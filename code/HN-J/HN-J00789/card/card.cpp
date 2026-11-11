#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		for(int i=1;i<=m;i++)
		{
			if(i==a[1])
			{
				cout<<1<<' ';
			}
			else
			{
				cout<<0<<' ';
			}
		}
	}
	if(n==2)
	{
		if(a[1]==a[2])
		{
			for(int i=1;i<=m;i++)
		    {
			    if(i==a[1])
			    {
				    cout<<1<<' ';
			    }
			    else
			    {
				    cout<<0<<' ';
			    }
		    }
		}
		else
		{
			for(int i=1;i<=m;i++)
		    {
			     if(i==a[1] || i==a[2])
			     {
				     cout<<2<<' ';
			     }
			     else
			     {
				     cout<<0<<' ';
			     }
		    }
		}
	}
	return 0; 
}
