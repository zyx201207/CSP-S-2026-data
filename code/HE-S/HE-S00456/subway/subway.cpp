#include<bits/stdc++.h>
#define int long long
#define debug puts("\n--------------")
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

inline int read() {
	int x = 0, k = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') k = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * k;
}

inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + '0');
	return;
}

const int N = 550;
const int M = 5e5 + 50;
int c, n, m, d, q;
int w[M];
int k[N];
int a[N], t[N];
int head[N], to[M << 1], nxt[M << 1], val[M << 1], tot;
int dis[N];
bool vis[N];

struct node {
	int id;
	int d;
	bool operator < (const node &x) const {
		return x.d < d;
	}
};
priority_queue<node> pq;

inline void dij(int x) {
	for (int i = 1; i <= m; ++i) {
		dis[i] = inf;
		vis[i] = false;
	}
	dis[x] = 0;
	vis[x] = true;
	pq.push({x, 0});
	
	while (!pq.empty()) {
		int now_node = pq.top().id;
		int now_d = pq.top().d;
		vis[now_node] = true;
		pq.pop();
		
		for (int i = head[now_node]; ~i; i = nxt[i]) {
			if (vis[to[i]]) continue;
			if (dis[to[i]] > now_d + val[i]) {
				dis[to[i]] = now_d + val[i];
				pq.push({to[i], dis[to[i]]});
			}
		}
	}
	return;
}

inline void add(int x, int y, int v) {
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
	return;
}

inline void solve() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	memset(head, -1, sizeof(head));
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) {
		w[i] = read();
	}
	for (int i = 1; i <= n; ++i) {
		k[i] = read();
		for (int j = 1; j <= k[i]; ++j) {
			a[j] = read(), t[j] = read();
			for (int k = 1; k < j; ++k) {
				add(a[k], a[j], t[k] + t[j]);
				add(a[j], a[k], t[k] + t[j]);
			}
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		int l = read(), r = read();
		dij(l);
		write(dis[r] + w[l] + w[r]);
		putchar('\n');
	}
	return;
}

int32_t main() {
	solve();
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
