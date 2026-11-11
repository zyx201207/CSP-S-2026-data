#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=true,b=true,x=false,y=false,ans=true;
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			a=false;
			ans=false;
		}
	}
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i]&&ans==true)
		{
			b=false;
			ans=false;
		}
	}
	if(((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C'))&&((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C'))&&ans==true)
	{
		x=true;
	}
	else if(((s1[2]=='D')||(s1[2]=='F'))&&((s1[2]=='D')||(s1[2]=='F')))
	{
		x=true;
	}
	else
	{
		ans=false;
	}
	if((s1[2]==s2[2]+1||s1[2]==s2[2]-1)&&ans==true)
	{
		y=true;
	}
	if(a==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(b==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(x==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(y==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
