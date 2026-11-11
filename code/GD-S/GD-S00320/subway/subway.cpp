#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#define int long long
using namespace std;
int c, n, m, d, q, w[(int)5e5 + 5], g[(int)505][(int)505], f[(int)505][(int)505];
vector<pair<int, int>> _g[(int)5e5 + 5], _f[(int)5e5 + 5];
void dij(int x){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	f[x][x] = 0;
	vector<bool> vis(505, 0);
	vis[x] = true;
	for(auto i : _f[x]){
		f[x][i.first] = i.second;
		q.push({f[x][i.first], i.first});
	}
	while(!q.empty()){
		int cur = q.top().second;
		// cout << cur << '\n';
		q.pop();
		if(vis[cur]) continue;
		vis[cur] = true;
		for(auto i : _f[cur]){
			if(f[x][cur] + i.second < f[x][i.first]){
				f[x][i.first] = f[x][cur] + i.second;
				q.push({f[x][i.first], i.first});
			}
		}
	}
	return ;
}
		
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	int mx = 0;
	memset(g, 0x3f, sizeof g);
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int x, y;
			cin >> x >> y;
			mx = max(mx, x);
			_g[x].push_back({i, y});
		}
	}
	for(int i = 1;i <= mx;i++){
		for(auto _j : _g[i]){
			for(pair<int, int> _k : _g[i]){
				int j = _j.first, k = _k.first;
				if(j == k) continue;
				g[j][k] = g[k][j] = min(g[j][k], _j.second + _k.second);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		g[i][i] = 0;
	}
	memset(f, 0x3f, sizeof f);
	//for(int k = 1;k <= n;k++){
	//	for(int i = 1;i <= n;i++){
	//		for(int j = i;j <= n;j++){
	//			if(i == j) {
	//				f[i][j][k] = 0;
	//				continue;
	//			}
	//			f[i][j][k] = f[j][i][k] = min((k - 1? f[i][j][k - 1] : 0x3f3f3f3f), min(g[i][j], (k - 1 ? f[i][k][k - 1] + f[j][k][k - 1] : 0x3f3f3f3f)));
	//		}
	//	}
	//}
	for(int i = 1;i <= n;i++){
	       for(int j = i;j <= n;j++){
			if(i == j || g[i][j] >= 0x3f3f3f3f3f3f3f3f) continue;
	 		_f[i].push_back({j, g[j][i]});
			_f[j].push_back({i, g[j][i]});
			//cout << "pb" << j << ' ' << i << ' ' << g[j][i] << '\n';
	       }
	}
	for(int i = 1;i <= n;i++){
		dij(i);
	}	
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cout << f[i][j] << ' ';
//		}
//		cout  << '\n';
//	}
	// cout << "FIII << '\n";
	while(q--){
		int s, t;
		cin >> s >> t;
		int res = 0x3f3f3f3f;
		for(auto _i : _g[s]){
			for(auto _j : _g[t]){
				int i = _i.first, j = _j.first;
				int i_ = _i.second, j_ = _j.second;
				res = min(res, i_ + j_ + f[i][j]);
			}
		}
		res += w[s] + w[t];
		cout << res << '\n';
	}
	return 0;
}
