#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 2e6 + 50, Q = 1e5 + 50, N = 5e5 + 50;
int c, n, m, p, question;
ll d[N], ans[Q];
bool vis[N];
struct node {
	int pos, dis;
	inline bool operator < (node x) const {
		return dis > x.dis;
	}
};
struct edge {
	int x, y, id;
}t[Q];
int head[M], val[M], nxt[M], to[M], tot;
void add (int u, int v, int w) {
	tot ++;
	to[tot] = v;
	nxt[tot] = head[u];
	val[tot] = w;
	head[u] = tot;
}
bool cmp (edge a, edge b) {
	return a.x < b.x;
}
priority_queue <node> q;
void D(int s) {
	memset (vis, 0, sizeof vis);
	memset (d, 0x3f3f3f3f, sizeof d);
	while (! q.empty()) {
		q.pop();
	}
	q.push ({s, 0});
	d[s] = 0;
	vis[s] = 1;
	while (! q.empty()) {
		int x = q.top().pos;
		q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = to[i], w = val[i];
			if (vis[y]) continue;
			vis[y] = 1;
			d[y] = min (d[y], d[x] + w);
			q.push ({y, w});
		}
	}
}
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin . tie(0), cout . tie(0);
	cin >> c >> n >> m >> p >> question;
	for (int i = 1; i <= m; i ++) {
		int w;
		cin >> w; 
		add (i, i + m, w);
		add (i + m, i, w);
	}
	for (int i = 1; i <= n; i ++) {
		int k, a, t;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			cin >> a >> t;
			add (a + m, i + m + m, t);
			add (i + m + m, a + m, t);
		}
	}
	for (int i = 1; i <= question; i ++) {
		cin >> t[i].x >> t[i].y;
		t[i].id = i;
	}
	sort (t + 1, t + 1 + question, cmp);
	for (int i = 1; i <= question; i ++) {
		if (t[i].x != t[i - 1].x) {
			D(t[i].x);
		}
		ans[t[i].id] = d[t[i].y];
	}
	for (int i = 1; i <= question; i ++) {
		cout << ans[i] << '\n';
	}
	return 0; 
}
