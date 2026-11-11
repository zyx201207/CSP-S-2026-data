#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 510, M = 5e5 + 10;
const ll INF = 1LL << 60LL;

struct Edge {
	int v, w;	
} ;

int test, n, m, d, q, w[M];
vector<Edge> edges[M];
ll f[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> test >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int len;
		cin >> len;
		for (int j = 1; j <= len; j++) {
			int a, t;
			cin >> a >> t;
			edges[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = INF;
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto x : edges[i])
			for (auto y : edges[i])
				f[x.v][y.v] = min(f[x.v][y.v], (ll)x.w + y.w);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (; q--; ) {
		int a, b;
		cin >> a >> b;
		ll ans = INF;
		for (auto x : edges[a])
			for (auto y : edges[b])
				ans = min(ans, f[x.v][y.v] + x.w + y.w); 
		ans += (ll)w[a] + w[b];
		cout << ans << "\n";
	}
	return 0;
}

