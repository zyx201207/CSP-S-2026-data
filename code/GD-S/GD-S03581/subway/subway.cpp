#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int M = 5e2 + 10;
int w[N], k[M];
int sum[N][21];
int fl[M][M];
int c, n, m, d, q;
vector<int> g[N];
signed main(){
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			int a, t;
			cin >> a >> t;
			g[a].push_back(i);
			sum[a][g[a].size() - 1] = t;
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			fl[i][j] = 4e18;
		}
	}
	for(int i = 1; i <= n; i ++) fl[i][i] = 0;
	for(int i = 1; i <= m; i ++){
		int len = g[i].size();
		for(int j = 0; j < len - 1; j ++){
			for(int k = j + 1; k < len; k ++){
				fl[g[i][j]][g[i][k]] = fl[g[i][k]][g[i][j]] = min(fl[g[i][j]][g[i][k]], sum[i][k] + sum[i][j]);
			}
		}
	}
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				fl[i][j] = min(fl[i][j], fl[i][k] + fl[k][j]);
			}
		} 
	}
	while(q--){
		int st, ed;
		cin >> st >> ed;
		int ans = 9e18;
		int lens = g[st].size(), lene = g[ed].size();
		int mini, minj;
		for(int i = 0; i < lens; i ++){
			for(int j = 0; j < lene; j ++){
				int cs = g[st][i], ct = g[ed][j];
				if(fl[cs][ct] < ans){
					ans = fl[cs][ct];
					mini = i, minj = j;
				}
			}
		}
		int pp = ans + w[st] + w[ed] + sum[st][mini] + sum[ed][minj];
		printf("%lld\n", pp);
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

