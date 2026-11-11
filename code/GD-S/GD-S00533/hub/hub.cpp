#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5e5 + 5;
int n, k, a[MAXN], vis[MAXN], dis[MAXN];
vector<int> e[MAXN];

int fa[MAXN];
int find(int x){
	return fa[x] == x ? fa[x] : find(fa[x]);
}

void solve(){ 
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) e[i].clear();
	for(int i = 1, u, v; i <= n - 1; ++i){
		cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u); 
	}
	int ans = 1e18;
	for(int o = 0; o < (1 << n); ++o){
		if(__builtin_popcount(o) != k) continue;
		for(int i = 1; i <= n; ++i) if((o >> i - 1) & 1) a[i] = 1; else a[i] = 0;
		for(int i = 1; i <= n; ++i) fa[i] = i;
		for(int i = 1; i <= n; ++i) if(a[i]){
			for(auto x : e[i]){
				if(a[x]){
					int u = find(x), v = find(i);
					if(u == v) continue;
					fa[u] = v;
				}
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; ++i) vis[i] = 0;
		for(int i = 1; i <= n; ++i) if(a[i] && !vis[find(i)]) vis[find(i)] = 1, cnt++;
		if(cnt > 2) continue;
//		for(int i = 1; i <= n; ++i) if(a[i]) cout << i << ' '; cout << "\n"; 
		for(int i = 1; i <= n; ++i) vis[i] = 0, dis[i] = 0;
		queue<int> q;
		for(int i = 1; i <= n; ++i) if(a[i]) q.push(i), vis[i] = 1;
		while(q.size()){
			int u = q.front(); q.pop();
//			cout << u << ' ' << dis[u] << '\n';
			for(auto v : e[u]){
				if(!vis[v]) dis[v] = dis[u] + 1, vis[v] = 1, q.push(v);
			}
		}
		int res = 0;
		for(int i = 1; i <= n; ++i) res = max(res, dis[i]);
//		cout << "aaa : " << res << '\n';
 		ans = min(ans, res);
	 }  
	cout << ans << '\n';
 	
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int c, T; cin >> c >> T; while(T--) solve();

    return 0;
}
