//GZ-J00377 陈阳锦
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) {
		cout<<1;
		int ha=b[0]*10+b[1],hb=d[0]*10+d[1];
		if(ha==hb){
			cout<<1;
			int hc=b[2]-'A',hd=d[2]-'A';
			if((hc<=2&&hd<=2)||(hc>=3&&hd>=3)) {
				cout<<1;
				if((hc<=2&&hd<=2)){
                    if(abs(hc-hd)==1)cout<<1;
                    else cout<<0;
				}
				else if((hc>=3&&hd>=3)) cout<<1;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";

	return 0;
}
