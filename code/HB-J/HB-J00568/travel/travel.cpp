#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}e=b[0]+b[1];
	f=d[0]+d[1];
	if(e==f) cout<<1;
	else{
		cout<<"000";
		return 0;
	}e=b[2],f=d[2];
	if((e[0]<='C'&&f[0]<='C')||(e[0]>'C'&&f[0]>'C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if(e[0]+1==f[0]||f[0]+1==e[0]) cout<<1;
	else cout<<0;

	return 0;
}
