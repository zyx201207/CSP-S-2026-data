#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

using ll = long long;
const int MAXM = 500005, MAXN = 505;
int n, m, q;
ll W[MAXM];
unordered_map<int, ll> dis[MAXM];
struct Node{
	int v, c;
};
vector<Node> G[MAXM];
unordered_map<int, ll> pays[MAXM];
vector<int> reach[MAXM];

void spfa(int s) {
	queue<pair<int, int>> q;
	for (auto route: reach[s]) {
		q.push(make_pair(s, route));
		dis[s].insert(make_pair(route, pays[s][route]));
	}
	while (!q.empty()) {
		int u = q.front().first, c1 = q.front().second;
		q.pop();
		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i].v, c2 = G[u][i].c;
			if (c1 == c2) {
				if (dis[v].find(c2) == dis[v].end()) {
					dis[v].insert(make_pair(c2, dis[u][c1]));
					q.push(make_pair(v, c2));
					continue;
				}
				if (dis[v][c2] > dis[u][c1]) {
					dis[v][c2] = dis[u][c1];
					q.push(make_pair(v, c2));
				}
				continue;
			}
			if (dis[v].find(c2) == dis[v].end()) {
				dis[v].insert(make_pair(c2, dis[u][c1] + pays[u][c1] + pays[u][c2]));
				q.push(make_pair(v, c2));
				continue;
			}
			if (dis[v][c2] > dis[u][c1] + pays[u][c1] + pays[u][c2]) {
				dis[v][c2] = dis[u][c1] + pays[u][c1] + pays[u][c2];
				q.push(make_pair(v, c2));
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, d;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)cin >>W[i];
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		int last_u = -1;
		for (int j = 1; j <= k; ++j) {
			int u;
			ll t;
			cin >> u >> t;
			reach[u].push_back(i);
			pays[u].insert(make_pair(i, t));
			if (last_u != -1) {
				G[last_u].push_back(Node{u, i});
			}
			last_u = u;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		spfa(x);
		ll ans = -1;
		for (auto it = dis[y].begin(); it != dis[y].end(); ++it) {
			int c = it->first;
			ll cost = it->second;
			cost += W[y] + pays[y][c] + W[x];
			if (ans == -1)ans = cost;
			else ans = min(ans, cost);
		}
		cout << ans << endl;
	}
	return 0;
}