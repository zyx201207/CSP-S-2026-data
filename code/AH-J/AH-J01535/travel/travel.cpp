#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a==x)
		cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==y[0]&&b[1]==y[1])
		cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[2]>='A' && b[2]<='C' && y[2]>='A' && y[2]<='C')
		cout<<1;
	else if(b[2]>='D' && b[2]<='F' && y[2]>='D' && y[2]<='F')
	{
		cout<<1<<1;
		return 0;
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	
	if(b[2]=='C' && y[2]=='D')
		cout<<0;
	else if(b[2]=='D' && y[2]=='C')
		cout<<0;
	else if(abs(b[2]-y[2])==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
