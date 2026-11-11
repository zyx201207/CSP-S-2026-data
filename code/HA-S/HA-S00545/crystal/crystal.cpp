#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],sum[500005],z[500005],m,ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*for (int i=1; i<=n; i++)
	{
		a[i]=a[i]-a[1];
	}*/
	for (int i=1; i<=n; i++)
	{
		sum[i]=sum[i-1]+a[i];
		z[i]=a[i]*(i-1)-sum[i-1];
	}
	for (int i=2; i<=n; i++)
	{
		int l=1,r=i,mid;
		while (l<=r)
		{
			mid=(l+r)/2;
			if (z[i]-(mid-1)*a[i]+sum[mid-1]<=m)
			{
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9
*/
