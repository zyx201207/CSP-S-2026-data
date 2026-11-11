#include<bits/stdc++.h>

#define int long long

using namespace std;

int c; // 测试点编号 25
int n; // 地铁线路数 500
int m; // 地铁站数 5e5
int d; // 每个地铁站最多被几条线路经过 20
int q; // 出行计划数 1e5
int w[500005];
// 从第 i个地铁站的地铁口走到站厅需要的时间 

struct node{
	int id;
	int tm;
};
vector<node> T[500005];
int f[505][505];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>> c;
	cin>> n >> m >> d;
	cin>> q;
	
	for(int i = 1; i <= m; i++){
		cin>> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin>> k;
		for(int j = 1; j <= k; j++){
			int a, t;
			cin>> a >> t;
			T[a].push_back({i, t});
		}
	}
	
	// 1: 500 k[i]
	memset(f, 0x3f3f, sizeof(f));
	for(int i = 1; i <= n; i++){
		f[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		int g = T[i].size();
		for(int j = 0; j < g; j++){
			int uj = T[i][j].id;
			int wj = T[i][j].tm;
			for(int k = 0; k < g; k++){
				int uk = T[i][k].id;
				int wk = T[i][k].tm;
				if(uj != uk){
					f[uj][uk] = min(f[uj][uk], wj + wk);
					f[uk][uj] = f[uj][uk];
				}
			}
		}
	}
	
	
	// 2: f[i][j]
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
			}
		}
	}
	
	// 3: xr(i) + f[i][j] +yr(j)
	for(int i = 1; i <= q; i++){
		int x, y;
		cin>> x >> y;
		int ans = LONG_LONG_MAX;
		for(int j = 0; j < T[x].size(); j++){
			for(int k = 0; k < T[y].size(); k++){
				int jto = T[x][j].id;
				int jt  = T[x][j].tm;
				int kto = T[y][k].id;
				int kt  = T[y][k].tm;
				ans = min(ans, f[jto][kto] + jt + kt);
			}
		}
		cout<< ans + w[x] + w[y] << "\n";
	}
	
	return 0;
}

