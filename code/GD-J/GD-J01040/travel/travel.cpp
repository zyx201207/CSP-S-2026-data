#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
string x,y;
bool f;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b) cout<<1;
	else cout<<0;
	string tx=x.substr(0,2),ty=y.substr(0,2);
	if(tx==ty&&a==b) f=true,cout<<1;
	else cout<<0;
	if(f&&x[2]<='C'&&y[2]<='C' || x[2]>'C'&&y[2]>'C') cout<<1;
	else cout<<0;
	if(f&&abs(x[2]-y[2])==1&&(x[2]!='C'&&y[2]!='D'&&x[2]!='D'&&y[2]!='C')) cout<<1;
	else cout<<0;
	return 0;
} 
