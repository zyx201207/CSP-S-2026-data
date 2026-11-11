#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

int c, t, n, d, a[2000010];
unordered_map<int, bool> mp;
bool bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, 0});
	int ans = LLONG_MAX, cnt = 0;
	while(!q.empty()) {
		int u = q.front().first, w = q.front().second; q.pop();
		mp[u] = true;
		if(u == y) {
			ans = min(ans, w);
			if(w == ans) cnt++;
			if(cnt == 3) break;
		}
		if(u >= ans) continue;
		
		for(int i = 1; i <= n; i++) {
			if(i == u || mp.count(i)) continue;
			if(abs(a[i] - a[u]) <= d) q.push({i, w + 1});
		}
	}
	if(cnt == 2) return true;
	return false;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(a[i] - a[j]) <= d) continue;
//				cout << i << j << "\n"; 
				mp.clear();
				ans += bfs(i, j);
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
} 

