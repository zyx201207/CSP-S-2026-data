#include<bits/stdc++.h>
using namespace std;
int pai(string x,string y)
{
	if(x[0]==y[0]&&x[1]==y[1])
	{
		return true;
	}
	else
	{
		return false;
	}
}
int ce(string x,string y)

{
	if(x[2]>='A'&&y[2]>='A'&&x[2]<='C'&&y[2]<='C')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int guodao(string x,string y)
{
	if(pai(x,y)&&ce(x,y))
	{
		if(x[2]=='C'&&y[2]>'C'||x[2]=='D'&&y[2]<'D')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int xiangling(string x,string y)
{	
	if((x[2]-y[2]==1||y[2]-x[2]==1)&&!(guodao(x,y)))
	{
		return true;
	}
	else
	{
		return false;
	}
		
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,a,b;
	cin>>x>>a>>y>>b;
	if(x==y)
	{
		cout<<1;
	}
	else
	{
		for(int i=1;i<=4;i++)
		{
			cout<<0;
		}
		return 0;
	}
	if(pai(a,b))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(pai(a,b)&&ce(a,b))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(xiangling(a,b)&&ce(a,b)&&pai(a,b))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
