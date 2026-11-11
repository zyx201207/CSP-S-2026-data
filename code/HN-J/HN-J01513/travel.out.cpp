#include <iostream>
#include <string>;
using namespace std;
int main(){
	string R1,R2,X1,X2;
	cin >> R1 >> R2 >> X1 >> X2;
	if (R1==X1) {
	cout << 1;
		if(R2[0]==X2[0]&&R2[1]==X2[1]){
				cout << 1;
				if(R2[2]>='D'&&X2[2]>='D'){
					cout << 1<< 1;
				}
				else if(R2[2]<='C'&&X2[2]<='C'){
					cout << 1;
					if(R2[2]-1==X2[2]||R2[2]+1==X2[2]){
					cout << 1;						
					}else cout << 0;					
				}else cout << 0<<0;
		}else cout << 0<<0<<0;
	}else cout << 0;
	return 0;
}


