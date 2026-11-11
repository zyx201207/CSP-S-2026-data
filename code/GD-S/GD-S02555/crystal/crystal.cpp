#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500001],sum[500001];
long long l=(long long)(1e12),r=(long long)(1e12);
int check(long long mid)
{
	long long sum=0;
	int t=0;
	for (int i=1;i<=n;i++)
		if (a[i]<=mid)
			sum+=mid-a[i],t++;
	if (sum>m)
		return -1;
	return t;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]),l=min(a[i],l);
	sort(a+1,a+n+1);
	while (l<=r)
	{
		long long mid=(l+r)>>1;
		int k=check(mid);
		if (k!=-1)
			l=mid+1,ans=max(ans,k);
		else 
			r=mid-1;
	}
	printf("%d",ans);
}
