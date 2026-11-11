#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
string z,z1,c,c1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> z >> c >> z1 >> c1;
	if(z==z1){
		cout << 1;
		if(c[0]==c1[0]){
			cout << 1;
			if(c[1]==c1[1]){
				cout << 1;
				if(c[2]=='a'&&c1[2]=='b'||c[2]=='b'&&c1[2]=='c'||c[2]=='c'&&c1[2]=='b'||c[2]=='b'&&c1[2]=='a'){
					cout << 1;
				}else if(c[2]>'C'&&c1[2]>'C'){
					cout << 1;
				}else{
					cout << 0;
				} 
			}else{
				cout << 0;
			}
		}else{
			cout << 0;
		}
	}else {
		cout << 0;
	}
	return 0;
}
