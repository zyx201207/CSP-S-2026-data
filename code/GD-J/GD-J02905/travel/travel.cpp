#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int c1,c2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	c1=(a[0]-'0')*10+a[1]-'0';
	c2=(c[0]-'0')*10+c[1]-'0';
	z1=(b[0]-'0')*10+b[1]-'0';
	z2=(d[0]-'0')*10+d[1]-'0';
	if(c1==c2) cout<<1;
	else {
		cout<<"0000";
		return 0; 
	}
	if(z1==z2) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1) cout<<1;
	else cout<<"0";
	return 0;
} 
