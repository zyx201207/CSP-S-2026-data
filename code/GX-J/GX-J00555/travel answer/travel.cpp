#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel1.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	cin>>s;
	bool n;

	if(s[1]-=s[6]==0)
	{	n=1;
		cout<<n;
	}
	else {n=0;
		cout<<n;}
	if(s[3]-=s[8]==0)
	{	
		n=1;
		cout<<n;
	}	
	else {n=0;cout<<n;}
	if(s[4]-=s[9]==31)
	{	
		n=1;
		cout<<n;
	}
	else {n=0;cout<<n;}
	if(s[4]-=s[9]>=30)
	{	
		if(s[4]=='C'&&s[9]=='D')
		{n=0;
		cout<<n;}
		else
		{n=1;
		cout<<n;}
	}
	else if(s[1]-=s[6]!=0)
	{
		n=0;
		for(int i=1;i<=4;i++)
		{
			
			cout<<n;
			return 0;
		}
	}
	return 0;
}
