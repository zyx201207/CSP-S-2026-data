#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long g,h;
long long e[10];
char f[10]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>g>>a>>h>>b;
	int i=0;
	if(a[0]==0){
		e[1]=a[1]-'0';
		f[1]=a[2];
	}else{
		e[1]=a[0]-'0';
		e[1]=e[1]*10+a[1];
		f[1]=a[2];
	}
	i=0;
	if(b[0]==0){
		e[2]=b[1]-'0';
		f[2]=b[2];
	}else{
		e[2]=b[0]-'0';
		e[2]=e[2]*10+b[1];
		f[2]=b[2];
	}if(g==h)cout<<1;
	else cout<<0;
	if(g==h&&e[1]==e[2])cout<<1;
	else cout<<0;
	if(g==h&&e[1]==e[2]&&((f[1]<='C'&&f[2]<='C')||(f[1]>='D'&&f[2]>='D')))cout<<1;
	else cout<<0;
	if(g==h&&e[1]==e[2]&&((f[1]<='C'&&f[2]<='C')||(f[1]>='D'&&f[2]>='D'))&&abs(f[1]-f[2])==1)cout<<1;
	else cout<<0;
	//cout<<endl<<e[1]<<','<<f[1]<<endl<<e[2]<<','<<f[2];
	return 0; 
}
