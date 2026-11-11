#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
	int to, v;
	node (int _to, int _v) {
		to = _to, v = _v;
	}
};

vector<node> edges[501];
int w[500001];
int cc[500001];
int k[501];
int dist[501];	
int a[501][500001];
int c, n, m, d, p;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dij(int x) {
	pq.push({0, x});
	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[x] = 0;
	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		if (x > dist[y]) continue;
		for (auto yy : edges[x]) {
			if (dist[y] + yy.v < dist[yy.to]) {
				dist[yy.to] = dist[y] + yy.v;
				pq.push({dist[yy.to], yy.to});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int t, q;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t;
			cc[a[i][j]]++;
			if (j == 1 || j == k[i]) continue;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (cc[a[i][j]] > 1) {
				edges[a[i][j]].push_back(node(a[i][j - 1], t));
				edges[a[i][j - 1]].push_back(node(a[i][j], t));
				edges[a[i][j]].push_back(node(a[i][j + 1], t));
				edges[a[i][j + 1]].push_back(node(a[i][j], t));
				edges[a[i][j - 1]].push_back(node(a[i][j + 1], 0));
				edges[a[i][j + 1]].push_back(node(a[i][j - 1], 0));
			} else {
				edges[a[i][j]].push_back(node(a[i][j - 1], 0));
				edges[a[i][j - 1]].push_back(node(a[i][j], 0));
				edges[a[i][j]].push_back(node(a[i][j + 1], 0));
				edges[a[i][j + 1]].push_back(node(a[i][j], 0));
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		dij(x);
		cout << dist[y] + w[x] + w[y] << "\n";
	}
	return 0;
}
