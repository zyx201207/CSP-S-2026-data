#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
const int N = 5e5 + 5;
const int M = 505;
const int D = 22;

int w[N];
int t[N][D];

long long f[M][M];
using pi = pair<int, int>;
#define fi first
#define sc second
vector<pi> v[N];

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin.tie(0) -> sync_with_stdio(false);
	
	memset(f, 0x3f, sizeof(f));//? 
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)   cin >> w[i];
	
	for(int i = 1;i <= n;i ++){
		f[i][i] = 0; 
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			int qwq, wqw;
			cin >> qwq >> wqw;
			v[qwq].push_back({i, wqw});
		}
	}
	
	for(int i = 1;i <= m;i ++){
		int sz = v[i].size();
		for(int j = 0;j < sz;j ++){
			for(int r = j + 1; r < sz; r ++){
				int y1 = v[i][j].fi, y2 = v[i][r].fi;
				long long tal = v[i][j].sc + v[i][r].sc;
				f[y1][y2] = min(f[y1][y2], tal);
				f[y2][y1] = f[y1][y2];
			}
		}
	}
	
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	while(q --){
		int x, y;
		cin >> x >> y;
		int szx = v[x].size(), szy = v[y].size();
		long long ans = LLONG_MAX; 
		for(int i = 0;i < szx;i ++){
			for(int j = 0;j < szy;j ++){
				long long tal = v[x][i].sc + v[y][j].sc;
				int y1 = v[x][i].fi, y2 = v[y][j].fi;
				ans = min(ans, 1ll * w[x] + w[y] + tal + f[y1][y2]);
			}
		}
		cout << ans << "\n";
	}
	
//	cerr << clock() << " ms";
}

