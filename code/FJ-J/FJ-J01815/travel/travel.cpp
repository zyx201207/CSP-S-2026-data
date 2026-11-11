#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool flag=1;
	if(a==c)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
		flag=0;
	}
	
	if(b[0]==d[0]&&b[1]==d[1]&&flag==1) 
	{
		
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=0;
	}
	char x=b[2];
	char y=d[2];bool k=1;bool o=1;
	if(x=='A'||x=='B'||x=='C')
	{
		k=1;
	}
	else
	{
		k=0;
	}
	if(y=='A'||y=='B'||y=='C')
	{
		o=1;
	}
	else
	{
		o=0;
	}
	if(k==o&&flag==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=0;
	}
	
	
	
	
	if(abs(b[2]-d[2])==1&&flag==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
