#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);	
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		int k=(1LL<<21)-1,ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				} 
				k&=a[j];
			}
			ans=max(ans,k);
		}
		cout<<ans;
		return 0;
	}
	return 0;
 } 
