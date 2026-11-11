#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6 + 5;
int n, k, c, dis[MAXN];
bool vis[MAXN], f[MAXN];
vector<int> g[MAXN];
inline void dfs(int x, int fa) {
	dis[x] = dis[fa] + 1;
	for(auto v : g[x]) {
		if(v == fa) continue;
		dfs(v, x);
	}
}
inline bool check(int x) {
	memset(f, 0, sizeof(f));
	int res = 0;
	for(int i = x; i <= n; i += 2 * x + 1) {
		f[i] = 1;
		res ++;
	}
	if(f[n] != 1) res ++;
	return res <= k;
}
inline void solve() {
	cin >> n >> k;
	int ans = 1e18;
	for(int i = 1; i <= n; i ++) g[i].clear();
	for(int i = 1, u, v; i < n; i ++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(c >= 13 && c <= 14) {
		int l = 0, r = n;
		while(l < r) {
			int mid = (l + r) / 2;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << '\n';
		return;
	}
	for(int i = 1; i < (1ll << n); i ++) {
		int res = 0;
		for(int j = 1; j <= n; j ++) {
			if(i & (1ll << (j - 1))) res ++;
		}
		if(res != k) continue;
		int cnt = 0;
		for(int j = 1; j <= n; j ++) {
			if(i & (1ll << (j - 1))) {
				cnt ++;
				for(auto v : g[j]) {
					if(vis[v]) cnt --;
				}
				vis[j] = 1;
			}
			else vis[j] = 0;
		}
		if(cnt > 2) continue;
		int s = 0;
		for(int j = 1; j <= n; j ++) {
			dis[0] = -1;
			dfs(j, 0);
			int tot = 1e18;
			for(int k = 1; k <= n; k ++) {
				if(vis[k]) tot = min(tot, dis[k]);
			}
			s = max(s, tot);
		}
		ans = min(ans, s);
	}
	cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> c >> T;
	while(T --) solve();
	return 0;
}
