#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
long long p[maxn], dis[maxn], f[maxn], vis[maxn];
vector<int> g[maxn];
int c, t;
queue<int> q;
void solve() {
	long long n, m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++) cin >> p[i], g[i].clear();
		for (int i = 1 ; i <= n ; i ++) {
			for (int j = 1 ; j <= n ; j ++) if (abs(p[i] - p[j]) <= m && (i != j)) {
				g[i].push_back(j);
			}
		}
		long long ans = 0;
		for (int i = 1 ; i <= n ; i ++) {
			for (int j = 1 ; j <= n ; j ++) dis[j] = 1e17 , f[j] = 0;
			dis[i] = 0;
			f[i] = 1;
			q.push(i);
			while (q.size()) {
				auto top = q.front(); q.pop();
				int u = top;
				for (auto v : g[u]) {
					if (dis[v] == dis[u] + 1) f[v] ++;
					if (dis[v] > dis[u] + 1) {
						dis[v] = dis[u] + 1;
						q.push(v);
						f[v] = f[u];
					}
				}
			} 
			for (int j = 1 ; j <= n ; j ++) {
				ans += (f[j] == 2);
			}
		}
		cout << (ans >> 1) << '\n';
}
int main(){
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0); 
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	while (t --) solve();
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/
