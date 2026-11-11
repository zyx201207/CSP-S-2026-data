#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int c, T, n, d, a[N], ans, dis[N], cnt[N];
bool vis[N];

struct heap {
	int siz;
	struct node {
		int u, dis;
	} h[N << 3];
	
	void push(node x) {
		h[++siz] = x;
		int i = siz;
		while (h[i].dis < h[i / 2].dis && i / 2 > 0) {
			swap(h[i], h[i / 2]);
			i /= 2;
		}
	}
	
	void pop() {
		swap(h[1], h[siz]);
		siz--;
		int i = 1;
		while (i * 2 <= siz) {
			int t = i * 2;
			if (h[t + 1].dis < h[t].dis && t + 1 <= siz) t++;
			if (h[i].dis < h[t].dis) break;
			swap(h[i], h[t]);
			i = t;
		}
	}
} q;

void dijkstr(int s) {
	q.siz = 0;
	for (int i = 1; i <= n; ++i) dis[i] = N, cnt[i] = 0, vis[i] = 0;
	dis[s] = 0, cnt[s] = 1;
	q.push({s, 0});
	while (q.siz) {
		int u = q.h[1].u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = u + 1; i <= n; ++i) {
			if (abs(a[u] - a[i]) > d) break;
			if (dis[i] > dis[u] + 1) {
				dis[i] = dis[u] + 1;
				cnt[i] = cnt[u];
				q.push({i, dis[i]});
			} else if (dis[i] == dis[u] + 1) cnt[i] += cnt[u];
		}
	}
}

void init() {
	ans = 0;
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
}

void solve() {
	init();
	for (int i = 1; i <= n; ++i) {
		dijkstr(i);
		for (int j = i + 1; j <= n; ++j) if (cnt[j] == 2) ans++;
	}
	printf("%lld\n", ans);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &T);
	while (T--) solve();
	return 0;
}
