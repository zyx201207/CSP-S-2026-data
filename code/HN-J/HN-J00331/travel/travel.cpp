#include<bits/stdc++.h>
using namespace std;
int a,c,e,f;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	e=b[0]-'0';
	e*=10;
	e+=b[1]-'0';
	f=d[0]-'0';
	f*=10;
	f+=d[1]-'0';
//	cout<<e<<f; 
	cout<<(a==c);
	if(a!=c){
		cout<<"000";
		return 0;
	}
	cout<<(e==f);
	bool flag=0;
	cout<<((flag=(!((b[2]<='C')^(d[2]<='C'))))&&e==f);
	if(flag){
		if(abs(b[2]-d[2])+abs(e-f)==1){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
} 
