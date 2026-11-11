#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;

int c, n, m, d, q, w[N], a[505][N], t[505][N], k[505], cnt[N], root, sum[N], f[N][N];
bool flagA = 1;
vector<pair<int, int> > g[N];

void dfs(int u, int fa){
	for(int i = 0 ; i < g[u].size() ; i ++){
		int v = g[u][i].first;
		if(v == fa) continue;
		sum[v] = sum[u] + g[u][i].second;
		dfs(v, u);
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++) cin >> w[i];
	for(int i = 1 ; i <= n ; i ++){
		cin >> k[i];
		if(k[i] > 2) flagA = 0;
		for(int j = 1 ; j <= k[i] ; j ++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	if(flagA){
		for(int i = 1 ; i <= n ; i ++){
			g[a[i][1]].push_back({a[i][2], t[i][1] + t[i][2]});
			g[a[i][2]].push_back({a[i][1], t[i][1] + t[i][2]});
			cnt[a[i][1]] ++;
			cnt[a[i][2]] ++;
		}
		for(int i = 1 ; i <= m ; i ++){
			if(cnt[i] == 1){
				root = i;
				break;
			}
		}
		dfs(root, 0);
		for(int i = 1 ; i <= q ; i ++){
			int x, y;
			cin >> x >> y;
			if(sum[x] > sum[y]) swap(x, y);
			cout << w[x] + w[y] + sum[y] - sum[x] << '\n';
		}
	}
	else{
		memset(f, 0x3f, sizeof(f));
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= k[i] ; j ++){
				for(int l = 1 ; l <= k[i] ; l ++){
					if(j == l) continue;
					int x = a[i][j], y = a[i][l];
					f[x][y] = min(f[x][y], t[i][j] + t[i][l]);
				}
			}
		}
		for(int k = 1 ; k <= m ; k ++){
			for(int i = 1 ; i <= m ; i ++){
				for(int j = 1 ; j <= m ; j ++){
					if(i == j) continue;
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
					
				}
			}
		}
		for(int i = 1 ; i <= q ; i ++){
			int x, y;
			cin >> x >> y;
			cout << w[x] + w[y] + f[x][y] << '\n';
		}
	}
	return 0;
}
//¾ÍÏñÊÇ 
