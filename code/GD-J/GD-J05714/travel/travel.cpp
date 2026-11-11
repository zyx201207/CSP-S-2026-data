#include <bits/stdc++.h>
using namespace std;
bool a,b,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if (c1==c2)
	{
		cout<<1;
		a=true;
	}else
		cout<<0;
	if (s1[0]==s2[0]&&s1[1]==s2[1]&&a)
	{
		cout<<1;
		b=true;
	}
	else
		cout<<0;
	
	if (b)
	{
		if (s1[2]=='A')
		{
			if (s2[2]=='B'||s2[2]=='C')
			{
				cout<<1;
				c=true;
			}
			else
				cout<<0;
		}else if (s1[2]=='B')
		{
			if (s2[2]=='A'||s2[2]=='C')
			{
				cout<<1;
				c=true;
			}
			else
				cout<<0;
		}else if (s1[2]=='C')
		{
			if (s2[2]=='A'||s2[2]=='B')
			{
				cout<<1;
				c=true;
			}
			else
				cout<<0;
		}else if (s1[2]=='D')
		{
			if (s2[2]=='F')
			{
				cout<<1;
				c=true;
			}
			else
				cout<<0;
		}else if (s1[2]=='F')
		{
			if (s2[2]=='D')
			{
				cout<<1;
				c=true;
			}
			else
				cout<<0;
		}
	}else
		cout<<0; 
	
	
	if (c)
	{
		if (s1[2]=='D'||s1[2]=='F')
			cout<<1;
		else if (s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C')
			cout<<1;
		else
			cout<<0;
	}else
		cout<<0;
	return 0;
}

