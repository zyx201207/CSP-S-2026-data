#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int c,e;
	string d,f;
    cin >> c >> d >> e >> f;
    if(c == e){
    	cout << 1;
		if(d[0]*10+d[1] == f[0]*10+f[1]){
			cout << 1;
			if((d[2] == 'A'||d[2] == 'B'||d[2] == 'C')&&(f[2] == 'A'||f[2] == 'B'||f[2] == 'C')||(d[2] == 'D'||d[2] == 'F')&&(f[2] == 'D'||f[2] == 'F')){
				cout << 1;
				if((d[2]=='A'&&f[2]=='C')||(d[2]=='C'&&f[2]=='A')){
					cout << 0;
				}else{
					cout << 1;
				}
			}else{
				cout << 0 << 0;
				
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
    return 0;
}

