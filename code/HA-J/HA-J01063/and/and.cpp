#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m<n)
	{
		sort(a+1,a+n+1);
		for(int i=n;i>=n-m+1;i--)
		{
			if(i==n)
			{
				ans=a[i];
			}
			else
			{
				ans=ans&a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				ans=a[i];
			}
			else
			{
				ans=ans&a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
