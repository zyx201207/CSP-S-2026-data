/*
Luogu: 1412168

you ji:

hyw
CCF gei ge mian zi ba *

you mei you ren yi qi wan ARCAEA, Phigros, BlueArchive, anqu, suanjiaozhou, ***game
                                                        huang you lao zheng e xin ^

Happy Hellowen!(wan sheng jie shi zhe me da de ma???)
*/

#include <bits/stdc++.h>
//#define int long long
using namespace std;
int c, t, n, k;
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> k;
		vector<vector<int>> p(n + 1);
		vector<pair<int, int>> edges;
		for(int i = 1, u, v; i < n; ++ i) {
			cin >> u >> v;
			p[u].push_back(v);
			p[v].push_back(u);
		}
		if(k == n) {
			cout << "0\n";
			continue;
		}
		if(k >= n - 2) {
			cout << "1\n";
			continue;
		}
		int ans = n - k;
		vector<int> sdps;
		auto dfs = [&](int x, int tot, auto&& dfs) -> void {
			if(tot == k) {
				queue<pair<int, int>> q;
				vector<int> dis(n + 1, -1);
				for(int p : sdps) {
					q.emplace(p, 0);
					dis[p] = 0;
				}
				vector<bool> _vis(n + 1, false);
				auto dfs2 = [&](int x, int fa, auto&& dfs2) -> void {
					if(_vis[x]) return;
					_vis[x] = true;
					for(int nxt : p[x]) {
						if(dis[nxt]) continue;
						if(nxt == fa) continue;
						dfs2(nxt, x, dfs2);
					}
				};
				int tmp = 0;
				for(int x : sdps) {
					if(!_vis[x]) {
						++ tmp;
						if(tmp > 2) return;
						dfs2(x, 0, dfs2);
					}
				}
				tmp = 0;
				while(q.size()) {
					int nw = q.front().first;
					q.pop();
					for(int v : p[nw]) {
						if(dis[v] == -1)
							dis[v] = dis[nw] + 1, tmp = max(tmp, dis[v]), q.emplace(v, dis[v]);
					}
				}
				ans = min(ans, tmp);
//				for(int x : sdps) {
//					cout << x << ' ';
//				}
//				cout << ':' << tmp << '\n';
				return;
			}
			if(x > n) {
				return;
			}
			if(n - x + 1 + tot < k) return;
			dfs(x + 1, tot, dfs);
			sdps.push_back(x);
			dfs(x + 1, tot + 1, dfs);
			sdps.pop_back();
		};
		dfs(1, 0, dfs);
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
// while(1) RP++;
