#include<bits/stdc++.h>
using namespace std;
int a,c,f;
string d,b,x,xx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	x=d.substr(0,2);
	xx=b.substr(0,2);
	if(x==xx)f=1;
	if(a==c&&f)cout<<1;
	else cout<<0;
	if(a==c&&f&&((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='C'&&d[2]=='A')))
	cout<<1;
	else cout<<0;
	if(a==c&&f&&((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')))
	cout<<1;
	else cout<<0;
	return 0;
 } 
