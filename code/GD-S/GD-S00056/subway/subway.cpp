#include<bits/stdc++.h>
using namespace std;
const int N = 507, M = 5e5+7;
int c, n, m, d, q;
int w[M];
struct uct{
	int x;
	long long y;
};
basic_string<uct> g[M];
long long dis[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k, x, y;
		cin >> k;
		while(k--) cin >> x >> y, g[x] += (uct){i, y};
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= m; i++){
		for(uct x : g[i]){
			for(uct y : g[i]){
				if(x.x == y.x) continue;
				dis[x.x][y.x] = dis[y.x][x.x] = min(dis[x.x][y.x], x.y+y.y);
			}
		}
	}
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int j = 1; j <= n; j++){
		for(int i = 1; i <= n; i++){
			for(int k = i; k <= n; k++){
				dis[i][k] = dis[k][i] = min(dis[i][k], dis[i][j]+dis[j][k]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		long long ans = dis[0][0];
		for(uct u : g[x]){
			for(uct v : g[y]) ans = min(ans, dis[u.x][v.x]+u.y+v.y);
		}
		cout << ans+w[x]+w[y] << '\n';
	}
	return 0;
} 
