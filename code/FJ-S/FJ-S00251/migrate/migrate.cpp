#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000010, INF = 1e18;
int c, t, n, d;
// f ·½°¸Êı
// d ¾àÀë 
int x[N], f[N], dis[N];
int calc(int p) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) dis[i] = INF, f[i] = 0;
	f[p] = 1, dis[p] = 0;
	for (int i = p + 1; i <= n; i++) {
		for (int j = p; j < i; j++) {
			if (abs(x[i] - x[j]) <= d) {
				if (dis[j] == INF) continue;
				if (dis[j] + 1 < dis[i]) 
					f[i] = f[j], dis[i] = dis[j] + 1;
				else if (dis[j] + 1 == dis[i])
					f[i] += f[j];
			}
		} 
		if (f[i] == 2) cnt++;
	}
	return cnt;
}
void solve() {
	int ans = 0;
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
	for (int i = 1; i < n; i++) ans += calc(i);
	printf("%lld\n", ans);
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) solve();
	return 0;
}
