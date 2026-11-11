#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int INF = 0x3f3f3f3f;
ll c, n, m, d, q;
ll dis[5005][5005];
ll sta[5005];
ll maps[505][500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	memset(maps, 0x3f, sizeof(maps));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		ll w;
		cin >> w;
		sta[i] = w;
		dis[i][i] = 0; 
	}
	for(int i = 1; i <= n; i++){
		ll k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			maps[i][a] = t;
		}
	}
	for(int p = 1; p <= n; p++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				dis[i][j] = min(dis[i][j], maps[p][i] + maps[p][j]);
			}
		}	
	}
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
			}
		}
	}	
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + sta[x] + sta[y] << endl; 
	}
	return 0;
}

