#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
typedef pair<int, ll> PII;
typedef pair<ll, int> PLL;

const int N = 2e6 + 10;

int n;
ll dd, x[N];

namespace sol1 {
	const int N1 = 310;
	const ll inf = 1ll << 30;
	ll d[N1][N1];
	vector<PII> G[N1];
	void dij(int s) {
		for (int i = 1; i <= n; i++) {
			d[s][i] = inf;
		}
		d[s][s] = 0;
		priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
		pq.push({d[s][s], s});

		while (!pq.empty()) {
			auto o = pq.top();
			pq.pop();
			ll di = o.first;
			int u = o.second;
			if (di > d[s][u]) continue;
			for (auto v : G[u]) {
				int to = v.first, w = v.second;
				if (d[s][to] > d[s][u] + w) {
					d[s][to] = d[s][u] + w;
					pq.push({d[s][to], to});
				}
			}
		}
	}
	void sol() {
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
//		for (int i = 2;i <=n; i++) {
//			cout << x[i] - x[i - 1] << ' ';
//		}
//		cout << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ll v = x[j] - x[i];
				if (v > dd) break;
				G[j].pb({i, 1});
				G[i].pb({j, 1});
			}
		}
		for (int i = 1; i <= n; i++) {
			dij(i);
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1;j <= n; j++) {
				int ways = 0;
				for (int k = i + 1; k < j; k++) {
					if (d[i][k] + d[k][j] == d[i][j]) {
						++ways;
					}
				}
				if (ways == 2) ans++;
			}
		}
		cout << ans <<"\n";
	}
}

void solve() {
	cin >> n >> dd;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}

	if (n <= 300) {
		sol1::sol();
		return;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int c, T;
	cin >> c >> T;
	while (T--) solve();

	return 0;
}

/*
9

10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
