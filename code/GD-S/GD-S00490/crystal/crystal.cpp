#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],sum[N];
bool check(ll x)
{
	for(int i=x;i<=n;i++)
	{
		ll val=a[i]*x-(sum[i]-sum[i-x]);
		if(val<=m) return true;
	}
	return false;
}
ll find(ll l,ll r)
{
	while(l+1<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	printf("%lld\n",find(0,n+1));
	return 0;
}
