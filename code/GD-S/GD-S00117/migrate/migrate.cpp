#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const ll inf = 2e18;
const int N = 5e3 + 5;
int C, T, n;
ll d, x[N], dp[N], f[N], ans;

void init(){
	ans = 0;
}

void solve(){
	cin >> n >> d;
	init();
	
	for(int i = 1; i <= n; ++i) cin >> x[i];
	
	for(int u = 1; u <= n; ++u){
//		cout << u << ":{\n";
		memset(dp, 0, sizeof dp);
		memset(f, 0, sizeof f);
		f[u] = 1;
		for(int v = u + 1; v <= n; ++v){
			ll cg = x[v] - d;
			int k = lower_bound(x + u, x + v, cg) - x;
//			cout << "cg:" << k << "->" << v << '\n';
			dp[v] = inf;
			if(k == v) continue;
			ll cnt = 0;
			for(int i = k; i < v; ++i){
				if(dp[i] + 1 < dp[v]) dp[v] = dp[i] + 1, cnt = f[i];
				else if(dp[i] + 1 == dp[v]) cnt += f[i];
//				cout << i << "->" << v << ':' << dp[v] << ' ' << f[i] << '\n';
			}
			if(cnt == 2) ++ans;
			f[v] = cnt;
//			cout << v << ':' << dp[v] << ' ' << f[v] << '\n';
		}
//		cout << "}\n";
	}
	
	cout << ans << '\n';
	
//	cout << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> C >> T;
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 3
-2 -1 0 1 2

0 1
6 2
-4 -3 -2 -1 3 6
*/
