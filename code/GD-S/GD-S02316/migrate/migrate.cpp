#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

namespace my {
	typedef long long ll;
	
	constexpr int N = 2e6 + 5;
	constexpr int MOD = 998244353;
	constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;

	typedef long long ll;
	
	ll x[N], dis[N], tim[N];
	bool vis[N];
	vector <int> g[N];

	int main() {
		#ifndef LOCAL
			freopen("migrate.in", "r", stdin);
			freopen("migrate.out", "w", stdout);
		#endif

		int C, T; scanf("%d%d", &C, &T);
		
		while (T--) {
			int n; ll d; scanf("%d%lld", &n, &d);
			
			for (int i = 1; i <= n; i++)
				scanf("%lld", &x[i]);
				
			for (int i = 1; i <= n; i++) {
				g[i].clear();
			}
				
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					if (abs(x[j] - x[i]) <= d) {
						g[i].push_back(j);
//						printf("Edge from %d to %d\n", i, j);
					}
					
			auto bfs = [&] (int s) {
				struct Node {
					int u; ll dis;
				};
				
				for (int i = 1; i <= n; i++) {
					tim[i] = 0; dis[i] = INFLL; vis[i] = false;
				}
				
				queue <Node> q;
				q.push({s, 0});
				dis[s] = 0;
				
				while (!q.empty()) {
					int u = q.front().u, now = q.front().dis; q.pop();
					
					for (int v : g[u])
						if (!vis[v]) {
							vis[v] = true;
							
							dis[v] = dis[u] + 1;
							q.push({v, dis[v]}); 
						}
				}	
				
//				puts("dis = ");
//				for (int i = 1; i <= n; i++) {
//					printf("%lld ", dis[i]);
//				}
//				putchar('\n');
				
				q.push({s, 0});
				while (!q.empty()) {
					int u = q.front().u, now = q.front().dis; q.pop();
					
					if (now > dis[u]) continue;
					if (dis[u] == now) tim[u]++;
					
					for (int v : g[u])
						q.push({v, dis[u] + 1});
				}
			};
			
			ll ans = 0;
			for (int i = 1; i <= n; i++) {
				bfs(i);
				
				for (int j = i + 1; j <= n; j++) {
					ans += tim[j] == 2;
				}
			}
			
			printf("%lld\n", ans);
		}

		#ifndef LOCAL
			fclose(stdin);
			fclose(stdout);
		#endif

		return 0;
	}
}

int main() {
	my::main();

	return 0;
}

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
