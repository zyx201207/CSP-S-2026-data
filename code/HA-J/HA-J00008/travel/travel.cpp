#include <bits/stdc++.h>
using namespace std;
string co,so,ct,st;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>ct>>so>>st;
	if(co==so){
		cout<<"1";
		if(ct[0]==st[0]&&ct[1]==st[1]){
			cout<<"1";
			if(ct[2]>'C'&&st[2]>'C'){
				cout<<"11";
			}
			else if(ct[2]<='C'&&st[2]<='C'){
				cout<<"1";
				if(st[2]-1==ct[2]||ct[2]-1==st[2]){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}