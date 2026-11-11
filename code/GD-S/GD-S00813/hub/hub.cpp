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

constexpr int maxn = 105;

int C, T, n, k;
vector<int> V[maxn];

int fa[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

signed main() {
#ifdef OJ
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
#else
	freopen("hub2.in", "r", stdin);
	freopen("hub2.out", "w", stdout);
#endif

	cin >> C >> T;
	rep (idt, 1, T) {
		cin >> n >> k;
		rep (i, 1, n) V[i].clear();
		rep (i, 2, n) {
			int u, v;
			cin >> u >> v;
			V[u].push_back(v);
			V[v].push_back(u);
		}

		int ans = n;
		for (int st = 1; st < (1 << n); ++st) {
			if (__builtin_popcount(st) != k) continue;
			int cnt = 0;
			rep (i, 1, n) fa[i] = i;
			rep (u, 1, n) for (int v : V[u]) if ((st >> u - 1 & 1) && (st >> v - 1 & 1)) merge(u, v);
			rep (i, 1, n) if (find(i) == i && (st >> i - 1 & 1)) ++cnt;
			if (cnt > 2) continue;
			int mx = 0;
			rep (i, 1, n) {
				queue<int> que;
				vector<int> dis(n + 1, 0);
				que.push(i); dis[i] = 1;
				int r = n;
				while (!que.empty()) {
					int u = que.front(); que.pop();
					if (st >> u - 1 & 1) {
						r = dis[u] - 1;
						break;
					}
					for (int v : V[u]) if (!dis[v]) dis[v] = dis[u] + 1, que.push(v);
				}
				mx = max(mx, r);
			}
			ans = min(ans, mx);
		}
		cout << ans << '\n';
	}

	return 0;
}
