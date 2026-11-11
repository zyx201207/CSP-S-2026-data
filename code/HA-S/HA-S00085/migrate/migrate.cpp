/*
bfs?
*/
#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second

using namespace std;

#define N 2000005
#define INF 1e18

ll c, t, n, d, a[N], ans;
ll dis[N], vis[N], cnt[N];
queue<pii> q;

inline void bfs(int s) {
	for (int i = 1; i <= n; i++) dis[i] = INF;
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	dis[s] = 0;
	
	q.push({s, 0});
	while (q.size()) {
		int u = q.front().fi, len = q.front().se; q.pop();
		
		if (len == dis[u]) cnt[u]++;
		if (len < dis[u]) {
			dis[u] = len;
			cnt[u] = 1;
		}
		
		int idx = upper_bound(a + 1, a + n + 1, a[u] + d) - a;
		for (int i = u + 1; i < idx; i++) {
			q.push({i, len + 1});
		}
	}
	return;
}

inline void solve() {
	ans = 0;
	
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		bfs(i);
		for (int j = i + 1; j <= n; j++) {
//			cerr << cnt[j] << " ";
			if (cnt[j] == 2) ans++;
		}
//		cerr << "\n";
	}
	
	cout << ans << "\n";
	return;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> c >> t;
	while (t--) solve();

	return 0;
}

