#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll bh,t,n,d,a[2000005],cnt[2000005],sum[2000005],ans;
bool f;

void dfs(ll pos) {
	for (ll i = n;i >= pos + 1;i--) {
		if (a[i] - a[pos] > d) continue;
		if (sum[pos] + 1 < sum[i]) {
			sum[i] = sum[pos] + 1;
			cnt[i] = 1;
			dfs(i);
		} 
		else if (sum[pos] + 1 == sum[i]) {
			cnt[i]++;
			dfs(i);
		}
	}
}

int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&bh,&t);
	while (t--) {
		scanf("%lld%lld",&n,&d);
		for (ll i = 1;i <= n;i++) scanf("%lld",&a[i]);
		if (n > 100) {
			if (d <= a[2] - a[1]) {
				printf("0\n");
				continue;
			}
			ll x = d / (a[2] - a[1]),minn = 2 * x - 1;
			if (minn > n) {
				printf("0\n");
				continue;
			}
			ll y = n - minn;
			printf("%lld\n",y);
			continue;
		}
		ans = 0;
		for (ll i = 1;i < n - 1;i++) {
			for (ll j = i;j <= n;j++) sum[j] = 1e18,cnt[j] = 0;
			sum[i] = 0;
			dfs(i);
			for (ll j = i + 2;j <= n;j++) 
				if (cnt[j] == 2) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
