#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,ans;
ll a[500011],sum[500011];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for(ll i=1;i<=n;i++)
		sum[i] = sum[i - 1] + a[i];
	ll r = 1;
	for(ll l=1;l<=n;l++) {
		if (r < l)
			r = l;
		while (r < n && a[r + 1] * (r - l + 2) - (sum[r + 1] - sum[l - 1]) <= m)
			r++;
		ans = max(ans,r - l + 1);
	}
	printf("%lld\n",ans);
	return 0;
} 
