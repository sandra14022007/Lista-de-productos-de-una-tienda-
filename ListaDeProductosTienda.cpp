//bibliotecas que nos permiten usar cin,cout y vectores dinámicos 
#include <iostream>   
#include <vector> 
//disminuye el trabajo de escribir std cada rato     
using namespace std;  

// Definición de la clase Producto, la usaremos en la clase tienda quien almacenara un vector de productos 
class Producto{
	
	private:  
	// atributos considerados 
	string nombre;  
	int codigo;    
	float precio;  
	int stock;      
	public: 	
	// Método para registrar los datos de un producto, sera usada desde Tienda 
	void registrar(){	
		cout<<"Codigo del producto: "; // Solicita al usuario el código del producto
        cin>>codigo;                 // Guarda el valor ingresado en la variable codigo
		//se repite lo mismo con los otros atributos 
        cout<<"Nombre del producto: "; 
        cin>>nombre;                   

        cout<<"Precio: ";              
        cin>>precio;                   

        cout<<"Cantidad en stock: ";  
        cin>>stock;                    
	}
	
	// Método que muestra la información del producto
    void mostrar(){
        cout<<"Codigo: "<<codigo<<endl;  
        cout<<"Nombre: "<<nombre<<endl;  
        cout<<"Precio: "<<precio<<endl;  
        cout<<"Stock: "<<stock<<endl;    
	}

	// Método para modificar los datos de un producto existente.
    void modificar(){
        cout<<"Nuevo nombre: "; // Solicita un nuevo nombre
        cin>>nombre;            // Actualiza el nombre del producto

        cout<<"Nuevo precio: "; // Solicita un nuevo precio
        cin>>precio;            // Actualiza el precio

        cout<<"Nuevo stock: ";  // Solicita nueva cantidad
        cin>>stock;             // Actualiza el stock
		
		// Este método es llamado después de que la clase Tienda
		// encuentra el producto dentro del vector mediante su código.
	}

	// Métodos getters que devuelven el código, precio y stock del producto.
    int getCodigo(){
        return codigo;  
	}

    float getPrecio(){
        return precio;  
	}

    int getStock(){
        return stock;  
	}
};

// Definición de la clase Tienda.
// Esta clase representa el sistema que administra todos los productos.
class Tienda{

	public: 
	string nombre;  
	vector<Producto> productos;
	// Vector que almacena objetos de tipo Producto.
	// El vector permite agregar o eliminar productos dinámicamente.

	// Método que permite registrar un nuevo producto en el sistema.
	void registrarProducto(){

    Producto p;
    // Se crea un objeto temporal de tipo Producto.
    // Este objeto almacenará los datos ingresados por el usuario

    cout << "Ingrese los datos del producto\n";
    p.registrar();
    // Se llama al método registrar() de la clase Producto.
    for(int i = 0; i < productos.size(); i++){
    // Se recorre el vector de productos 
    // productos.size() devuelve la cantidad de productos almacenados.
        if(productos[i].getCodigo() == p.getCodigo()){
        // Se compara el código del producto almacenado con el ingresado 
            cout << "Error: el codigo ya existe\n";
            // Si los códigos son iguales, significa que ya existe un producto con ese código 
            return;
        }}

    productos.push_back(p);
    // Si el código no se repite, el producto se agrega al vector.
    // push_back() inserta el nuevo objeto al final del vector.
    cout << "Producto registrado correctamente\n";
}
	
    // Método que muestra todos los productos almacenados en el vector.
    void mostrarProductos(){

    if(productos.size() == 0){
        // Si el vector está vacío, no hay productos para mostrar.
        cout << "No hay productos registrados\n";
        return;
    }

    cout << "\nLISTA DE PRODUCTOS\n";
    for(int i = 0; i < productos.size(); i++){
        // Ciclo que recorre el vector desde la posición 0
        productos[i].mostrar();
        // Accede al producto almacenado en la posición i y llama al método mostrar() de la clase Producto.
        cout << "------------------\n";
    }}
    	
