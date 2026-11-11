#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+9;
ll n,k;
ll a[N];
ll s[N];
bool check(ll mid,ll r)
{
	return (r-mid+1)*a[r]-(s[r]-s[mid-1])<=k;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	s[i]=s[i-1]+a[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		//1~i全部变成能量为a[i]
		ll l=1,r=i,ret=i;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid,i))ret=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-ret+1);
	}
	printf("%lld",ans);
	return 0;
}
