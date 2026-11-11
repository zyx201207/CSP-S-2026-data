#include<bits/stdc++.h>
typedef long long ll;
const ll N=5e5+5;
using namespace std;
ll n,m,a[N],s[N];
bool check(ll mid)
{
	for(ll i=mid;i<=n;i++)
	{
		if (s[i-1]-s[i-mid]+m>=(mid-1)*a[i])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=n,ans=1;
	while(l<=r)
	{
		ll mid=l+((r-l)>>1);
		if (check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
