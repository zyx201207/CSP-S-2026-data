#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5, M = 5e5 + 5, D = 25;

struct pt {
	int n;
	long long t;
};

int c, n, m, d, q;
long long f[N][N], a[M];
vector<pt> g[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q ;
	
	for(int i = 1;i <= m;i++) cin >> a[i] ;
	for(int i = 1;i <= n;i++) {
		int k;
		cin >> k ;
		while(k--) {
			int c;
			long long t;
			cin >> c >> t ;
			g[c].push_back({i, t});
		}
	}
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) f[i][j] = LONG_LONG_MAX;
		f[i][i] = 0;
	}
	
	for(int i = 1;i <= m;i++) {
		for(int j = 0;j < g[i].size();j++) {
			for(int k = j;k < g[i].size();k++) {
//				if(i == 2) cout <<  << ' '<<<<' '<< g[i][j].t << ' '<<g[i][k].t<<endl ;
				int u = g[i][j].n, v = g[i][k].n;
				f[u][v] = f[v][u] = min(f[v][u], g[i][j].t + g[i][k].t);
			}
		}
	}

	for(int k = 1;k <= n;k++) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				if(f[i][k] == LONG_LONG_MAX || f[k][j] == LONG_LONG_MAX) continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	while(q--) {
		int x, y;
		long long ans = LONG_LONG_MAX;
		cin >> x >> y ;
		for(int i = 0;i < g[x].size();i++) {
			for(int j = 0;j < g[y].size();j++) {
				int u = g[x][i].n, v = g[y][j].n;
				long long t = a[x] + a[y] + g[x][i].t + g[y][j].t;
				ans = min(ans, f[u][v] + t);
			}
		}
		cout << ans << endl ;
	}
	
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
