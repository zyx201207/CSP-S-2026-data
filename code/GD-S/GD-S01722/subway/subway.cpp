#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 507, M = 1e4+7, SOL1 = 607;
int c, n, m, d, q, w[N], len[M], dis1[SOL1][SOL1];
vector<int> a[M], t[M];
vector<int> g[M];
void solution1() {
	memset(dis1, 0x3f, sizeof dis1);
	int tot = n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			int v = a[i][j];
			tot++;
			dis1[tot][v] = dis1[v][tot] = t[i][j];
			if (j != 0) dis1[tot-1][tot] = dis1[tot][tot-1] = 0;
		}
	}
	for (int i = 1; i <= tot; ++i) dis1[i][i] = 0;
	for (int k = 1; k <= tot; ++k) {
		for (int i = 1; i <= tot; ++i) {
			for (int j = 1; j <= tot; ++j) {
				dis1[i][j] = min(dis1[i][j], dis1[i][k] + dis1[k][j]);
			}
		}
	}
	while(q--) {
		int u, v; cin >> u >> v;
		cout << dis1[u][v] + w[u] + w[v] << "\n";
	}
}
signed main() {// n, m º¬Òå¶Ôµ÷ 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; ++i) cin >> w[i];
	for (int i = 1; i <= m; ++i) {
		cin >> len[i];
		for (int j = 1; j <= len[i]; ++j) {
			int v, T; cin >> v >> T;
			a[i].push_back(v), t[i].push_back(T);
		}
	}
	solution1();
	return 0;
}

