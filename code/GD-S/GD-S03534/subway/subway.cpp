#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5.1e5;
const ll INF = 4e18;
int c, n, m, d, q;
int cnt[N], ans[N];
ll w[N], dis[N][21];
bool vis[N][21];
vector<pair<pair<int, int>, ll>> G[N][21];
vector<pair<int, int>> qry[N];

void dij(int s) {
	for (int i = 1; i <= n + m; i++) {
		for (int j = 0; j <= cnt[i]; j++) {
			dis[i][j] = INF;
			vis[i][j] = false;
		}
	}
	priority_queue<pair<ll, pair<int, int>>> q;
	q.push({0, {s, 0}});
	dis[s][0] = 0;
	while (!q.empty()) {
		auto u = q.top().second;
		q.pop();
		if (vis[u.first][u.second]) continue;
		vis[u.first][u.second] = true;
		for (auto &e : G[u.first][u.second]) {
			auto v = e.first;
			ll w = e.second;
			ll nw = dis[u.first][u.second] + w;
			ll &d = dis[v.first][v.second];
			if (d > nw) {
				d = nw;
				q.push({-d, v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, x, y; j <= k; j++) {
			cin >> x >> y;
			++cnt[x];
			G[x][cnt[x]].push_back({{m + i, 0}, 0});
			G[m + i][0].push_back({{x, cnt[x]}, 0});
			G[x][cnt[x]].push_back({{x, 0}, y});
			G[x][0].push_back({{x, cnt[x]}, y});
		}
	}
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		qry[x].push_back({y, i});
	}
	for (int x = 1; x <= m; x++) {
		if (qry[x].empty()) continue;
		dij(x);
		for (auto q : qry[x]) {
			int y = q.first, qid = q.second;
			ans[qid] = w[x] + dis[y][0] + w[y];
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
