#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,e,f;
	char c,d;
	cin>>a>>b>>c>>e>>f>>d;
	if(a==e)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b==f)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(c=='A'||c=='B'||c=='C')
	{
		if(d=='A'||d=='B'||d=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(c=='D'||c=='F')
	{
		if(d=='D'||d=='F')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(c=='A'||c=='C')
	{
		if(d=='B')
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(d=='A'||d=='C')
	{
		if(c=='B')
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
 } 
