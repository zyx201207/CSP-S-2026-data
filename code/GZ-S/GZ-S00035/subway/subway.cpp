// GZ-S00035 贵阳市白云区华师一学校 袁子高 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
vector<int> a[MAXN], t[MAXN];
vector<pair<int, int>> G[MAXN];
vector<int> w(MAXN);
vector<int> dist(MAXN * 2);

void dijkstra(int n) {
	vector<char> vis(MAXN, 0);
	dist = vector<int>(MAXN, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
	dist[n] = 0;
	p.push({0, n});
	while (!p.empty()) {
		int u = p.top().second, d = p.top().first;
		p.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto it : G[u]) {
			int v = it.second, w = it.first;
			if (u + w < dist[v]) {
				dist[v] = u + w;
				p.push({u + w, v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d, p;
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int ai, ti;
			cin >> ai >> ti;
			a[i].push_back(ai);
			t[i].push_back(ti);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			G[i + m].push_back({t[i][j] + w[j] * 2, a[i][j]});
			G[a[i][j]].push_back({t[i][j] + w[j] * 2, i + m});
		}
	}
	while (p--) {
		int l, r;
		cin >> l >> r;
		dijkstra(l);
		cout << dist[r] + w[l] + w[r] << '\n';
	}
	return 0;
}
