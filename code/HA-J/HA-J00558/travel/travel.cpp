#include<bits/stdc++.h>
using namespace std;
int a,b;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b)
	{
		cout<<"1";		
	}
	else if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		if(s1[i+1]==s2[i+1])
		{
			cout<<"1";
			break;
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	
	for(int i=0;i<3;i++)
	{
		if(s1[i+2]=='A'||s1[i+2]=='B'||s1[i+2]=='C')
		{
			if(s2[i+2]=='A'||s2[i+2]=='B'||s2[i+2]=='C')
			{
				cout<<"1";
				break;
			}
		 } 
		if(s1[i+2]=='D'||s1[i+2]=='F')
		{
			if(s2[i+2]=='D'||s2[i+2]=='F')
			{
				cout<<"1";
				break;
			}
		 } 
		 else
		 {
		 	cout<<"00";
		 	return 0;
		 }
	}
	for(int i=0;i<3;i++)
	{
		if(s1[i+2]=='A'&&s2[i+2]=='B'||s1[i+2]=='B'&&s2[i+2]=='A'||s1[i+2]=='B'&&s2[i+2]=='C'||s1[i+2]=='C'&&s2[i+2]=='B'||s1[i+2]=='D'&&s2[i+2]=='E'||s1[i+2]=='E'&&s2[i+2]=='D')
		{
			cout<<"1";return 0;
		}
		else
		{
			cout<<"0";return 0;
		}
	}
	return 0;
 } 
