#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
// #define int ll
#define OJ

// constexpr int maxn = 2000010;
constexpr int maxn = 5010, max_edges = maxn * 3 * 2;

int C, T, n;
ll m, a[maxn];

struct Edge {
	int u, v, nxt;
} edges[max_edges];
int cnt_edge = 0, head[maxn];
inline void add(int u, int v) { edges[++cnt_edge] = { u, v, head[u] }; head[u] = cnt_edge; }

bool tree[max_edges];
int dis[maxn], cnt[maxn];
void bfs(int s) {
	rep (i, 1, n) dis[i] = 0x3f3f3f3f;
	queue<int> que;
	que.push(s), dis[s] = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		int cur = dis[u];
		for (int vw = head[u]; vw; vw = edges[vw].nxt) {
			int u = edges[vw].u, v = edges[vw].v;
			if (cur + 1 < dis[v]) dis[v] = cur + 1, que.push(v), tree[vw] = true, cnt[v] += cnt[u];
		}
	}
}

signed main() {
#ifdef OJ
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#else
	freopen("migrate3.in", "r", stdin);
	freopen("migrate3.out", "w", stdout);
#endif

	cin >> C >> T;
	rep (idt, 1, T) {
		cin >> n >> m;
		rep (i, 1, n) cin >> a[i];
		rep (i, 1, n) head[i] = 0; cnt_edge = 0;

		// rep (i, 1, n) rep (j, 1, n)
		// 	if (i != j && abs(a[i] - a[j]) <= m)
		// 		add(i, j);

		for (int i = n, j = n; i >= 1; --i) {
			while (a[j] - a[i] > m) --j;
			if (C <= 6)
				per (k, j, i + 1) add(i, k), add(k, i);
			else {
				if (j > i) add(i, j), add(j, i);
				if (j - 1 > i) add(i, j - 1), add(j - 1, i);
				if (j - 2 > i) add(i, j - 2), add(j - 2, i);
			}
		}

		ll ans = 0;

		if (C <= 10 || n <= 10000) {
			rep (s, 1, n) {
				rep (i, 1, n) cnt[i] = 0;
				rep (i, 1, cnt_edge) tree[i] = false;
				bfs(s);
				for (int vw = 1; vw <= cnt_edge; ++vw) {
					int u = edges[vw].u, v = edges[vw].v;
					if (dis[v] == dis[u] + 1 && !tree[vw])
						++cnt[v];
					// if (tree[vw]) cerr << u << ',' << v << '\n';
				}
				// cerr << "log: " << s << ": "; rep (i, 1, n) cerr << cnt[i] << ' '; cerr << '\n';
				bfs(s);
				int cont = 0;
				rep (i, s + 1, n) cont += (cnt[i] == 1);
				ans += cont;
			}
		} else {
			ans = 0;
		}

		cout << ans << '\n';
	}

	return 0;
}




