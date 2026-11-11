#include <stdio.h>
#include <string.h>
#include <queue>
typedef long long int llong;
int c, t, n;
llong d, x[2000005];
std::queue <int> Q;
int dis[2000005], cnt[2000005];
int BFS (int s) {
	memset (dis, 0x3F, sizeof (dis));
	memset (cnt, 0, sizeof (cnt));
	Q.push (s);
	dis[s] = 0;
	cnt[s] = 1;
	while (!Q.empty ()) {
		int u = Q.front ();
		Q.pop ();
		for (int v = u - 1; v >= 1; --v) {
			if (x[u] - x[v] > d)	break;
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				Q.push (v);
			} else if (dis[u] + 1 == dis[v]) {
				cnt[v] += cnt[u];
			}
		}
		for (int v = u + 1; v <= n; ++v) {
			if (x[v] - x[u] > d)	break;
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				Q.push (v);
			} else if (dis[u] + 1 == dis[v]) {
				cnt[v] += cnt[u];
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)	res += (cnt[i] == 2);
	return res;
}
int main (void) {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%d %d", &c, &t);
	while (t--) {
		scanf ("%d %lld", &n, &d);
		for (int i = 1; i <= n; ++i)	scanf ("%lld", &x[i]);
		llong ans = 0;
		for (int i = 1; i <= n; ++i)	ans += (llong)BFS (i);
		printf ("%d\n", ans >> 1);
	}
	return 0;
}
