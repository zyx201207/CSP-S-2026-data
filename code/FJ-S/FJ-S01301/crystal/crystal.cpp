#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],sum[N];
int n,m;
int ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	
	for (int i=2;i<=n;i++)
	{
		int l=1,r=i;
		while (l<r)
		{
			int mid=(l+r)>>1;
			int tmp=(i-mid+1)*a[i];
			tmp-=(sum[i]-sum[mid-1]);
			if (tmp<=m)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
