#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string ans="";
	string p="ABC DF";
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+='1';
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	int f,g=0;
	for(int i=0;i<p.size();i++)
	{
		if(p[i]==s1[2])
		{
			f=i;
		}
	}
	for(int i=0;i<p.size();i++)
	{
		if(p[i]==s2[2])
		{
			g=i;
		}
	}
	
		if(s1[1]==s2[1]&&s1[0]==s2[0])
		{
			ans+='1';
		}
		
		else
		{
			ans+='0';
		
		}
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
	{
		ans+='1';
		
	}
	else
	{
		ans+='0'; 
	}
	
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&abs(g-f)==1)
	{
		ans+='1';
	}
	else
	{
		ans+='0';
	}
	
	cout<<ans;
	
	
	return 0;
} 
