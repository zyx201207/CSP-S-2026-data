#include <bits/stdc++.h>

using namespace std;

using ll = long long; using ull = unsigned long long;
#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)

bool mST;

namespace Main {

	const int N = 2e6 + 5;
	int n;
	ll D;
	ll X[N];
	int fa[N];
	
	ll f[N], g[N];

	namespace WT{
		int main() {
			
			ll ans = 0;
			REP(i, 1, n) {
				memset(f, 0x3f, sizeof(f));
				f[i] = 0, g[i] = 1;
				REP(k, i, n) {
					REP(j, k, fa[k]) {
						if(f[j] > f[k] + 1) f[j] = f[k] + 1, g[j] = g[k];
						else if(f[j] == f[k] + 1) g[j] += g[k];
					}
					if(g[k] == 2) {
						ans++;
						// cout << i << ' ' << k << '\n';
					}
				}
				// if(i == 1) cerr << g[8] << '\n';
			}
			cout << ans << '\n';
			return 0;
		}
	}
	namespace SS2{
		int main() {
			ll ans = 0;
			REP(i, 1, n) {
				int x = i;
				bool flag = 0, aba = 0;
				int Z = 0;
				for(; x != fa[x]; x = fa[x], Z = fa[Z]) {
					int y = fa[x];
					int w = max(0, fa[y - 1] - (y - 2 >= x ? fa[y - 2] : y));
					if(flag) {
						w = max(0, fa[y] - fa[y - 1]);
					}
					if(fa[y] == fa[Z] || (fa[y] - 1 == fa[Z] && (!flag || aba))) w = 0;
					ans += w;
					if(fa[y - 1] == fa[y] && fa[y - 2] != fa[y]) {
						if(flag) break;
						flag = 1, aba = 1;
					}
					if(fa[y - 1] == fa[y] && fa[y - 2] == fa[y]) break;
					if(fa[y - 1] == fa[y] - 1) {
						if(!Z) aba = 0;
						Z = y - 1;
					}
					else if(fa[y - 1] != fa[y]) {
						Z = 0;
					}
				}
			}
			cout << ans << '\n';
			return 0;
		}
	}
	int cid;

	vector<int> G[N];
	ll ans;
	ll s1[N], s2[N];
	bool Z[N];


	void dfs(int u, int prt) {
		s1[u] = 1;
		for(int &v: G[u]) {
			dfs(v, u);
			s1[u] += s1[v];
			s2[u] += s2[v];
		}
		if(u != prt) {
			int x = u, y = fa[x];

			ll w1 = max(0, fa[y - 1] - (y - 2 >= x ? fa[y - 2] : y));
			ll w2 = max(0, fa[y] - fa[y - 1]);
			for(auto&v: G[u])
				if(!Z[v])
					ans += w1 * s1[v];
			ans += w1;
			ans += w2 * s2[u];
			if(fa[y - 1] == fa[y] && fa[y - 2] == fa[y]) s1[u] = s2[u] = 0;
			if(fa[y - 1] == fa[y] && fa[y - 2] != fa[y]) {
				s2[u] = s1[u], s1[u] = 0;
				// if(flag) break;
				// flag = 1;
			}
			if(fa[y - 1] == fa[y] - 1) {
				Z[u] = 1;
			}
			else Z[u] = 0;
		}
	}
	int sn;
	void Solve() {
		cin >> n >> D;
		REP(i,1 , n) cin >> X[i];
		for(int i = n, j = n + 1; i >= 1; --i) {
			while(j > i && X[j - 1] - X[i] > D) j--;
			fa[i] = j - 1;
		}
		if(sn + n <= 300){sn +=n; WT::main();return;}
		if(sn + n <= 5000){sn += n; SS2::main();return;}
		REP(i, 1, n) if(fa[i] != i) G[fa[i]].push_back(i);
		ans = 0;
		REP(i, 1, n) {
			if(fa[i] == i) {
				dfs(i, i);
			}
		}
		cout << ans << '\n';

		REP(i, 1, n) G[i].clear(), s1[i] = s2[i] = 0, Z[i] = 0;
	}
	int main() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		int cases;
		cin >> cid >> cases;
		while(cases--) Solve();
		return 0; 
	}
}

bool mED;

int main() {
#ifndef Ace
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("migrate.err", "w", stderr);
#endif
	Main::main();
	
	cerr << fixed << setprecision(3) << "Time:" << 1. * clock() / CLOCKS_PER_SEC << "s" << '\n';
	cerr << "static Memory: " << abs(&mST - &mED) / 1048576. << "mb" << '\n'; 
	return 0;
} 
/*
1s 1024M


*/