#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, M = 5e5+5;
struct JZ {
	int c, t;
};
int c, n, m, d, q;
int W[M], dis[N][N];
vector <JZ> a[M];
map <int, int> mp[M], sum[M];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> W[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, id, t; j <= k; j++) {
			cin >> id >> t;
			a[id].push_back((JZ){i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto j : a[i]) {
			for (auto k : a[i]) {
				if (j.c == k.c) continue;
				dis[j.c][k.c] = min(dis[j.c][k.c], j.t+k.t);
				dis[k.c][j.c] = min(dis[k.c][j.c], j.t+k.t);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int k = 1; k <= n; k++) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
		}
	}
	for (int i = 1, s, t; i <= q; i++) {
		cin >> s >> t;
		if (s > t) swap(s, t);
		if (mp[s][t] != 0) {
			cout << sum[s][t] << '\n';
			continue;
		}
		int ans = 1e18;
		for (auto j:a[s]) {
			for (auto k:a[t]) {
				ans = min(ans, W[s]+j.t+dis[j.c][k.c]+k.t+W[t]);
			}
		}
		cout << ans << '\n';
		mp[s][t] = 1, sum[s][t] = ans;
	}
	return 0;
}
