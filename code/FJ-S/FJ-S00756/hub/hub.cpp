// 15
// 17:00 START!
#include <bits/stdc++.h>
using namespace std;
#define int ll
using ll = long long; using pi = pair<int, int>;
#define Fr(i, s, t) for (int i(s); i <= (t); ++i)
#define Bk(i, t, s) for (int i(t); i >= (s); --i)
inline int rd() {
	int x(0), f(1), c; while ((c = getchar()) < 48 || c > 57) f = c ^ 45;
	do x = x * 10 + (c & 15); while ((c = getchar()) > 47 && c < 58); return f ? x : -x;
}
namespace _1 {
	constexpr int N = 4010;
	int n, k, vis[N]; vector<int> e[N];
	int S, dis[N][N], D[N];
	inline void dfs(int u, int fa) {
		vis[u] = 1;
		for (int v : e[u]) if (v != fa && ((S>>v) & 1)) dfs(v, u);
	}
	inline void dfs2(int u, int fa, int rt) {
		if (fa) dis[rt][u] = dis[rt][fa] + 1;
		for (int v : e[u]) if (v != fa) dfs2(v, u, rt);
	}
	inline void Main() {
		n = rd(), k = rd();
		Fr(i, 1, n) e[i].clear(), vis[i] = 0, dis[i][i] = 0; 
		Fr(i, 1, n) Fr(j, 1, n) dis[i][j] = 0; 
		Fr(i, 2, n) {
			int u = rd(), v = rd();
			e[u].emplace_back(v), e[v].emplace_back(u);
		}
		int ans = 1e18;
		Fr(_, 0, (1 << n) - 1) {
			S = _ << 1;
			if (__builtin_popcount(S) != k) continue;
			int cnt = 0, res = 0;
			Fr(i, 1, n) vis[i] = 0;
			Fr(i, 1, n) if (!vis[i] && ((S>>i) & 1)) dfs(i, 0), ++cnt;
			if (cnt > 2 || !cnt) continue;
			Fr(i, 1, n) dfs2(i, 0, i);
			Fr(i, 1, n) {
				D[i] = 1e18;
				Fr(j, 1, n) if ((S>> j) & 1) D[i] = min(D[i], dis[i][j]);
				res = max(res, D[i]);
			}
			ans = min(ans, res);
		} 
		cout << ans << '\n';
	}
}
signed main() {
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	int c = rd();
	Bk(T, rd(), 1) _1::Main();
}

