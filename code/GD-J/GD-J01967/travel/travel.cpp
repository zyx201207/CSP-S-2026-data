#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	x=b[0]+b[1];
	y=d[0]+d[1];
	if(x==y)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(b[2]<='C'&&d[2]<='C')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	char n=b[2];
	int n1=int(n)+1;
	n=char(n1);
	char m=d[2];
	int m1=int(m)+1;
	m=char(m1);
	if(b[2]==m||d[2]==n)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
} 
