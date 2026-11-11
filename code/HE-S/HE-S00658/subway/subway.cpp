#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 5;
int c, n, m, d, q;
vector<int> ed[N], val[N];
int w[N];
int k[505];
int a[505][N], t[505][N];
struct node {
	int x, dis;
	friend bool operator < (node a, node b) {
		return a.dis > b.dis;
	}
};
bool p[N];
int from[N];
int dis[N];
bool vis[N];
void dij(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<node> q;
	dis[s] = 0;
	q.push((node){s, dis[s]});
	while (!q.empty()) {
		int x = q.top().x;
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int i = 0; i < ed[x].size(); i++) {
			int u = ed[x][i], g = val[x][i];
			if (dis[u] > dis[x] + g) {
				dis[u] = dis[x] + g;
				q.push((node){u, dis[u]});
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= k[i]; j++) {
			if (!p[a[i][j - 1]]) {
				p[a[i][j - 1]] = 1;				
				from[a[i][j - 1]] = i;
				ed[a[i][j - 1]].push_back(a[i][j]);
				val[a[i][j - 1]].push_back(t[i][j - 1]);
			} else {
				ed[a[i][j - 1]].push_back(a[i][j]);
				val[a[i][j - 1]].push_back(t[from[a[i][j - 1]]][j - 1] + t[i][j - 1]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		dij(x);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}

