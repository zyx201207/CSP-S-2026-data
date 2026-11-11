#include <bits/stdc++.h>
using namespace std;
int ans[15][15],minlen[15][15];
vector<long long> e[15];
void dfs(int u, vector<pair<int,int>> fas) {
	for(auto i :fas) {
		if(i.second == minlen[u][i.first]) {
			ans[u][i.first] ++;
		}
		i.second ++;
	}
	fas.push_back({u,1});
	for (auto j : e[u]) {
		dfs(j, fas);
	}
	fas.pop_back();
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) {
		if(c <= 2) {
			memset(ans, 0, sizeof(ans));
			int n,d;
			cin >> n >> d;
			for(int i = 1;i <= n;i ++) {
				e[i].clear();
			}
			vector<long long> x(n + 10);
			for(int i = 1;i <= n;i ++) {
				cin >> x[i];
			}
			for (int i = 1;i <= n;i ++) {
				for (int j = i + 1;j <= n;j ++) {
					if (x[j] - x[i] <= d) {
						e[j].push_back(i);
					}
				}
				cout << endl;
			}
			for(int i = 1;i <= n;i ++) {
				queue<int> q;
				vector<bool> vis(n);
				q.push(i);
				int d = 1;
				while(!q.empty()) {
					int u = q.front();
					q.pop();
					for(auto v:e[u]) {
						if(!vis[v]) {
							minlen[u][v] = d;
							q.push(v);
						}
					}
					d++;
				}
			}
			for(int i = 1;i <= n;i ++) {
				dfs(i, {});
			}
			int anss = 0;
			for (int i = 1;i <= n;i ++) {
				for (int j = 1;j <= n;j ++) {
					if(ans[i][j]) {
						anss ++;
					}
				}
			}
			cout << anss;
		}
	}
}
