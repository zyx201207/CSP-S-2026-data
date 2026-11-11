#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char s,t;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>s>>c>>d>>t;
	if(a==c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b==d)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s=='A')
	{
		if(t=='B')
		{
			cout<<"11";
		}
		else if(t=='C')
		{
			cout<<"10";
		}
		else
		{
			cout<<"00";
		}
		return 0;
	}
	if(s=='B')
	{
		if(t=='A'||t=='C')
		{
			cout<<"11";
		}
		else
		{
			cout<<"00";
		}
		return 0;
	}
	if(s=='C')
	{
		if(t=='B')
		{
			cout<<"11";
		}
		else if(t=='A')
		{
			cout<<"10";
		}
		else
		{
			cout<<"00";
		}
		return 0;
	}
	if(t=='F'||t=='D')
	{
		cout<<"11";
	}
	else
	{
		cout<<"00";
	}
	return 0;
}
