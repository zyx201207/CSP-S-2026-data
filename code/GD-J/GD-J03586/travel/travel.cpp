#include<bits/stdc++.h>
using namespace std;
int flag=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1;
	string s2;
	string s3;
	string s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 1;
	}
	if(s2[0]==s4[0] and s2[1]==s4[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 1;
	}
	if(s2[2]=='D')
	{
		if(s4[2]=='F')
		{
			cout<<"11";
		}
		else cout<<"00";
	}
	if(s2[2]=='F')
	{
		if(s4[2]=='D')
		{
			cout<<"11";
		}
		else cout<<"00";
	}
	if(s2[2]=='A')
	{
		if(s4[2]=='B')
		{
			cout<<"11";
		}
		else if(s4[2]=='C')
		{
			cout<<"10";
		}
		else cout<<"00";
	}
	if(s2[2]=='C')
	{
		if(s4[2]=='B')
		{
			cout<<"11";
		}
		else if(s4[2]=='A')
		{
			cout<<"10";
		}
		else cout<<"00";
	}
	if(s2[2]=='B')
	{
		if(s4[2]=='A' or s4[2]=='C')
		{
			cout<<"11";
		}
		else cout<<"00";
	}
 } 
