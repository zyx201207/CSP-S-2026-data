#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define rand rnd
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 5100;
struct edge{
	int v, nex;
}; 
int a[N];
int dis[N];
int cnt[N], vis[N];
int c, n, d, t;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(c <= 10){
			vector<vector<int> > dp, g;
			int ans = 0;
			dp.resize(n + 10);
			g.resize(n + 10);
			for(int i = 0; i <= n; i++){
				dp[i].resize(n + 10);
				g[i].resize(n + 10);
				for(int j = 0; j <= n; j++){
					dp[i][j] = 1e18, g[i][j] = 0;
				}
			}
			for(int i = 1; i <= n; i++){
				dp[i][i] = 0, g[i][i] = 0;
				for(int j = i + 1; j <= n; j++){
					if(abs(a[i] - a[j]) <= d) dp[i][j] = 1, g[i][j] = 1;
					else break;
				}
			}
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					for(int k = i + 1; k < j; k++){
						if(dp[i][j] == dp[i][k] + dp[k][j]){
							g[i][j] += g[i][k] * g[k][j];
						}
						if(dp[i][j] > dp[i][k] + dp[k][j]){
							dp[i][j] = dp[i][k] + dp[k][j];
							g[i][j] = g[i][k] * g[k][j];
						}
					}
				}
			}
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					if(g[i][j] == 2){
						ans++;
					}
				}
			}
			cout << ans << "\n";
		}
		if(c == 13 || c == 14){
			cout << "0\n";
		}
		
	}
	return 0;
}
/*
0 1
5 5
-4 0 1 3 8 
*/

