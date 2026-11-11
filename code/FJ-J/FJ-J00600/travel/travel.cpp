#include<bits/stdc++.h>
using namespace std;
string c,s,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>a>>b;
	if(c==a)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	long long x,y;
	x=(s[0]-'0')*10+(s[1]-'0');
	y=(b[0]-'0')*10+(b[1]-'0');
	if(x==y)
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char g,h;
	g=s[2],h=b[2];
	if((g<='C'&&h<='C')||(g>='D'&&h>='D'))
		cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(g-1==h||h-1==g)
		cout<<1;
	else
		cout<<0;
	return 0;
}
