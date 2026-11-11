#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int md=1e6;
int dd;
int maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{int t=0;
		for(int j=1;j<=n;j++)
		{
			t = t+abs(a[i]-a[j]);
		}
		int g=md;
		md = min(t,md);
		if(md!=g)dd = a[i];
		else if(md==t&&dd<a[i])dd = a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(dd==a[i])maxn++;
	}
	for(int i=1;i<=n;i++)
	{int t=1e6;
		if(dd==a[i])continue;
			if(m>=0&&a[i]<dd)
			{
				for(int j=1;j<=n;j++)
				{
					t = min(a[i],a[j]);
				}
				if(m-dd+t>=0)
				{
					m = m-dd+t;
					maxn++;
				}
			}
			
	}
	cout<<maxn;
	return 0;
}
