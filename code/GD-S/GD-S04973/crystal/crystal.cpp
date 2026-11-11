#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll a[N];
ll sum[N];
ll n,m;
int ans;
int query(int x)
{
	int l=1,r=x;
	int s=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(((x-mid+1)*a[x]-(sum[x]-sum[mid-1]))<=m)
		{
			s=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return x-s+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)ans=max(query(i),ans);
	printf("%d",ans);
	return 0;
}
