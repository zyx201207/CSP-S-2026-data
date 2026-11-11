#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)1e6 + 5;
const int _N = N + 5;
vector<int> mp[_N];
int dpt[_N];
void dfs(int fa, int u) {
	for(int v : mp[u]) {
		if(v == fa) continue;
		dpt[v] = dpt[u] + 1;
		dfs(u, v);
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C, T; cin >> C >> T;
	while(T--) {
		ll n, k; cin >> n >> k;
		for(int i = 1; i <= n; i++) mp[i].clear();
		for(int i = 1; i <= n - 1; i++) {
			int u, v; cin >> u >> v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		dpt[1] = 0; dfs(1, 1);
		int ans = 0;
		for(int i = 1; i <= n; i++) ans = max(ans, dpt[i]);
		cout << ans << endl;
	}
	return 0;
} 
