#include <iostream>
#include <cctype>
#include <queue>
#include <algorithm>
#define gc getchar
#define pc putchar
#define int long long
using namespace std;
const int N = 2000006, E = 5000006;
int n, _, Q, d, a[N];
int u, v, head[N], nxt[E], cnt, to[E], dis[N], path[N];
bool vis[N];
inline void rd(int &x) {
	int sum = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
	for (; isdigit(c); c = gc()) sum = sum * 10 + c - '0';
	x = sum * f;
}
inline void pt(int x) {
	if (x > 9) pt(x/10);
	pc(x%10+'0');
}
inline void wt(int x) {
	if (x < 0) {pc('-'); x = -x;}
	pt(x);
}
void add(int u, int v) {
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
struct node {
	int i, dis;
	bool operator <(const node &x) const {
		return x.dis < dis;
	}
};
int Dijkstra(int s) {
	priority_queue <node> q;
	int now;
	for (int i = 1; i <= n; i++) dis[i] = 1e18, vis[i] = 0, path[i] = 0;
	dis[s] = 0; vis[s] = 1;
	q.push({s, 0});
	path[s] = 1;
	while (!q.empty()) {
		now = q.top().i; q.pop();
//		wt(now);pc('\n');
		for (int i = head[now]; i; i = nxt[i]) {
//			wt(to[i]);pc('<');
			if (dis[now] + 1 < dis[to[i]]) {
				path[to[i]] = 1;
				dis[to[i]] = dis[now] + 1;
				if (!vis[to[i]]) {
					vis[to[i]] = 1;
					q.push({to[i], dis[to[i]]});
				}
			}
			else if (dis[now] + 1 == dis[to[i]]) {
				path[to[i]]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (path[i] == 2) ans++;
	} 
	return ans;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	rd(_);
	if (_ || _ == 0) {
		rd(Q); while (Q--) {
			rd(n); rd(d);
			cnt = 0;
			for (int i = 1; i <= n; i++) head[i] = 0, nxt[i] = 0, to[i] = 0;
			for (int i = 1; i <= n; i++) {
				rd(a[i]);
			}
//			sort(a+1, a+n+1);
			for (int i = 1; i <= n; i++) {
				for (int j = i+1; j <= n; j++) {
					if (a[j]-a[i]<=d) add(i, j);
					else break;
				}
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				ans += Dijkstra(i);
			}
			wt(ans);pc('\n');
		}
	}
//	else if (_ == 13 || _ == 14) {
//		rd(Q); while (Q--) {
//			rd(n); rd(d);
//			for (int i = 1; i <= n; i++) {
//				rd(a[i]);
//			}
//			wt(0);pc('\n');
//		}
//	}
	return 0;
}
