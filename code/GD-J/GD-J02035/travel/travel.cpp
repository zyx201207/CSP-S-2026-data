#include <iostream>
using namespace std; 

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int o,p;
	string k,l;
	cin>>o>>k>>p>>l;
	if (o!= p){
		cout<<"0000"<<endl;
		return 0;
	}
	char b = k[0];
	char n = l[0];
	if(b == n){
		char u = k[1];
		char j = l[1];
		if (u != j){
			cout<<"1000"<<endl;
		}else{
			char y=k[2];
			char t=l[2];
			if((y=='A'&&t=='B')||(y=='A'&&t=='C')||(y=='B'&&t=='A')||(y=='B'&&t=='C')||(y =='C'&&t =='A')||(y =='C'&&t =='B')||(y =='D'&&t =='F')||(y =='F'&&t =='D')){
				if(y=='D'||y=='F'){
					cout<<"1111"<<endl;
					return 0;
				}
				if(y =='A',t=='C'||y=='B',t=='A'||y=='B',t=='C'||y =='C',t =='B'){
					cout<<"1111"<<endl;
					return 0;
				}else{
					cout<<"1110"<<endl;
				}
			}else{
				cout<<"1100"<<endl;
			}
		}
	}
	return 0;
}
