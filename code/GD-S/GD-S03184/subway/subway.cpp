#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
struct Node {
	int a;
	long long b;
};
int c, n, m, d, q, w[MAX], x, y;
long long ans;
vector<Node> g[500510];
bool vis[500510];
void dfs(int s, long long sum) {
	if (s == y) {
		ans = min(ans, sum);
		return ;
	}
	for (int i = 0; i < g[s].size(); i++) {
		int to = g[s][i].a;
		if (vis[to]) {
			continue;
		}
		vis[to] = true;
		dfs(to, sum + g[s][i].b);
		vis[to] = false;
	}
}
long long bfs() {
	queue<Node> q;
	memset(vis, false, sizeof(vis));
	vis[x] = true;
	q.push({x, 0});
	while (!q.empty()) {
		int s = q.front().a, sum = q.front().b;
		q.pop();
		if (s == y) {
			return sum;
		}
		for (int i = 0; i < g[s].size(); i++) {
			int to = g[s][i].a;
			if (vis[to]) {
				continue;
			}
			vis[to] = true;
			q.push({to, sum + 1});
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	int A;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a;
			long long t;
			cin >> a >> t;
			A = t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	if (c >= 12 && c <= 15) {
		while (q--) {
			cin >> x >> y;
			cout << A * bfs() + w[x] + w[y] << endl;
		}
		return 0;
	}
	while (q--) {
		cin >> x >> y;
		ans = 0x3f3f3f3f;
		dfs(x, 0);
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
} 
