#include <iostream>
#include <cctype>
//#include <queue>
#include <vector>
#define gc getchar
#define pc putchar
#define int long long
using namespace std;
const int N = 500505, M = 500005, E = 10000005;
int n, _, m, d, Q, tot, stop, ans, t, stops, u, v, easy[M], /*head[N], nxt[E], w[E], cnt, to[E], dis[502][N],*/ f[502][502];
//bool vis[N];
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
//inline void wt(int x) {
//	if (x < 0) {pc('-'); x = -x;}
//	pt(x);
//}
/*void add(int u, int v, int W) {
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
	w[cnt] = W;
}
struct node {
	int i, dis;
	bool operator <(const node &x) const {
		return x.dis < dis;
	}
};*/
//int getDijkstra(int s, int t) {
//	priority_queue <node> q;
//	int now;
//	for (int i = 1; i <= tot; i++) dis[i] = 1e18, vis[i] = 0;
//	dis[s] = 0; vis[s] = 1;
//	q.push({s, 0});
//	while (!q.empty()) {
//		now = q.top().i; q.pop();
////		wt(now);pc('\n');
//		for (int i = head[now]; i; i = nxt[i]) {
////			wt(to[i]);pc('<');
//			if (dis[now] + w[i] < dis[to[i]]) {
//				dis[to[i]] = dis[now] + w[i];
//				if (!vis[to[i]]) {
//					vis[to[i]] = 1;
//					q.push({to[i], dis[to[i]]});
//				}
//			}
//		}
//	}
//	return dis[t];
//}
//priority_queue <node> q;
//void Dijkstra(int s) {
//	int now, S = s-m;
//	for (int i = 1; i <= tot; i++) dis[S][i] = 1e18, vis[i] = 0;
//	dis[S][s] = 0; vis[s] = 1;
//	q.push({s, 0});
//	while (!q.empty()) {
//		now = q.top().i; q.pop();
////		wt(now);pc('\n');
//		for (int i = head[now]; i; i = nxt[i]) {
////			wt(to[i]);pc('<');
//			if (dis[S][now] + w[i] < dis[S][to[i]]) {
//				dis[S][to[i]] = dis[S][now] + w[i];
//				if (!vis[to[i]]) {
//					vis[to[i]] = 1;
//					q.push({to[i], dis[S][to[i]]});
//				}
//			}
//		}
//	}
//}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
vector <pair<int, int>> link[N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	rd(_); rd(n); rd(m); rd(d); rd(Q); //tot = m+n;
	for (register int i = 1; i <= m; i++) {
		rd(easy[i]);
	}
	for (register int i = 1; i <= n; i++) {
		rd(stops);
		for (register int j = 1; j <= stops; j++) {
			rd(stop); rd(t); //add(stop, i+m, t); add(i+m, stop, t);
			link[stop].push_back({i, t});
//			wt(stop);pc('#');wt(i+m);pc('\n');
		}
	}
	for (register int i = 1; i <= n; i++) {
		for (register int j = 1; j <= n; j++) {
			f[i][j] = 1e18;
		}
	} // O(n^2)
	for (register int i = 1; i <= m; i++) {
		for (register pair<int, int> j : link[i]) {
			for (register pair<int, int> k : link[i]) {
				f[j.first][k.first] = min(f[j.first][k.first], j.second+k.second);
			}
		}
	} // O(md^2)
//	for (int i = 1; i <= n; i++) {
//		Dijkstra(i+m);
//	} // O(nmlogm)
	for (register int k = 1; k <= n; k++) {
		for (register int i = 1; i <= n; i++) {
			if (i == k) continue;
			for (register int j = 1; j <= n; j++) {
//				if (j == k) continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (Q--) {
		rd(u); rd(v);
		ans = 1e18;
//		for (int i = head[u]; i; i = nxt[i]) {
//			ans = min(ans, w[i] + dis[to[i]-m][v]);
//		}
		for (register pair<int, int> j : link[u]) {
			for (register pair<int, int> k : link[v]) {
				ans = min(ans, j.second + f[j.first][k.first] + k.second);
			}
		}
		pt(easy[u] + /*getDijkstra(u, v)*/ ans + easy[v]); pc('\n');
	} // O(Qd) -> O(Qd^2)
	
	return 0;
}
