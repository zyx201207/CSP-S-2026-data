// T2 subway
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

const LL MAXM = 5e5 + 5, MAXK = MAXM, MAXN = 5e2 + 5, MAXD = 20 + 5, MAXQ = 1e5 + 5;
const LL INF = 1e18;
// 没有>1e9。但是酌情开long long. 
LL w[MAXM], k[MAXN];
LL a[MAXK], t[MAXK]; // 5e2 * 5e5 = 2.5e8 woah 有点大 
LL dis[MAXN][MAXN];
bool vis[MAXN], vis2[MAXN][MAXN];
// 不是 太大了吧 存都存不了
// 预处理+动态 
LL c, n, m, d, q;
vector <node> g[MAXN];

void dijkstra(LL x) {
	// x: 起点。所以得用dis[x]开头。
	priority_queue <node, vector<node>, greater<node> > q;
	q.push({x, 0}); // 这个点 x，自己到自己 肯定是0 最先
	for (LL i = 0; i < MAXN; i++) vis[i] = false;
	dis[x][x] = 0;
	while (!q.empty()) {
		node t = q.top();
		LL tp = t.p;
		q.pop();
		if (vis[tp]) continue;
		vis[tp] = true;
		for (LL i = 0; i < g[tp].size(); i++) {
			node nxt = g[tp][i]; // 下一个点 这条边 
			if (dis[x][nxt.p] > dis[x][tp] + nxt.v) { // 当前有的路 比当前点距离到下一个点的距离大 
				dis[x][nxt.p] = dis[x][tp] + nxt.v;
				q.push({nxt.p, dis[x][nxt.p]});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q; // c = test_poLL.0 样例。 
	for (LL i = 1; i <= m; i++) {
		cin >> w[i]; // 口到厅的时间 
	}
		for (LL i = 1; i <= n; i++) {
			cin >> k[i]; // 每条线路经过站点数 
			for (LL j = 1; j <= k[i]; j++) {
				cin >> a[j] >> t[j]; // a是经过什么站 t表示这个站从厅到台的时间 往返一样 
			}
			for (LL x = 1; x <= k[i]; x++) {
				for (LL y = x; y <= k[i]; y++) {
					if (x == y) continue;
					g[a[x]].push_back({a[y], t[x] + t[y]});
					g[a[y]].push_back({a[x], t[x] + t[y]});
				}
		}
	}
	for (LL i = 0; i < MAXN; i++) {
		for (LL j = 0; j < MAXN; j++) {
			dis[i][j] = INF;
		}
	}
	for (LL i = 1; i <= m; i++) {
		dijkstra(i);
	}
	for (LL i = 1; i <= q; i++) {
		LL x, y;
		cin >> x >> y;
		// 出行计划起点终点
		// Q最大1e5 考虑dijkstra(m log m) 每个点 也就...5e2 * 5e5 * 10 有点玄但是这样最小 
		// 然后就这样。可以看一下速度。
		// 待会算。
		// dis存也就是二维dis，出发 每个点 也就n2 enough
		cout << dis[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2 

极端：5e5 走了 算了 待会儿再优化 
*/
