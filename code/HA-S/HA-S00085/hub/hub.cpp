/*
dijkstra ( ???
*/
#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second

using namespace std;

#define N 1000005

ll c, t, n, k, u, v, ans;
vector<int> g[N];

inline void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	cout << (n - k + 3) / 4 << "\n";
	return;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> c >> t;
	while (t--) solve();

	return 0;
}

