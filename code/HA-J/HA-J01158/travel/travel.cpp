#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	b=b[0]+b[1]+b[2];
	d=d[0]+d[1]+d[2];
	if (a==c)
	cout<<1;
	if (a!=c)
	cout<<0<<0<<0<<0;
	if (b[1]==d[1])
	cout<<1;
	if (b[1]!=d[1])
	cout<<0;
	if(b[2]=='C' and d[2]=='D')
	cout<<0<<0;
    if(b[2]=='A' and d[2]=='B')
	cout<<1<<1;
	if(b[2]=='B' and d[2]=='C')
	cout<<1<<1;
	if(b[2]=='C' and d[2]=='D')
	cout<<0<<0;
	if(b[2]=='D' and d[2]=='F')
	cout<<1<<1;
	if(b[2]=='A' and d[2]=='C')
	cout<<1<<0;
	if(b[2]=='A' and d[2]=='D')
	cout<<0<<0;
	if(b[2]=='A' and d[2]=='F')
	cout<<0<<0;
	if(b[2]=='B' and d[2]=='D')
	cout<<0<<0;
	if(b[2]=='B' and d[2]=='F')
	cout<<0<<0;
	if(b[2]=='D' and d[2]=='C')
	cout<<0<<0;
    if(b[2]=='B' and d[2]=='A')
	cout<<1<<1;
	if(b[2]=='C' and d[2]=='B')
	cout<<1<<1;
	if(b[2]=='D' and d[2]=='C')
	cout<<0<<0;
	if(b[2]=='F' and d[2]=='D')
	cout<<1<<1;
	if(b[2]=='C' and d[2]=='A')
	cout<<1<<0;
	if(b[2]=='D' and d[2]=='A')
	cout<<0<<0;
	if(b[2]=='F' and d[2]=='A')
	cout<<0<<0;
	if(b[2]=='D' and d[2]=='B')
	cout<<0<<0;
	if(b[2]=='F' and d[2]=='B')
	cout<<0<<0;
 	return 0;
}
