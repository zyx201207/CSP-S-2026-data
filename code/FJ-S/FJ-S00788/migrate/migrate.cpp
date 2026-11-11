#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6 + 5;
int n, d, C, a[MAXN], rr[MAXN], f[MAXN], dis[MAXN], cnt[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];
inline void bfs(int x) {
	priority_queue<pair<int, int>> q;
	for(int i = 1; i <= n; i ++) dis[i] = 1e18, vis[i] = 0, cnt[i] = 0;
	cnt[x] = 1; dis[x] = 0; q.push({0, x});
	while(q.size()) {
		int x = q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(auto v : g[x]) {
			if(dis[v] > dis[x] + 1) {
				cnt[v] = cnt[x];
				dis[v] = dis[x] + 1;
				q.push({-dis[v], v});
			}
			else if(dis[v] == dis[x] + 1) cnt[v] += cnt[x];
		}
	}
}
inline void solve() {
	cin >> n >> d;
	int ans = 0;
	for(int i = 1; i <= n; i ++) rr[i] = i, f[i] = 0;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n <= 5000) {
		for(int i = 1; i <= n; i ++) g[i].clear();
		int r = 1;
		for(int l = 1; l <= n; l ++) {
			while(a[r + 1] - a[l] <= d && r < n) r ++;
			for(int j = l + 1; j <= r; j ++) g[l].push_back(j);
		}
		for(int i = 1; i <= n; i ++) {
			bfs(i);
			for(int j = i + 1; j <= n; j ++) {
				if(cnt[j] == 2) ans ++;
			}
		}
		cout << ans << '\n';
		return;
	}
	else if(C >= 11 && C <= 12) {
		int r = 1, cnt = 0; a[n + 1] = 4e18;
		for(int l = 1; l <= n; l ++) {
			while(a[r + 1] - a[l] <= d) r ++;
			rr[l] = r;
			if(!cnt) cnt = r - l;
		}
		for(int i = 1; i <= n; i ++) {
			if(i + cnt + cnt - 1 <= n) ans ++;
		}
		cout << ans << '\n';
		return;
	}
	int r = 1; a[n + 1] = 4e18;
	for(int l = 1; l <= n; l ++) {
		while(a[r + 1] - a[l] <= d) r ++;
		rr[l] = r;
	}
	for(int i = n; i; i --) {
		if(a[n] - a[i] > d) {
			int L = rr[i], R = rr[rr[i]];
			while(L < R) {
				int mid = (L + R + 1) / 2;
				if(a[mid] > a[rr[i] - 1] + d) R = mid - 1;
				else L = mid;
			}
			if(L != rr[i] && a[L] > a[rr[i] - 2] + d) ans += rr[rr[i]] - L + 1;
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> C >> T; while(T --) solve();
	return 0;
}