    // Método que permite buscar un producto usando su código.
    void buscarProducto(){

    	int codigo;
    	// Variable donde se almacenará el código ingresado por el usuario.
        bool encontrado = false;
        // Variable booleana que indica si el producto fue encontrado.
        cout << "Ingrese el codigo del producto: ";
        cin >> codigo;
        // El usuario ingresa el código que desea buscar.
        for(int i = 0; i < productos.size(); i++){
        // Recorremos el vector 
            if(productos[i].getCodigo() == codigo){
            // Se compara el código ingresado con el código del producto actual.
                cout << "Producto encontrado\n";
                productos[i].mostrar();
                // Si se encuentra coincidencia se muestra el producto.
                encontrado = true;
                break;
            }        }

        if(!encontrado){
        // Si la variable sigue siendo false significa que no se encontró el producto.
            cout << "Producto no encontrado\n";
        }}
	
    // Método que permite modificar los datos de un producto existente.
    void modificarProducto(){
    	int codigo;
        bool encontrado = false;

        cout << "Ingrese el codigo del producto a modificar: ";
        cin >> codigo;

        for(int i = 0; i < productos.size(); i++){
        // Se recorre el vector buscando el producto.
            if(productos[i].getCodigo() == codigo){
                cout << "Ingrese los nuevos datos\n";
                productos[i].modificar();
                // Se llama al método modificar() del producto encontrado.
                cout << "Producto modificado correctamente\n";
                encontrado = true;
                break;
            }}

        if(!encontrado){
            cout << "Producto no encontrado\n";
        }
	}
	
    // Método que permite eliminar un producto del vector.
    void eliminarProducto(){
    	//mismo proceso para encontrar el producto por el código 
    	int codigo;
        bool encontrado = false;
        cout << "Ingrese el codigo del producto a eliminar: ";
        cin >> codigo;
        for(int i = 0; i < productos.size(); i++){
            if(productos[i].getCodigo() == codigo){
                productos.erase(productos.begin() + i);
                // erase elimina el elemento del vector.
                // productos.begin() apunta al inicio del vector y se suma i para eliminar la posición específica.
                cout << "Producto eliminado correctamente\n";
                encontrado = true;
                break;
            }}
        if(!encontrado){
            cout << "Producto no encontrado\n";
        }}
	
    // Método que genera un reporte general del inventario.
    void reporte(){
    	if(productos.size() == 0){
        // Se verifica si el vector está vacío.
        cout << "No hay productos registrados\n";
        return;
    	}

    float totalInventario = 0;
    // Variable que almacenará el valor total del inventario.
    cout << "\nREPORTE DE INVENTARIO\n";
    for(int i = 0; i < productos.size(); i++){
    // Se recorre todo el vector.
        productos[i].mostrar();
        // Se muestra cada producto.
        totalInventario += productos[i].getPrecio() * productos[i].getStock();
        // Se calcula el valor del inventario multiplicando
        // precio por cantidad disponible y acumulándolo en la variable total.
        cout << "-------------------\n";
    }
    cout << "Total de productos: " << productos.size() << endl;
    // Muestra la cantidad total de productos almacenados.
    cout << "Valor total del inventario: " << totalInventario << endl;
    // Muestra el valor total del inventario.
	}
};


int main(){

    Tienda tienda;

    int opcion;

    do{

        cout << "\n====== SISTEMA DE TIENDA ======\n";
        cout << "1. Registrar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto\n";
        cout << "4. Modificar producto\n";
        cout << "5. Eliminar producto\n";
        cout << "6. Generar reporte\n";
        cout << "7. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){

            case 1:
                tienda.registrarProducto();
                break;

            case 2:
                tienda.mostrarProductos();
                break;

            case 3:
                tienda.buscarProducto();
                break;

            case 4:
                tienda.modificarProducto();
                break;

            case 5:
                tienda.eliminarProducto();
                break;

            case 6:
                tienda.reporte();
                break;

            case 7:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    }while(opcion != 7);

    return 0;
}
