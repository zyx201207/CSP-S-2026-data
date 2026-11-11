#include <bits/stdc++.h>
using namespace std;
string a1,a2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>s1>>s2;
    if(a1==s1) cout<<1;
    else
    {
		cout<<"0000";
		return 0;
	}
    if(a2[0]==s2[0]&&a2[1]==s2[1]) cout<<'1';
    else
    {
		cout<<"000";
		return 0;
	}
	if(a2[2]=='D')
	{
		if(s2[2]=='F')
		{
			cout<<'1';
		}
		else
		{
			cout<<"00";
		    return 0;
		}
	}
	if(a2[2]=='F')
	{
		if(s2[2]=='D')
		{
			cout<<'1';
		}
		else
		{
			cout<<"00";
		    return 0;
		}
	}
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')
	{
		if(s2[2]!='D'&&s2[2]!='F')
		{
			cout<<'1';
		}
		else
		{
			cout<<"00";
		    return 0;
		}
	}
	if(a2[2]=='A')
	{
		if(s2[2]=='B')
		cout<<'1';
		else
		cout<<'0';
	}
	if(a2[2]=='B')
	{
		if(s2[2]=='A'||s2[2]=='C')
		cout<<'1';
		else
		cout<<'0';
	}
	if(a2[2]=='C')
	{
		if(s2[2]=='B')
		cout<<'1';
		else
		cout<<'0';
	}
	if(a2[2]=='D')
	{
		if(s2[2]=='F')
		cout<<'1';
		else
		cout<<'0';
	}
	if(a2[2]=='F')
	{
		if(s2[2]=='D')
		cout<<'1';
		else
		cout<<'0';
	}
    return 0;
}
