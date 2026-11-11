#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e2 + 10;
const int M = 5e5 + 10;
const ll INF = 1e18;
ll dis[N][N];
int c, n, m, d, q;
int w[M];
vector<pii> vec[M];
inline int rd(){
	int x = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
	return x;
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	c = rd();
	n = rd();
	m = rd();
	d = rd();
	q = rd();
	for(int i = 1; i <= m; i++) w[i] = rd();
	for(int i = 1; i <= n; i++){
		int x;
		x = rd();
		for(int y, z, j = 1; j <= x; j++){
			y = rd(), z = rd();
			vec[y].push_back({i, z});
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		if(vec[i].size() <= 1) continue;
		for(int j = 0; j < vec[i].size(); j++){
			for(int k = 0; k < vec[i].size(); k++){
				dis[vec[i][j].fi][vec[i][k].fi] = min(dis[vec[i][j].fi][vec[i][k].fi], (ll)vec[i][k].se + vec[i][j].se);
			}
		}
	} 
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cout << i << " " << j << " " << dis[i][j] << endl;
//		}
//	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int x, y;
		x = rd();
		y = rd();
		ll ans = INF;
		for(auto v1 : vec[x]){
			for(auto v2 : vec[y]){
				ans = min(ans, dis[v1.fi][v2.fi] + v1.se + v2.se);
			}
		}
		ans += w[x] + w[y];
		cout << ans << endl;
	}
}
