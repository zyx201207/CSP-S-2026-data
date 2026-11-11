#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 * 5 * 4;

int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	return x * f;
}

struct sbw {
	int nxt;
	int w = 1e18;
	bool operator < (const sbw & e) const {
		return e.w < w;
	}
};

vector < sbw > G[MAXN];
int dis[MAXN];
priority_queue < int > q;
int c, n, m, d, T;
int last;
bool vis[MAXN];

void dijkstra (int s) {
	dis[s] = 0;
	while (!q.empty()) {
		q.pop();
	}
	for (int i = 1; i <= G[s].size(); i++) {
		if (!vis[G[s][i].nxt]) {
			q.push(G[s][i].nxt);
			vis[G[s][i].nxt] = 1;
		}
	}
	while (!q.empty()) {
		int u = q.top();
		q.pop();
		for (int i = 1; i <= G[u].size(); i++) {
			if (dis[G[u][i].nxt] > G[u][i].w + dis[s]) {
				dis[G[u][i].nxt] = G[u][i].w + dis[s];
				if (!vis[G[u][i].nxt]) {
					vis[G[u][i].nxt] = 1;
					q.push(G[u][i].nxt);
				}
			}
		}
	}
}

int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	c = read ();
	n = read ();
	m = read ();
	d = read ();
	T = read ();
	for (int i = 1; i <= m; i++) {
		sbw t;
		t.nxt = i + m;
		t.w = read ();
		G[i].push_back(t);//iµØÌú¿Ú i + mµØÌúÕ¾  
	}
	for (int i = 1; i <= n; i++) {
		int k = read ();
		last = 0;
		for (int i = 1; i <= k; i++) {
			int a = read (), tt = read ();
			sbw t;
			t.nxt = a + m + n;
			t.w = tt;
			G[a + m].push_back(t);
			if (last) {
				sbw ttt;
				ttt.nxt = last;
				ttt.w = 0;
				G[a].push_back (ttt);
			}
			last = a;
		}
	}
	for (int i = 1; i <= T; i++) {
		memset (dis, sizeof (dis), 1e18);
		int x = read (), y = read ();
		dijkstra (x);
		printf ("%d\n", dis[y]);
	}
	return 0;
}
