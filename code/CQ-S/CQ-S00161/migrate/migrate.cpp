/*
数据结构吗

首先考虑 N^2 暴力

枚举两个点去chk吗 

先处理一个 dis 
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 2e6 + 10, M = 5e3 + 10, inf = 1e9;

void Freopen() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
}

int n;
ll d;
ll x[N];

int dis[M][M];
ll dp[M][M]; 

void solve() {
	cin >> n >> d;
	
	for ( int i = 1; i <= n; i ++) cin >> x[i];
	
	for ( int i = 1; i <= n; i ++)
		for ( int j = 1; j <= n; j ++) dis[i][j] = inf, dp[i][j] = 0;
	
	for ( int i = 1; i <= n; i ++) {
		dis[i][i] = 0;
		int ptr = i;

		for ( int j = i + 1; j <= n; j ++) {
			while (x[j] - x[ptr] > d && ptr < j) ptr ++;

			if (ptr == j) break ;
			dis[i][j] = dis[i][ptr] + 1;
		}
	} 
	
	for ( int s = 1; s <= n; s ++) {
		dp[s][s] = 1;
		
		for ( int i = s; i <= n; i ++) {
			for ( int j = i - 1; j >= s; j --) {
				if (x[i] - x[j] > d) break ;
				
				if (dis[s][j] + 1 == dis[s][i]) dp[s][i] += dp[s][j];
			}
		}
	}
	
	ll ans = 0;
	for ( int i = 1; i <= n; i ++)
		for ( int j = i + 1; j <= n; j ++)
			ans += (dp[i][j] == 2);
	
	cout << ans << '\n';
}

signed main() {
	Freopen();

	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int c, T;
	cin >> c >> T;
	
	while (T --) solve();

	return 0;
}

