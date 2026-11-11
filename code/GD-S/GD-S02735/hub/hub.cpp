#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
//	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --){
		int n, k;
		cin >> n >> k;
		vector<vector<int>> g(n);
		for(int i = 1; i < n; i ++){
			int u, v;
			cin >> u >> v;
			u --, v --;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		
		vector<vector<pair<int, int>>> maxl(n);
		vector<int> sz(n, 1);
		{
			auto dfs = [&](auto &dfs, int x, int f)->void{
				for(auto &y : g[x]) if(y != f){
					dfs(dfs, y, x);
					sz[x] += sz[y];
				}
				priority_queue<pair<int, int>> s;
				for(auto &y : g[x]) if(y != f){
					for(auto &v : maxl[y]){
						s.push({v.first, y});
					}
				}
				for(int i = 0; i < 3 && !s.empty(); i ++){
					maxl[x].emplace_back(s.top().first + 1, s.top().second);
					s.pop();
				}
				if(maxl[x].size() < 3) maxl[x].emplace_back(0, -1);
			};
			dfs(dfs, 0, 0);
		}
		
		auto qmax = [&](int x, int l, int r){
			int maxn;
			if(maxl[x][0].second != l && maxl[x][0].second != r){
				maxn = max(maxl[x][0].first, l);
			}
			else if(maxl[x][1].second != l && maxl[x][1].second != r){
				maxn = max(maxl[x][1].first, l);
			}
			else{
				maxn = max(maxl[x][2].first, l);
			}
			return maxn;
		};
		int ans = 1e9;
		auto dfs1 = [&](auto &self, auto &dfs, int x, int f, int l)->void{
			if(sz[x] < k || l >= ans) return;
			for(int i = 0; i < g[x].size(); i ++) if(g[x][i] != f) for(int j = i; j < g[x].size(); j ++) if(g[x][j] != f) {
				if(i == j){
					self(self, dfs, g[x][i], x, max(l, qmax(x, g[x][i], g[x][j])) + 1);
				}
				// debug
				cout << endl << x << ' ' << f << ' ' << l << endl;
				int maxn = max(qmax(x, g[x][i], g[x][j]), l) + 1;
				for(int ql = 1; ql < k; ql ++){
					ans = min(max({dfs(dfs, g[x][i], x, ql), maxn, dfs(dfs, g[x][j], x, ql)}), ans);
				}
			}
		};
		unordered_map<int, unordered_map<int, int>> dp;
		auto fq = [&](auto &fq, auto &dfs, int x, int f, int k, int i) -> int{
			if(g[x][i] == f) i ++;
			if(i == g[x].size()) return 0;
			int rt = 1e9;
			for(int a = 0; a <= sz[g[x][i]] && a <= k; a ++){
				int r1 = dfs(dfs, g[x][i], x, a), r2;
				r2 = fq(fq, dfs, x, f, k - a, i + 1);
				rt = min(max(r1, r2), rt);
			}
			return rt;
		};
		auto dfs2 = [&](auto &dfs, int x, int f, int k)->int{
			if(sz[x] < k) return 1e9;
			if(k == 0) return maxl[x][0].first;
			if(dp.count(x) && dp[x].count(k)) return dp[x][k];
			int rt = fq(fq, dfs, x, f, k, 0);
			dp[x][k] = rt; 
			// debug
			cout << x << ' ' << k << ' ' << rt << endl;
			return rt;
		};
		
		dfs1(dfs1, dfs2, 0, 0, 0);
		
		cout << ans << '\n';
	}
}
