#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int cnt=0,sum=0,ans=0;
	cin>>a>>b>>c>>d;
	if(a.size()==c.size())
	{
		for(int i=0;i<a.size();i++)
		{
			if(a[i]!=c[i])
			{
				cout<<0;
				cnt++;
				break;
			}
		}
	}
	else 
	{
		cout<<0;
	}
	if(cnt==0)
	{
		cout<<1;
	}
	if(b[2]!=d[2])
	{
		if(b[0]==d[0])
		{
			if(b[1]==d[1])
			{
				cout<<1;
				sum=1;
			}
		}
		else
		{
			cout<<0;
		}
	}	
	else
	{
		cout<<0;
	}
	if(b[2]=='C'&&d[2]=='D')
	{
		cout<<0;
	}
	if(b[2]=='D'&&d[2]=='C')
	{
		cout<<0;
	}
	else if((b[2]==d[2]-1)||(b[2]==d[2]+1))	
	{
		if(sum==1)
		{
			cout<<1;
			ans=1;	
		}	
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	if(cnt==0&&sum==1&&ans==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
