#include <bits/stdc++.h>
using namespace std;
string rx,rz,xx,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>rz>>xx>>xz;
	if(rx!=xx){
		cout<<"0000";
		return 0;
	}
	else {
		cout<<1;
		string paiR=to_string(rz[0]*10+rz[1]);
		string paiX=to_string(xz[0]*10+xz[1]);
		if(paiR!=paiX){
			cout<<"000";
		}
		else{
			cout<<"1";
			bool rleft = (rz[2]>='A'&&rz[2]<='C');//为真在左，为假在右
			bool xleft =(xz[2]>='A'&&xz[2]<='C');
			if(rleft!=xleft){
				cout<<"00";
			}
			else{
				cout<<1;
				if(abs(rz[2]-xz[2])==1){
					cout<<1;
				}
				else cout<<0;
			}
		}
	}
	return 0;
}