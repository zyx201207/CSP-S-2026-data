#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pa pair<ll,ll>
#define fi first
#define se second
ll n,m;
ll a[500005];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll j=1;
	ll ned=m;
	ans=1;
	for (ll i=2;i<=n;i++)
	{
		while (j<i && (i-j)*(a[i]-a[i-1])>ned)
		{
			ned+=(a[i-1]-a[j]);
			j++;
		}
		ned-=(i-j)*(a[i]-a[i-1]);
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
	}

