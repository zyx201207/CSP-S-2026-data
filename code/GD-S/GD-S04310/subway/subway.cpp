#include <iostream>
#include <vector>

#define ll long long

#define eb emplace_back

#define pii pair <int, ll>
#define fi first
#define se second
#define mp make_pair

using namespace std;

const int N = 510;
const int M = 5e5 + 10;
const int D = 22;

vector <pii> g[M];

int c, n, m, d, q;

ll w[M];

ll f[N][N];

ll min (ll a, ll b) {
	return a < b ? a : b;
}

int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			f[i][j] = 1e18;
	for (int i = 1; i <= n; ++ i)
		f[i][i] = 0;
	for (int i = 1; i <= m; ++ i) cin >> w[i];
	for (int i = 1; i <= n; ++ i) {
		int len;
		cin >> len;
		for (int j = 1; j <= len; ++ j) {
			int u, c;
			cin >> u >> c;
			g[u].eb (mp (i, c));
		}
	}
	for (int i = 1; i <= m; ++ i) 
		for (pii u : g[i]) 
			for (pii v : g[i])
				f[u.fi][v.fi] = f[v.fi][u.fi] = min (f[u.fi][v.fi], u.se + v.se);
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				f[i][j] = min (f[i][j], f[i][k] + f[k][j]);
	while (q --) {
		int s, t;
		cin >> s >> t;
		ll res = 1e18;
		for (pii u : g[s])
			for (pii v : g[t])
				res = min (res, f[u.fi][v.fi] + u.se + v.se);
		cout << res + w[s] + w[t] << '\n';		
	}
	
	return 0;
} 
