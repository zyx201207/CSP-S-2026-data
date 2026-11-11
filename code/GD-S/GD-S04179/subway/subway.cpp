#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;
int w[N], dis[1005][1005];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			dis[m + i][a] = t;
			dis[a][m + i] = t; 
		}
	}
	
	for(int k = 1; k <= m + n; k++){
		for(int i = 1; i <= m + n; i++){
			for(int j = i + 1; j <= m + n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		}
	}
	
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << dis[u][v] + w[u] + w[v] << '\n';
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
