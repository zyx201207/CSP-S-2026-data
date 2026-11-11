#include<bits/stdc++.h>
using namespace std;

int a[200005];
char b[200005];
set<char> s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0; 
	}
	if(n==2)
	{
		if(b[1]==b[2])
		{
			cout<<0;
			return 0;
		}
		if(a[1]%2==0)
		{
			ans+=a[1]/2;
		}
		else
		{
			if(a[2]%2==0)
			{
				ans+=a[2]/2;
			}
		}
		cout<<ans;
		return 0;
    }
    if(n==3)
    {
    	if(b[1]==b[2] && b[2]==b[3])
    	{
    		cout<<0;
    		return 0;
		}
		else
		{
			if(b[1]==b[2] && b[2]!=b[3] || b[1]==b[3] && b[2]!=b[3] || b[3]==b[2] && b[1]!=b[3])
			{
				cout<<2;
				return 0;
			}
			else
			{
				if(a[1]%2==0 && a[2]%2==0 && a[3]%2==1)
				{
					cout<<2;
					return 0;
				}
			}
		}
	}
    int y=0;
    for(int i=1;i<=n;i++)
    {
    	if(b[i]==b[i+1])
    	{
    		y++;
		}
	}
	if(y==n)
	{
		cout<<0;
	}
	else
	{
		y=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==1)
			{
				y++;
			}
		}
		if(y!=n)
		{
			for(int i=1;i<=n;i++)
			{
				s.insert(b[i]);
			}
			if(s.size()==2)
			{
				cout<<2;
				return 0;
			}
		}
	}
	return 0;
} 
