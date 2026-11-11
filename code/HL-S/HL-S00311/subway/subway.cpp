#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q;
long long w[500001];
long long dis[501][501];
bool clac[501];
vector<pair<int, long long>> station[500001];

void spfa(int x) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			pq.push({ dis[x][i], i });
		}
	}
	while (pq.size()) {
		pair<long long, int> p = pq.top();
		pq.pop();
		if (p.first > dis[x][p.second]) continue;
		for (int i = 1; i <= n; i++) {
			if (dis[x][i] > p.first + dis[p.second][i]) {
				dis[x][i] = p.first + dis[p.second][i];
				pq.push({ dis[x][i], i });
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			long long t;
			cin >> a >> t;
			station[a].push_back({ i, t });
		}
	}
	for (int i = 1; i <= m; i++) {
		for (pair<int, long long> p1 : station[i]) {
			for (pair<int, long long> p2 : station[i]) {
				dis[p1.first][p2.first] = min(dis[p1.first][p2.first], p1.second + p2.second);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		spfa(i);
	}
	while (q--) {                                  
		int x, y;
		cin >> x >> y;
		if (x == y) {
			cout << 0 << '\n';
			continue;
		}
		long long res = 1ll << 60;
		for (pair<int, long long> p1 : station[x]) {
			for (pair<int, long long> p2 : station[y]) {
				res = min(res, dis[p1.first][p2.first] + p1.second + p2.second);
			}
		}
		cout << res + w[x] + w[y] << '\n';
	}
	return 0;
}
