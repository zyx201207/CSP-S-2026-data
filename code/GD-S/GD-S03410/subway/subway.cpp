#include <bits/stdc++.h>
#define PII pair<int, int>
#define xf first
#define ys second
#define ll long long
using namespace std;
const int N = 2e2 + 5;
const int M = 5e5 + 5;
const ll INF = 1e18;
ll w[M];
ll cg[N][M];
vector<int> tk[M];
ll dis[N][N];
void solve1() {
	int n, m, d, q;
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a;
			ll t;
			cin >> a >> t;
			cg[i][a] = t;
			tk[a].push_back(i);
		}
	}
	for (int  i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int l = tk[i].size();
		for (int j = 0; j <= l - 1; j++) {
			for (int k = 0; k <= l - 1; k++) {
				if (tk[i][j] != tk[i][k]) {
					dis[tk[i][j]][tk[i][k]] = dis[tk[i][k]][tk[i][j]] = min(cg[tk[i][j]][i] + cg[tk[i][k]][i], dis[tk[i][j]][tk[i][k]]);
				}
			}
		} 
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][j] >= dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		ll ans = INF;
		for (int j = 0; j <= tk[u].size() - 1; j++) {
			for (int k = 0; k <= tk[v].size() - 1; k++) {
				ans = min(ans, dis[tk[u][j]][tk[v][k]] + w[u] + w[v] + cg[tk[u][j]][u] + cg[tk[v][k]][v]);
			}
		} 
		cout << ans << endl;
	}
}

const int NN = 5e2 + 5;
vector<int> e[NN];
bitset<NN> vis;
bitset<NN> ddd;
void solve2() {
	
}
void solve3() {
	int n, m, d, qq;
	cin >> n >> m >> d >> qq;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	ll T;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a;
			cin >> a >> T;
			tk[a].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		int l = tk[i].size();
		for (int j = 0; j <= l - 1; j++) {
			for (int k = 0; k <= l - 1; k++) {
				if (tk[i][j] != tk[i][k]) {
					e[tk[i][j]].push_back(tk[i][k]);
					e[tk[i][k]].push_back(tk[i][j]);
				}
			}
		} 
	}
	for (int i = 1; i <= qq; i++) {
		int u, v;
		cin >> u >> v;
		for (int j = 1; j <= n; j++) {
			ddd[j] = vis[j] = false;
		}
		for (auto x : tk[v]) {
			ddd[x] = true;
		}
		queue<PII> q;
		for (auto x : tk[u]) {
			q.push({x, 0});
			vis[x] = true;
		}
		int ans = 0;
		while (!q.empty()) {
			int x = q.front().xf;
			int t = q.front().ys;
			q.pop();
			if (ddd[x]) {
				ans = t;
				break;
			}
			
			for (auto y : e[x]) {
				if (!vis[y]) {
					vis[y] = true;
					q.push({y, t + 1});
				}
			}
		}
		ll o = T * 2ll + 2ll * T * ans + w[u] + w[v];
		cout << o << endl;
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	cin >> c;
	if (c <= 8 || c == 20 || c == 21) {
		solve1();
	}
	else if (9 <= c && c <= 11) {
		solve2();
	}
	else if (12 <= c && c <= 19) {
		solve3();
	}
	else {
		
	}
	return 0;
} 
