#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 550;
const int M = 5e5+50;
int c, n, m, mx, q, w[M], k[N], a[N][N];
int cnt[M], d[M][25], id[M][25];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> mx >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int x, y;
			cin >> x >> y;
			id[x][++cnt[x]] = i;
			d[x][cnt[x]] = y;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) a[i][j] = 0;
			else a[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= m; i++){ // 500000
		for(int t1 = 1; t1 <= cnt[i]; t1++){ // 20
			for(int t2 = t1+1; t2 <= cnt[i]; t2++){ // 20
				a[id[i][t1]][id[i][t2]] = min(a[id[i][t1]][id[i][t2]], d[i][t1]+d[i][t2]);
				a[id[i][t2]][id[i][t1]] = min(a[id[i][t2]][id[i][t1]], d[i][t1]+d[i][t2]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int u = 1; u <= n; u++){
			if(i == u) continue;
			for(int v = 1; v <= n; v++){
				if(i == v || u == v) continue;
				a[u][v] = min(a[u][v], a[u][i]+a[i][v]);
			}
		}
	}
	while(q--){
		int x, y, res = 1e18;
		cin >> x >> y;
		for(int i = 1; i <= cnt[x]; i++){
			for(int j = 1; j <= cnt[y]; j++){
				res = min(res, a[id[x][i]][id[y][j]]+d[x][i]+d[y][j]);
			}
		}
		res += w[x]+w[y];
		cout << res << '\n';
	}
	return 0;
}