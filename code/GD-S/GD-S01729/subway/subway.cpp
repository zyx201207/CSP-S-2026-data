#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long c, n, m, d, p, T, cnt, s, e;
vector<long long> g[N];
long long a[N];
vector<bool> vis(N, 0);
void dfs(long long u){
	if (u == e) return ;
	vis[u] = 1;
	for (auto v : g[u]){
		if (!vis[v]){
			cnt++;
			dfs(v);
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> c >> n >> m >> d >> p;
	for (long long i = 1; i <= m; i++){
		cin >> a[i];
	}
	for (long long i = 1; i <= n; i++){
		long long k;
		cin >> k;
		for (long long j = 1; j <= k; j++){
			long long u;
			cin >> u >> T;
			g[u].push_back(i);
			g[i].push_back(u);
		}
	}
	while (p--){
		cin >> s >> e;
		vis.clear();
		dfs(s);
		cout << a[s] + a[e] + cnt * T << endl;
	}
	return 0;
}
