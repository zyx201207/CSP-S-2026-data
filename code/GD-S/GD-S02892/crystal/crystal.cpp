#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005],ans=0;
bool chk(ll nw,ll x){return (nw-x+1)*a[nw]-(sum[nw]-sum[x-1])<=m;}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(chk(i,mid)) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-(r+1)+1);
	}
	printf("%lld",ans);
	return 0;
}
