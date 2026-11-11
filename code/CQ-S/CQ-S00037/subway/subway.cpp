#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int input() {
	int x;
	cin >> x;
	return x;
}
int c, n, m, d2, q;
int w[5000005], d[5000005], l[3005][3005];
bool vis[5000005];
vector<pair<int, int> > e[500005];
void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qu;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i ++) d[i] = INT_MAX;
	d[s] = 0;
	qu.push({0, s});
	while (!qu.empty()) {
		auto t = qu.top();
		qu.pop();
		int u = t.second, w = t.first;
		if (vis[u]) continue;
		vis[u] = true;
		for (auto i : e[u]) {
			int v = i.first, dis = i.second;
			if (dis + w + l[v][v] < d[v]) {
				d[v] = dis + w + l[v][v];
				qu.push({dis + w + l[v][v], v});
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    c = input(), m = input(), n = input(), d2 = input(), q = input();
    for (int i = 1; i <= n; i ++) cin >> w[i];
    for (int i = 1; i <= m; i ++) {
    	int k = input();
    	for (int i2 = 1; i2 <= k; i2 ++) {
    		int u = input(), v = input();
    		e[i].push_back({u, v});
    		e[u].push_back({i, v});
    		l[u][i] = l[i][u] = v;
		}
	}
	while (q --) {
		int a = input(), b = input();
		dijkstra(a);
		cout << d[b] + w[a] + w[b] + l[a][a] - l[b][b] << endl;
	}
	return 0;
}
