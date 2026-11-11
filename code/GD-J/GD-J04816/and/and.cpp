#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}else
	{
		ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	
	return 0;
}			
