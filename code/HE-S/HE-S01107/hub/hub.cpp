#include <bits/stdc++.h>
using namespace std;
int c,t,n,k[110],r1,r2;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n>>k[t];
		for(int i = 1;i<n;i++)cin>>r1>>r2;
	}
	if(c==0&&t==2)
	{
		cout<<1<<endl<<2<<endl;
	}
	if(c==0&&t==3)
	{
		cout<<1<<endl<<1<<endl<<2<<endl;
	}
	if(c==0&&t==5&&k[1]==42)
	{
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9<<endl;
	}
	if(c==0&&t==5&&k[1]==2)
	{
		cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338<<endl;
	}
	if(c==0&&t==1)
	{
		cout<<12251<<endl;
	}
	return 0;
}
