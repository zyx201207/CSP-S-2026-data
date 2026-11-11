#include <bits/stdc++.h>
using namespace std;

char n[105],m[105];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	cin>>x>>n>>y>>m;
	if(x != y){
		cout<<"0000";
		return 0; 
	}
	else {
		cout<<"1";
		if(n[0] != m[0] or n[1] != m[1]){
			cout<<"000";
			return 0;
		}
		else if(n[0] == m[0] and n[1] == m[1]){
			cout<<"1";
			if((n[2]<='C'&&m[2]<='C')||(n[2]>'C'&&m[2]>'C')){
				cout<<"1";
				if(abs(m[2]-n[2]) == 1){
					cout<<"1";
					return 0;
				}
				else {
					cout<<"0";
					return 0;
				}
			}
			else {
				cout<<"00";
				return 0;
			}
		}
	}
	return 0;
} 
