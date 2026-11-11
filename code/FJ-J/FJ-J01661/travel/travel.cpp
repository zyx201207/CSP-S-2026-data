#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool p=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<=1;i++)
	{
		
		if(s2[i]!=s4[i])
		{
			p=false;
		}
	}
	if(p==false)
	{
		cout<<0<<0<<0;
		return 0;
	}
	else
	{
		cout<<1;
	}
	p=false;
	if(s2[2]=='A'&&(s4[2]=='B'||s4[2]=='C'))
	{
		p=true;
	}
	if(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C'))
	{
		p=true;
		}	
	if(s2[2]=='C'&&(s4[2]=='A'||s4[2]=='B'))
	{
		p=true;
		}	
	if(s2[2]=='D'&&s4[2]=='F')
	{
		p=true;
		}	 
	if(s2[2]=='F'&&s4[2]=='D')
	{
		p=true;
		}	
	if(p==true)
	{
		cout<<1;
		if(max(s2[2]-s4[2],s4[2]-s2[2])==1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	else 
	{
		cout<<0<<0;
		return 0;
	}
	return 0;
 } 
