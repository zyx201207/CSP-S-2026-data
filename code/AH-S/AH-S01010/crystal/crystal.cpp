#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
ll m,a[500005],sum[500005];
inline bool cmp(ll x,ll y){return x>y;}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;--i)
	{
		int l=i,r=n,mid;
		while(l<=r)
		{
			mid=l+r>>1;
			if(1ll*a[i]*(mid-i+1)-(sum[mid]-sum[i-1])<=m) l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r-i+1);
	}
	printf("%d\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
