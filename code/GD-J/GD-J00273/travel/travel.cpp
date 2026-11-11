#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	if(a[0]==d[0]&&a[1]==d[1])
	{
		cout<<1;
	}
	if(a[0]!=d[0]||a[1]!=d[1])
	{
		cout<<"0000";
		return 0;
	}
	if(s[0]==f[0]&&s[1]==f[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s[2]=='A' && f[2]=='B')
	{
		cout<<1;
	}
	else if(s[2]=='A' && f[2]=='C')
	{
		cout<<1;
	}
	else if(s[2]=='B' && f[2]=='A')
	{
		cout<<1;
	}
	else if(s[2]=='B' && f[2]=='C')
	{
		cout<<1;
	}
	else if(s[2]=='C' && f[2]=='A')
	{
		cout<<1;
	}
	else if(s[2]=='C' && f[2]=='B')
	{
		cout<<1;
	}
	else if(s[2]=='D' && f[2]=='F')
	{
		cout<<1;
	}
	else if(s[2]=='F' && f[2]=='D')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s[0]==f[0]&&s[1]==f[1])
	{
		if(s[2]=='A' && f[2]=='B')
		{
			cout<<1;
			
		}
		else if(s[2]=='B' && f[2]=='A')
		{
			cout<<1;
		}
		else if(s[2]=='B' && f[2]=='C')
		{
			cout<<1;
		}
		
		else if(s[2]=='C' && f[2]=='B')
		{
			cout<<1;
		}
		else if(s[2]=='D' && f[2]=='F')
		{
			cout<<1;
		}
		else if(s[2]=='F' && f[2]=='D')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
}
