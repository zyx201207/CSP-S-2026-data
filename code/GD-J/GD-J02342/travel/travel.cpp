#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	bool x=0;
	if(c1==s1) 
	{
		x=1;
		cout<<1;
	}
	else 
	{
		x=0;
		cout<<0;	
	}
	
	if(x && c2[0]==s2[0] && c2[1]==s2[1]) 
	{
		x=1;
		cout<<1;
	}
	else 
	{
		x=0;
		cout<<0;
	}
	if(x && ((c2[2]>='D' && s2[2]>='D') ||(c2[2]<='C' && s2[2]<='C')))
	{
		x=1;
		cout<<1;
	}
	else 
	{
		x=0;
		cout<<0;
	}
	if(x && abs(c2[2]-s2[2])==1)
	{
		x=1;
		cout<<1;
	}
	else 
	{
		x=0;
		cout<<0;
	}
	return 0;
 } 
