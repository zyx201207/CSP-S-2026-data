#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a , b , n , m;
	cin >> a >> n >> b >> m;
	if(a!=b){
		cout << "0000";
	}else{
		cout << 1;
		if(n[0]!=m[0]||n[1]!=m[1]){
			cout << "000";
		}else{
			cout << 1;
			if(n[2]>'C'&&m[2]>'C'){
				cout << 11;	
			}else{
				if(n[2]<'D'&&m[2]<'D'){
					cout << 1;
					if((n[2]=='A'&&m[2]=='C')||(n[2]=='C'&&m[2]=='A')){
						cout << 0;
					}else{
						cout << 1;
					}
				}else{
					cout << "00";
				}
			}
		}
	}
	return 0;
} 
