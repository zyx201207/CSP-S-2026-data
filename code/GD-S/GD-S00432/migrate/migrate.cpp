#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+5;
int c, T, n, dis[N];
bool vis[N];
ll d, a[N], f[N], ans;
vector<int> G[N];
struct node {
	int u, w;
	bool operator < (const node &p) const {
		return w > p.w;
	}
}; priority_queue<node> q;
void add(int x, int y) {
	G[x].push_back(y);
	G[y].push_back(x);
}
void solve() {
	scanf("%d %lld", &n, &d), ans = 0;
	for(int i=1; i<=n; i++)
		scanf("%lld", &a[i]), G[i].clear();
	for(int i=2; i<=n; i++) {
		int pos = lower_bound(a+1, a+i, a[i]-d)-a;
		for(int j=pos; j<i; j++) add(j, i); 
	} for(int u=1; u<n; u++) {
		while(!q.empty()) q.pop();
		for(int i=u; i<=n; i++)
			dis[i] = 1e9, f[i] = vis[i] = 0;
		dis[u] = 0, q.push({u, 0}), f[u] = 1;
		while(!q.empty()) {
			int x = q.top().u; q.pop();
			if(vis[x]) continue;
			vis[x] = 1;
			for(int v : G[x]) {
				if(dis[v]==dis[x]+1)
					f[v] += f[x], q.push({v, dis[v]});
				else if(dis[v]>dis[x]+1)
					dis[v] = dis[x]+1,
					q.push({v, dis[v]}),
					f[v] = f[x];
				if(f[v]>2) f[v] = 3;
			}
		} for(int i=u+1; i<=n; i++)
			if(f[i]==2) ans++;
	} printf("%lld\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &T);
	while(T--) solve();
	return 0;
}
