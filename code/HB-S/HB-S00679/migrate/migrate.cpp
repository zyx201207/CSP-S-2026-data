#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int c, t, n, d, a[N], k[N], cnt, dis[N];

void dfs(int x, int step) {
	dis[x] = min(dis[x], step);
	if (step > dis[x]) return;
	k[x]++;
	for (int i = n; i > x; i--) {
		if (a[i] - a[x] > d) continue;
		dfs(i, step + 1);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int j = 1; j <= n; j++) {
			memset(k, 0, sizeof k);
			memset(dis, 0x3f, sizeof dis);
			dfs(j, 1);
			for (int i = j + 1; i <= n; i++) if (k[i] == 2) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}

