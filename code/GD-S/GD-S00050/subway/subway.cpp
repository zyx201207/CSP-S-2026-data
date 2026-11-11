#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, cnt, b[N], C, D, w[N], len[N], vis[N];
long long d[N];
vector<int>a[N], t[N];
vector<pair<int, int>>e[N];
long long edge[2005][2005];
void dij(int s) {
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>q;
	for (int i = 0; i <= m + n + 5; i++)
		d[i] = 1e15, vis[i] = 0;
	q.push({0, s});
	d[s] = 0;
	while (!q.empty()) {
		auto tmp = q.top();
		long long x = tmp.second, y = tmp.first;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = 1;
		for (auto i : e[x]) {
			long long v = i.first, w = i.second;
			if (d[v] > d[x] + w)
				d[v] = d[x] + w, q.push({d[v], v});
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int i, j, x, y, z, q;
	cin >> C >> n >> m >> D >> q;
	for (i = 1; i <= m; i++)
		cin >> w[i];
	for (i = 1; i <= n; i++) {
		cin >> len[i];
		a[i].resize(len[i] + 5), t[i].resize(len[i] + 5);
		for (j = 1; j <= len[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= len[i]; j++) {
			e[m + i].push_back({a[i][j], t[i][j]});
			e[a[i][j]].push_back({m + i, t[i][j]});
		}
	}
	if (m <= 2000) {
		for (i = 1; i <= m; i++) {
			dij(i);
			for (j = 1; j <= m; j++)
				edge[i][j] = d[j];
		}
		while (q--) {
			cin >> x >> y;
			cout << w[x] + edge[x][y] + w[y]<< "\n";
		}
		return 0;
	}
	while (q--) {
		cin >> x >> y;
		dij(x);
		cout << w[x] + d[y] + w[y] << "\n";
	}
	return 0;
}
