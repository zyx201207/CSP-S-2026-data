#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, d, x[10005], vis[10005], f[10005];
vector<int> g[10005];
int q[10005], l, r;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T; cin >> c >> T;
	while(T--){
		cin >> n >> d;
		int max = 1e18, mn = 1e18;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
			g[i].clear();
		}
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(x[j]-x[i] <= d){
					g[i].push_back(j);
				}
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++) vis[j] = f[j] = 0;
			q[l = r = 1] = i; vis[i] = f[i] = 1;
			while(l <= r){
				int u = q[l++];
				f[u] = min(f[u], 3ll);
				for(auto v:g[u]) if(!vis[v]){
					vis[v] = vis[u]+1;
					q[++r] = v;
					f[v] = f[u];
				} else if(vis[v] == vis[u]+1){
					f[v] += f[u];
				}
			}
			for(int j = i; j <= n; j++){
				if(f[j] == 2){
					// cout << i << " " << j << '\n';
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
/*
debuged for 2.5h and found my solution is wrong.

//freopen()
//freopen()

*/