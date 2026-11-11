#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;

int c,n,m,d,q;
int dp[MAXN][MAXN],w[MAXN],t[MAXN];

pair <int,int> p;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp,0x3f,sizeof dp);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1;i <= n + m;i++) dp[i][i] = 0;
	
	if(d == 2) {//d == 2抢分 (9-11) 复杂度(n) ^ 3 
		for(int i = 1;i <= m;++i) cin >> w[i];
		for(int i = 1;i <= n;i++) {
			int k;
			cin >> k;
			int u,x,v,y;
			cin >> u >> x >> v >> y;
			dp[u][v] = min(dp[u][v],x + y),dp[v][u] = min(dp[v][u],x + y);
		}
		for(int k = 1;k <= n;k++) {
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[j][k]);
				}
			}
		}
		for(int i = 1;i <= q;i++) {
			int u,v;
			cin >> u >> v;
			cout << dp[u][v] + w[u] + w[v] << '\n';
		} return 0;
	} 
	
	//Floyd抢分 复杂度 (n + m) ^ 3 
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++) {
			int v,w;
			cin >> v >> w;
			dp[m + i][v] = min(dp[m + i][v],w),dp[v][m + i] = min(dp[v][m + i],w);
		}
	}
	
	for(int k = 1;k <= n + m;k++) {
		for(int i = 1;i <= m + n;i++) {
			for(int j = 1;j <= m + n;j++) {
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[j][k]);
			}
		}
	}
	
	for(int i = 1;i <= q;i++) {
		int u,v;
		cin >> u >> v;
		cout << dp[u][v] + w[u] + w[v] << '\n';
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

