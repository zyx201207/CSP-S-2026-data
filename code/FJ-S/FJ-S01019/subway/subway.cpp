#include<bits/stdc++.h>
#define st first
#define nd second
#define int long long
using namespace std;

//bool memory_start;

const int N = 505, M = 5e5+5;

int cid, n, m, d, q;

int w[M], k[N], f[N][N];

vector<pair<int, int>> e[M];

//bool memory_end;

signed main(){
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> cid >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++) cin >> w[i];
	
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int A, T;
			cin >> A >> T;
			e[A].push_back({i, T});
		}
	}
	
	memset(f, 0x3f, sizeof(f));
	
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	
	for(int i = 1; i <= m; i++){
		int len = e[i].size();//len <= 20
		for(int u = 0; u < len; u++){
			for(int v = u + 1; v < len; v++){
				int x = e[i][u].st, y = e[i][v].st;
				f[x][y] = f[y][x] = min(f[x][y], e[i][u].nd + e[i][v].nd);
			}
		}
	}
	
	for(int K = 1; K <= n; K++){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				f[i][j] = f[j][i] = min(f[i][j], f[i][K] + f[K][j]);
			}
		}
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for(auto ed : e[x]){
			int u = ed.st, wu = ed.nd;
			for(auto edg : e[y]){
				int v = edg.st, wv = edg.nd;
				ans = min(ans, wu + wv + f[u][v]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	
	//cerr << (&memory_start - &memory_end) / 8 / 1024 / 1024 << '\n';
	
	return 0;
}
