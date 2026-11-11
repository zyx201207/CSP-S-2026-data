#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int n=0,m=0;
	string e[3]={"A","B","C"},f[3]={"D","F","0"}
	
	if(b[0]==d[0])
	{
		if(b[1]==d[1])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	
	string e[3]={"A","B","C"},f[3]={"D","F","0"}
	for(int k=0;k<=2;k++)
	{
		if((b[2]==e[k])&&(d[2]==e[k]))
	{
		m++;
	}
	if((b[2]==f[k])&&(d[2]==f[2]))
	{
		n++;
	}
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	
	}
	if((m==2)||(n==2))
	{
		cout<<1;
		if((b[2]=='D')&&(d[2]=='F'))
		{
			cout<<1;
		}
		else if(b[2]+1==d[2]&&b[2]-1==d[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
		cout<<0;
	}
	return 0;
}