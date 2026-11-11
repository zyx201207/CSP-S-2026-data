#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int a1=(a[0]-'0')*10+(a[1]-'0');
	int a2=(c[0]-'0')*10+(c[1]-'0');
	if(a1==a2)f++,cout<<1;
	else cout<<0;
	int b1=(b[0]-'0')*10+(b[1]-'0');
	int b2=(d[0]-'0')*10+(d[1]-'0');
	if(b1==b2&&f==1)f++,cout<<1;
	else cout<<0;
	if(b[2]=='C'&&d[2]=='D') cout<<0;
	else if((((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))||((b[2]>='D'&&b[2]<='F')&&(d[2]>='D'&&d[2]<='F')))&&f==2)f++,cout<<1;
	else cout<<0;
	if(abs(b[2]-d[2])==1&&f==3)cout<<1;
	else cout<<0;
	return 0;
} 

