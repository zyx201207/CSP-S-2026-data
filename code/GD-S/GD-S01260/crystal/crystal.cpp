#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5;
int a[N+11],sum[N+11];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid,fin=i;
		while(l<=r)
		{
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)
				r=mid-1,fin=mid;
			else l=mid+1;
		}
		ans=max(ans,i-fin+1);
	}
	printf("%lld",ans);
	return 0;
}
