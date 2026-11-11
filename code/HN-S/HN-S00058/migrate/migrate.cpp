#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 50000 + 5; 
int c, t;
int n, d;
int ans;
int a[N];
queue<pair<int, int> > q;
int vis[N], mn[N];;
void solve(int st) {
	memset(vis, 0, sizeof(vis));
	memset(mn, 60, sizeof(mn));
	q.push({st, 0});
	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		int u = p.first;
		int cnt = p.second;
		for(int i = u + 1; i <= n; i++) {
			if(a[i] - a[u] > d)
				break;
			if(cnt + 1 > mn[i])
				continue;
			q.push({i, cnt + 1});
			if(cnt + 1 == mn[i]) {
				vis[i]++;
				if(vis[i] == 2)	
					ans++;
				if(vis[i] == 3)
					ans--;
			}
			if(cnt + 1 < mn[i]) {
				mn[i] = cnt + 1;
				if(vis[i] == 2)
					ans--;
				vis[i] = 1;
			}
		}
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++)	
			cin >> a[i];
		ans = 0; 
		for(int i = 1; i <= n; i++)
			solve(i);
		cout << ans << "\n";
	}
	return 0;
}
