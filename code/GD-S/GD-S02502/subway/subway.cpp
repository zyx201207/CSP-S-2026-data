#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, t, x, y, a[500009];
long long w[500009], mi = 1e18, ans;
vector<pair<int, int>> g[500009]; 
bool vis[509];
void dfs(int now, int end) {
	if(now == end) {
		mi = min(mi, ans);
		return;
	}
	for(auto i : g[now]) {
		if(vis[i.first] == 0) {
			ans += i.second;
			vis[i.first] = 1;
			dfs(i.first, end);
			ans -= i.second;
			vis[i.first] = 0;
		}
	}
}
int main (  ) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a[j] >> t;
			for(int l = 1; l < j; l++) {
				g[a[l]].push_back({a[j], t});
				g[a[j]].push_back({a[l], t});
			}
		}
	}
	while(q--) {
		cin >> x >> y;
		ans = w[x] + w[y];
		dfs(x, y);
		cout << mi << '\n';
	}
	return 0;
}
