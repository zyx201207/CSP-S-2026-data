#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxd = 15e5;
int dp[maxd];
int c, n, m, d, q, x, y;
struct T{
	int v, e;
};
vector <T>g[maxd];
void dfs(int x){
	for(auto v : g[x]){
		if(dp[v.v] == -1 || dp[x] + v.e < dp[v.v]){
			dp[v.v] = dp[x] + v.e;
			dfs(v.v);
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		g[i].push_back({i + m, x});
		g[i + m].push_back({i, x});
	}
	int nowx = 2 * m + 1;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int l;
		for(int j = 1; j <= x; j++){
			int a, t;
			cin >> a >> t;
			g[a + m].push_back({nowx, t});
			g[nowx].push_back({a + m, t});
			if(j >= 2){
				g[nowx].push_back({l, 0});
				g[l].push_back({nowx, 0});
			}
			l = nowx;
			nowx++;
		}
	}
	while(q--){
		memset(dp, -1, sizeof(dp));
		cin >> x >> y;
		dp[x] = 0;
		dfs(x);
		cout << dp[y] << endl;
	}
	return 0;
}
