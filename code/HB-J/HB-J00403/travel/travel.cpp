#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<'\n';
		return 0;
	}
	cout<<1;
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000"<<'\n';
		return 0;
	}
	cout<<1;
	int szb=b[2]-'A',szd=d[2]-'A';
	if((szb>2&&szd<3)||(szb<3&&szd>2)){
		cout<<"00"<<'\n';
		return 0;
	}
	cout<<1;
	if(abs(szd-szb)!=1){
		cout<<0<<'\n';
		return 0;
	}
	cout<<1;
	return 0;
}
