#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y,z,v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x+=int(a[0]*10+a[1]);
	y+=int(c[0]*10+c[1]);
	z+=int(b[0]*10+b[1]);
	v+=int(d[0]*10+d[1]);
	if(x==y) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(x==y&&z==v) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='B') cout<<11;
	else if(b[2]=='A'&&d[2]=='C') cout<<10;
	else if(b[2]=='B'&&d[2]=='A') cout<<11;
	else if(b[2]=='B'&&d[2]=='C') cout<<11;
	else if(b[2]=='C'&&d[2]=='B') cout<<11;
	else if(b[2]=='C'&&d[2]=='A') cout<<10;
	else if(b[2]=='D'&&d[2]=='F') cout<<11;
	else if(b[2]=='D'&&d[2]=='F') cout<<11;
	else cout<<0<<0;
	return 0;
} 
