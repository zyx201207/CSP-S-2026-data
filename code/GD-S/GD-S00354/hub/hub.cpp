#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (b); i >= (int)(a); --i)
using LL = long long;
using Pii = pair<int, int>;
#define fst first
#define snd second
#define pb push_back

namespace gdb7
{
	vector<int> G[1000010];
	bool bd[105], mk[105];
	int dis[105][105];
	int n, k, ans;
	void mark(int u, int fa) {
		mk[u] = true;
		for (auto v: G[u]) {
			if (v == fa || !bd[v]) {
				continue;
			}
			mark(v, u);
		}
	}
	void dfs(int id, int bdcnt) {
		if (bdcnt > k) return ;
		if (id == n + 1) {
			if (bdcnt != k) return ; 
			memset(mk, 0, sizeof(mk));
			int res = 0, cnt = 0;
			rep (i, 1, n) {
				if (!mk[i] && bd[i]) {
					++cnt;
					if (cnt > 2) {
						return ;
					}
					mark(i, 0);
				}
			}
//			rep (i, 1, n) {
//				cout << bd[i] << " \n"[i == n];
//			}
			rep (i, 1, n) {
				if (bd[i]) continue;
				int tmp = n + 1;
//				cout << i << ":" << endl;
				rep (j, 1, n) {
					if (!bd[j]) continue;
//					cout << "\t" << j << ": " << dis[i][j] << endl;
					tmp = min(tmp, dis[i][j]);
				}
//				cout << i << "\'s tmp: " << tmp << endl;
				res = max(res, tmp);
			}
			ans = min(ans, res);
			return ;
		}
		bd[id] = true;
		dfs(id + 1, bdcnt + 1);
		bd[id] = false;
		dfs(id + 1, bdcnt);
	}
	signed main(void) {
		freopen("hub.in", "r", stdin);
		freopen("hub.out", "w", stdout);
		int c, t;
		scanf("%d%d", &c, &t);
		while (t--) {
			scanf("%d%d", &n, &k);
			rep (i, 1, n) {
				G[i].clear();
			}
			memset(dis, 0x3f, sizeof(dis));
			rep (i, 1, n - 1) {
				int u, v;
				scanf("%d%d", &u, &v);
				G[u].pb(v);
				G[v].pb(u);
				dis[u][v] = dis[v][u] = 1;
			}
			rep (k, 1, n) {
				rep (i, 1, n) {
					rep (j, 1, n) {
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
			ans = n + 1;
			dfs(1, 0);
			printf("%d\n", ans);
		}
		return 0;
	}
};

signed main()
{
	return gdb7::main();
}

