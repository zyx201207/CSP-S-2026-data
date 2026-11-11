#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4009;
int ID, T, n, K;
vector<int> g[N];
int dp[N][N][3], d[N], mxd[N], tmp[5];
void dfs(int u, int _fa, int dep){
	d[u] = dep, mxd[u] = 1;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v == _fa) continue;
		dfs(v, u, dep+1);
		mxd[u] = max(mxd[u], mxd[v]+1);
	}
}
int lim;
void dfs1(int u, int _fa){
	if(mxd[u] <= lim){
		dp[u][d[u] + mxd[u] - 1][0] = 0;
	}
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v == _fa) continue;
		dfs1(v, u);
	}
	for(int j = d[u]; j <= min(d[u]+mxd[u]-1, d[u]+lim-1); j++){
		tmp[0] = 0, tmp[1] = n, tmp[2] = n;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if(v == _fa) continue;
			tmp[2] = min(min(min(n, tmp[2]+dp[v][j][0]), tmp[1]+dp[v][j][1]), tmp[0]+dp[v][j][2]);
			tmp[1] = min(min(n, tmp[1]+dp[v][j][0]), tmp[0]+dp[v][j][1]);
			tmp[0] = min(n, tmp[0]+dp[v][j][0]);
		}
		dp[u][j][0] = min(dp[u][j][0], tmp[0]);
		dp[u][j][1] = min(dp[u][j][1], tmp[1]);
		dp[u][j][2] = min(dp[u][j][2], tmp[2]);
	}
	tmp[1] = tmp[2] = 1;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v == _fa) continue;
		int tp = dp[v][d[u]][1], tp1 = dp[v][d[u]][2];
		for(int j = d[u]+1; j <= n; j++){
			tp = min(tp, dp[v][j][0]);
			tp1 = min(tp1, dp[v][j][1]);
		}
		tmp[2] = min(min(n, tmp[2]+tp), tmp[1]+tp1);
		tmp[1] = min(n, tmp[1]+tp); 
	}
	dp[u][d[u]-1][1] = min(dp[u][d[u]-1][1], tmp[1]);
	dp[u][d[u]-1][2] = min(dp[u][d[u]-1][2], tmp[2]);
	for(int i = d[u]; i <= n; i++){
		dp[u][i][0] = min(dp[u][i][0], dp[u][i-1][0]);
		dp[u][i][1] = min(dp[u][i][1], dp[u][i-1][1]);
		dp[u][i][2] = min(dp[u][i][2], dp[u][i-1][2]);
	}
}
bool chk(){
	dfs1(1, 0);
	for(int i = 0; i <= n; i++){
		if(dp[1][i][2] <= K || dp[1][i][1] <= K || dp[1][i][0] <= K){
			return true;
		} 
	}
	return false;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> ID >> T;
	while(T--){
		cin >> n >> K;
		for(int i = 1; i <= n; i++){
			g[i].clear();
			d[i] = mxd[i] = 0;
		}
		for(int i = 1, u, v; i < n; i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0, 1);
		int l = 0, r = n, res = n;
		while(l <= r){
			lim = (l+r)/2;
			for(int i = 1; i <= n; i++){
				for(int j = 0; j <= n; j++){
					dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = n;
				}
			}
			if(chk()){
				res = lim;
				r = lim-1;
			}else{
				l = lim+1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
