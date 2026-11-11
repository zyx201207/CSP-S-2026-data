#include<bits/stdc++.h>
#define int long long
using namespace std;
string ida,ina,idb,inb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ida>>ina>>idb>>inb;
	if(ida==idb){
		cout<<"1";
		if(ina[0]==inb[0] && ina[1]==inb[1]){
			cout<<"1";
			if((ina[2]<='C' && inb[2]<='C') || (ina[2]>'C' && inb[2]>'C')){
				cout<<"1";
				if(abs((int)ina[2]-inb[2])==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
