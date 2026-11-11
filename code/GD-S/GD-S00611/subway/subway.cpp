#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 5e5 + 10, M = 5e2 + 10, inf = 1e18;

int C, n, m, d, Q;
ll w[N];
ll dis[M][M];
vector<pair<int, ll>> to[N + M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> C >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			ll A, T;
			cin >> A >> T;
			to[A].push_back({m + i, T});
			to[m + i].push_back({A, T});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			dis[i][j] = dis[j][i] = inf;
	for (int i = 1; i <= n; i++) {
		for (pair<int, ll> v : to[m + i]) {
			for (pair<int, ll> j : to[v.first]) {
				//cout << i << ' ' << v.first << ' ' << j.first - m << ' ' << v.second << ' ' << j.second << '\n';
				dis[i][j.first - m] = min(dis[i][j.first - m], v.second + j.second);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dis[i][j] = min(dis[i][j], dis[j][i]);
			dis[j][i] = min(dis[i][j], dis[j][i]);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
		
	for (int i = 1; i <= Q; i++) {
		int u, v;
		cin >> u >> v;
		ll ans = inf;
		for (int j = 1; j <= n; j++) {
			ll tou = inf, tov = inf;
			for (pair<int, ll> k : to[u]) {
				if (k.first - m == j)
					tou = min(tou, k.second);
				else 
					tou = min(tou, k.second + dis[k.first - m][j]);
			}
			for (pair<int, ll> k : to[v]) {
				if (k.first - m == j)
					tov = min(tov, k.second);
				else 
					tov = min(tov, k.second + dis[k.first - m][j]);
			}
			ans = min(ans, tou + tov + w[u] + w[v]);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
//example 2 have 325 :)
