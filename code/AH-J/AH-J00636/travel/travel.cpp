#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[4]={},s2[4]={};
	cin>>c1>>c2;
	for(int i=0;i<=3;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s2[2]=='D'||s2[2]=='F')
	{
		if(s1[2]=='D'||s2[2]=='F')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	    {
		    cout<<1;
	    }
	    else
	    {
	    	cout<<0;
		}
	}
	if(s1[0]==s2[0])
	{
	    if(s1[1]==s2[1])
		{
		    if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
			{
			    cout<<1;	
		    }
			else
			{
				cout<<0;
			}	
	    }	
	}
    return ;
}
