#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],s[500010];
bool check(ll x)
{
	for(ll i=x;i<=n;i++)if(a[i]*x-(s[i]-s[i-x])<=m)return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	s[0]=0;
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll l=1,r=n,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
