#include <bits/stdc++.h>
using namespace std;
const long long N = 505, M = 5e5 + 5, inf = 1e18;
long long c, n, m, d, q, f[N][N], w[M], tmp, u, v, ans, h, p;
vector<pair<long long, long long>> e[M];
int main() {
	cin.tie(0) -> sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= n; j++)
			f[i][j] = inf;
	for (long long i = 1; i <= n; i++) f[i][i] = 0;
	for (long long i = 1; i <= m; i++) cin >> w[i];
	for (long long i = 1; i <= n; i++) {
		cin >> tmp;
		for (long long j = 1; j <= tmp; j++) {
			cin >> u >> v;
			e[u].push_back({i, v});
		}
	}
	for (long long i = 1; i <= m; i++) {
		for (pair<long long, long long> j : e[i])
			for (pair<long long, long long> k : e[i]) if (j != k) {
				f[j.first][k.first] = min(f[j.first][k.first], j.second + k.second);
				f[k.first][j.first] = f[j.first][k.first];
			}
	}
	for (long long k = 1; k <= n; k++)
		for (long long i = 1; i <= n; i++)
			for (long long j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		cin >> u >> v;
		ans = inf;
		for (pair<long long, long long> i : e[u])
			for (pair<long long, long long> j : e[v]) 
				ans = min(ans, f[i.first][j.first] + i.second + j.second);
		ans += w[u] + w[v];
		cout << ans << '\n';
	}
	return 0;
} 
