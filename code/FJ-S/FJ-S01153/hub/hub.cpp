#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define Write cin.tie(nullptr);
#define by cout.tie(nullptr);
#define ___NightDay___ ios::sync_with_stdio(0)
#define N 3005
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mkpr make_pair
#define fi first
#define se second

int c, q, n, m, ans;
struct Edge {
	int nxt, to;
} e[N * 2];
int h[N], ecnt;
void add_edge(int u, int v) {
	ecnt ++;
	e[ecnt].to = v;
	e[ecnt].nxt = h[u];
	h[u] = ecnt;
	return;
}

int vis[N], vis1[N];
void dfs1(int x) {
	if (! vis[x]) {
		return;
	}
	if (vis1[x]) {
		return;
	}
	vis1[x] = 1;
	for (int i = h[x]; i; i = e[i].nxt) {
		dfs1(e[i].to);
	}
	return;
}
bool vis2[N];
int bfs(int x) {
	queue<pii> q;
	q.push(mkpr(x, 0));
	vis2[x] = 1;
	while (! q.empty()) {
		pii t = q.front();
		q.pop();
		for (int i = h[t.fi]; i; i = e[i].nxt) {
			if (vis[e[i].to]) {
				return t.se + 1;
			}
			if (vis2[e[i].to]) {
				continue;
			}
			vis2[e[i].to] = 1;
			q.push(mkpr(e[i].to, t.se + 1));
		}
	}
	return -1;
}
void dfs(int stp, int last) {
	if (stp > m) {
		memset(vis1, 0, sizeof(vis1));
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[i] && ! vis1[i]) {
				dfs1(i);
				cnt ++;
			}
		}
		if (cnt > 2) {
			return;
		}
		int tmax = -inf;
		for (int i = 1; i <= n; i ++) {
			if (! vis[i]) {
				memset(vis2, 0, sizeof(vis2));
				int res = bfs(i);
				tmax = max(res, tmax);
			}
		}
		ans = min(tmax, ans);
		return;
	}
	for (int i = last + 1; i <= n; i ++) {
		vis[i] = 1;
		dfs(stp + 1, i);
		vis[i] = 0;
	}
	return;
}

int main() {
	Write by ___NightDay___;
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> q;
	while (q --) {
		cin >> n >> m;
		ans = inf;
		ecnt = 0;
		memset(h, 0, sizeof(h));
		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}

// 15pts, #1~3
// ALL: 100 + [80, 100] + 40 + 15 = [235, 255]
