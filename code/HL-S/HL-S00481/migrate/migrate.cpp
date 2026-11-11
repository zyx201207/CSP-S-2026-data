#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c, T, n, d, a[N];
int dis[N], cnt[N];
void sol_baoli () {
	cin >> n >> d;
	for (int i=1; i<=n; ++i) cin >> a[i];
	vector<int> e[n+5];
	for (int i=1; i<=n; ++i) {
		for (int j=i+1; j<=n; ++j) {
			if (a[j]-a[i]<=d) 
				e[i].push_back(j),
				e[j].push_back(i);
		}
	}
	int ans=0;
	for (int i=1; i<=n; ++i) {
		queue<int> q; q.push(i);
		for (int j=1; j<=n; ++j) 
			dis[j]=-1, cnt[j]=0;
		dis[i]=0; cnt[i]=1;
		while (q.size()) {
			int u=q.front(); q.pop();
			for (int v:e[u]) {
				if (dis[v]==-1) dis[v]=dis[u]+1, q.push(v);
				if (dis[v]==dis[u]+1) cnt[v]+=cnt[u];
			}
		}
		for (int j=i+1; j<=n; ++j)
			if (cnt[j]==2) ans++;
	}
	cout << ans << '\n';
}
signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> T; 
	while (T--) { 
		sol_baoli();
	}
	return 0;
}