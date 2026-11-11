// T3 migrate
// time: /usr/bin/time -v ./task
// long long. memory. 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
	LL p, v; // to point, value is.
};

bool operator< (node x, node y) {
	return x.v < y.v;
}

bool operator> (node x, node y) {
	return x.v > y.v;
}

const LL MAXN = 1e4 + 5;
const LL INF = 5e18;
LL x[MAXN];
LL dis[MAXN][MAXN], cnt[MAXN][MAXN];
bool vis[MAXN];
vector <node> g[MAXN];
LL n, d;
// 不用想 最短路计数  

void dijkstra(LL x) {
	// x: 起点
	priority_queue <node, vector<node>, greater<node> > q;
	q.push({x, 0}); // 这个点 x，自己到自己 肯定是0 最先
	for (LL i = 0; i < MAXN; i++) vis[i] = false;
	dis[x][x] = 0;
	cnt[x][x] = 1;
	while (!q.empty()) {
		node t = q.top();
		LL tp = t.p;
		q.pop();
		if (vis[tp]) continue;
		vis[tp] = true;
		for (LL i = 0; i < g[tp].size(); i++) {
			node nxt = g[tp][i]; // 下一个点 这条边 
			if (nxt.p <= tp) continue; // 回头 不算。 
			if (nxt.v > d) continue;
			if (!vis[nxt.p] && dis[x][nxt.p] > dis[x][tp] + 1) { // 当前有的路 比当前点距离到下一个点的距离大 
				dis[x][nxt.p] = dis[x][tp] + 1;
				cnt[x][nxt.p] = cnt[x][tp];
				q.push({nxt.p, dis[x][nxt.p]});
			}
			else if (!vis[nxt.p] && dis[x][nxt.p] == dis[x][tp] + 1) {
				cnt[x][nxt.p] += cnt[x][tp];
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false); 
	LL c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (LL i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (LL i = 1; i <= n; i++) {
			g[i].clear(); 
			for (LL j = i; j <= n; j++) {
				if (i == j) continue;
				g[i].push_back({j, x[j] - x[i]});
			}
		}
		for (LL i = 0; i <= n; i++) {
			for (LL j = 0; j <= n; j++) {
				dis[i][j] = INF;
				cnt[i][j] = 0;
			}
		}
		for (LL i = 1; i <= n; i++) {
			dijkstra(i);
		}
		LL ans = 0;
		for (LL i = 1; i <= n; i++) {
			for (LL j = i; j <= n; j++) {
				if (cnt[i][j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << "\n"; 
	}
	return 0;
}
