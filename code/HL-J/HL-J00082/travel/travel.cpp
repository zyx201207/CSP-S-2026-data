#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travei.out","w",stdout);
	long long a,b,c,d;
	char n,m;
	cin>>a>>b>>n>>c>>d>>m;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	if(a==c&&b==d)
	{
		cout<<"11";
	}
	else if(a==c&&b!=d)
	{
		cout<<"1000";
		return 0;
	}
	else if(a!=c&&b==d)
	{
		cout<<"01";
	}
		else if(a!=c&&b!=d)
	{
		cout<<"00";
	}
	if(n+1==m||n-1==m)
	{
		if(n=='C'&&m=='D')
		{
			cout<<"00";
		}
		else
		{
			cout<<"11";
		}
	}
	if(n+1!=m&&n-1!=m)
	{
		if(n=='C'&&m=='D')
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
		cout<<0;
	}
	return 0;
}
