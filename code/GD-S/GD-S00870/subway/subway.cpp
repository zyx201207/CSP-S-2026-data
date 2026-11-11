#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// the number of subway lines is small
// hinting at floyd on the subway lines
// that will be something like O(n^3 + qd^2)
// that will be on the order of 5e7, passable
// to t get from line i to line j
// we need to find the station where the interchange is quickest
// if we iterate over stations naively, this is O(md^2)
// 2e8 is a bit dangerous
// what if we iterate over all the lines
// then the stations that it can reach
// then the other lines at each station
// I think this is O(sum(k)d)
// good, total 6e7
// but why is this faster?
// never mind

int n, m, q;
ll w[500010], G[510][510];
vector<pair<int, ll>> E[510], V[500010];

void preprocess() {
	memset(G, 0x3f, sizeof(G));
	for (int i = 1; i <= n; i++) {
		for (auto [a, t1]: E[i]) {
			for (auto [j, t2]: V[a]) {
				if (i == j) continue;
				G[i][j] = min(G[i][j], t1 + t2);
			}
		}
	}
	for (int i = 1; i <= n; i++) G[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == i) continue;
			for (int j = 1; j <= n; j++) {
				if (j == i || j == k) continue;
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c, d;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i], V[i].reserve(d);
	for (int i = 1; i <= n; i++) {
		int l; cin >> l;
		E[i].reserve(l);
		while (l--) {
			int a; ll t;
			cin >> a >> t;
			E[i].push_back({a, t});
			V[a].push_back({i, t});
		}
	}
	preprocess();
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll md = 0x3f3f3f3f3f3f3f3f;
		for (auto [i, t1]: V[x]) {
			for (auto [j, t2]: V[y]) {
				md = min(md, t1 + t2 + G[i][j]);
			}
		}
		cout << md + w[x] + w[y] << "\n";
	}
	
	return 0;
}
