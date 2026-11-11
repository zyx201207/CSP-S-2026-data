#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x=0,r=0;
	string x1,r1;
	cin>>x>>x1>>r>>r1;
	if(x==r)
	{
		a[1]=1;
	}
	else
	{
		a[1]=0;
	}
	
	if(x==r)
	{
		if(x1[0]==r1[0] && x1[1]==r1[1])
	{
		a[2]=1;
	}
	else
	{
		a[2]=0;
	}
	}
	
	if(x==r)
	{
		if(x1[0]==r1[0] && x1[1]==r1[1])
	{
		if(x1[2]=='A' || x1[2]=='B' || x1[2]=='C')
		{
			if(r1[2]=='A' || r1[2]=='B' || r1[2]=='C')
			{
				a[3]=1;
			}
		}
		else if(x1[2]=='D' || x1[2]=='F')
		{
			if(r1[2]=='D' || r1[2]=='F')
			{
				a[3]=1;
			}
		}
		else
		{
			a[3]=0;
		}
	}
	}
	
	
	if(a[3]==1)
	{
		if(x1[2]+r1[2]==131)
	{
		a[4]=1;
	}
	else if(x1[2]+r1[2]==133)
	{
		a[4]=1;
	}
	else if(x1[2]+r1[2]==138)
	{
		a[4]=1;
	}
	else
	{
		a[4]=0;
	}
	}
	else
	{
		a[4]=0;
	}
	
	
	for(int i=1;i<=4;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
} 
