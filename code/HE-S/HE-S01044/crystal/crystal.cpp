#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=1;
int a[N],sum[N];
bool check(int x)
{
	int minn=1e18+5;
	for(int i=x;i<=n;i++)
		minn=min(minn,(x*a[i])-(sum[i]-sum[i-x]));
	return (minn<=m);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1,ans=mid;
		else
			r=mid;
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
