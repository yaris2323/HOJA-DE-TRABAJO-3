/*Una empresa de parqueos lo contrata para realizar un programa en que se contabilicen el valor de 
los tickets que se cobren durante el día, según en el orden que se hayan cobrado.
Dichos los datos deberán de guardarse a un archivo de texto según de vaya cobrando. 
Así mismo deberá de mostrar un reporte en pantalla el monto cobrado durante el día, 
esto leyendo los datos grabados en el archivo.
Utilice ciclos y/o funciones para realizar
*/
 

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct ticket{
	string ticket;
	string dia;
	float precio;
};
void mp(); 
void reporte();
void leer_archivo();
int main(){	
	mp();	
}
void mp(){
	
	int resp;
	string nombrearchivo;
	cout<<"ticket: ";
	getline(cin,nombrearchivo);
	
	do{
		cout<<" 1 - ticket del reporte "<<"\n";
		cout<<" 2 - Mostrar todos los ticket en orden "<<"\n";
		cout<<" 3 - total de ticket durante el dia"<<"\n";
		
		cout<<" Seleccione su opción: ";
		cin>>resp;
		if (resp==1){		
			system("ticket");
			reporte();			
		}
		else if (resp==2){		
			system("orden");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
void reporte(){
	string ticket_v;
	int dia_v;
	float precio_v;
	ofstream archivo; 
	fflush(stdin);
	cout<<"Ingrese ticket: "<<endl;
	getline(cin,ticket_v);
	cout<<"Ingrese dia: "<<endl;
	cin>>dia_v;	
	cout<<"Ingrese Precio: "<<endl;
	cin>>precio_v;
	
	archivo.open("tickets.txt",ios::app); 
	archivo<<ticket_v<<"\t"<<dia_v<<"\t"<<precio_v<<endl;
	archivo.close();	
}
void leer_archivo(){
	ifstream archivo;
	archivo.open("tickets.txt",ios::in);
	int lineas,i=0;
	string s,linea;	
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	ticket recordset[lineas];
	
	archivo.open("tickets.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].ticket>>recordset[i].dia>>recordset[i].precio;
    }
    archivo.close(); 
    for(int i = 0; i <lineas; i++){
    	cout<<recordset[i].ticket<<" "<<recordset[i].dia<<" "<<recordset[i].precio<<endl;

	}
	system("Pause");
	

}
 

