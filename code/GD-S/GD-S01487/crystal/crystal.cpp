#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500005],ans;

int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (ll i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	ll l = 1,r = 0,sum = 0;
	for (ll i = 2;i <= n;i++) {
		sum += a[++r];
		while (a[i] * (r - l + 1) - sum > m && l <= r + 1) sum -= a[l++];
		ans = max(ans,r - l + 2);
	}
	if (!ans) printf("1");
	else printf("%lld",ans);
	return 0;
}
