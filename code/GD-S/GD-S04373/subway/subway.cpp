#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> w;
ll e[505][500005];
ll dis[505][505];
vector<pair<ll, ll>> g[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	w.resize(m + 1);
	for(int i = 1; i <= m; m++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		ll k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			ll a, t;
			cin >> a >> t;
			g[a].push_back({i, a});
			e[i][a] = t;
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int k = n + 1; k <= n + m; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(e[k][i] + e[k][j], dis[i][j]);
			}
		}
	}
	while(q--){
		ll x, y;
		cin >> x >> y;
		ll mi = 1ll << 62;
		for(auto i : g[x]){
			for(auto j : g[y]){
				mi = min(mi, dis[i.first][j.first] + i.second + j.second);
			}
		}
		cout << w[x] + w[y] + mi;
	}
	return 0;
}
//代码因
//--------------------------------
//Failed to execute "D:\GD-S04373\subway\subway.exe":
//Error 0: 操作成功完成。
//我是蒟蒻有没有人知道为什么(fccf是个回文串) 
//请按任意键继续. . .
//无法运行
