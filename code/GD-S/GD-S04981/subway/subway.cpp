#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, ll>;
const int M = 5e5 + 5, N = 505;
ll w[M];
ll f[N][N];
ll c, n, m, d, q;// 测试，线路，站台，mx 出边，询问 
vector<pii> rt[N], dt[M];
// 线路到厅，厅到线路 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	map<pii, ll> mp;// 厅 i 与 j 线路的最短连线 
	for(int i = 1;i <= n;i++){
		int k; cin>>k;
		while(k--){
			ll x, v; cin>>x>>v;
			// 厅，值 
			rt[i].pb({x, v});
			if(!mp[{x, i}]) mp[{x, i}] = v;
			else mp[{x, i}] = min(mp[{x, i}], v);
			
			dt[x].pb({i, v});
		}
	}
//	cout<<"alkjdshflaksdjhfalks\n";
//	for(int i = 1;i <= m;i++){
//		for(int j = 1;j <= n;j++) cout<<mp[{i, j}]<<" \n"[j == n]; 
//	}
	
	memset(f, 0x3f, sizeof f);
	for(int i = 1;i <= n;i++){
		for(auto t : rt[i]){
			ll x = t.first, v = t.second;
//			cout<<i<<" "<<x<<" sdifghlad\n";
			// 厅、权值 
			for(auto t0 : dt[x]){
				int j = t0.first, v0 = t0.second;
				f[i][j] = min(f[i][j], 1ll * v + v0);
			}
		}
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++) cout<<f[i][j]<<" \n"[j == n];
//	}
	
	// 线路之间的最短距离 
	for(int i = 1;i <= n;i++) f[i][i] = 0;
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	while(q--){
		int u, v; cin>>u>>v;
		ll res = LLONG_MAX;
		for(auto x : dt[u]){
			for(auto y : dt[v]){
				res = min(res, w[u] + w[v] + x.second + y.second + f[x.first][y.first]);
			}
		}
		cout<<res<<'\n';
	}
}

