//24pts
#include<bits/stdc++.h>
bool Mst;
#define ll long long
using namespace std;
const int N = 2e6 + 10;
int c, T, n;
ll d, a[N];
//#1~#6
const int N6 = 310;
ll dp[N6][N6], sum[N6][N6];

bool Med;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cerr << "Memory is " << abs(&Med - &Mst) / 1024.0 / 1024 << "MB.\n";
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		
		if(c <= 6){
			ll ans = 0;
			for(int s = 1; s <= n; ++s){
				for(int i = 1; i <= n; ++i){
					for(int j = 0; j <= n; ++j) dp[i][j] = sum[i][j] = 0;
				}
				dp[s][0] = sum[s][0] = 1;
				for(int i = s + 1; i <= n; ++i) sum[i][0] += sum[i - 1][0];
//				cerr << "The Start is " << s << '\n';
				for(int i = s + 1; i <= n; ++i){
					int m = n + 1;
					for(int j = 1; j <= n; ++j){
						dp[i][j] = 0;
						int k;
						for(k = i - 1; a[i] - a[k] <= d && k >= s; --k){
							dp[i][j] += dp[k][j - 1];
						}
						int pos = lower_bound(a + s, a + i, a[i] - d) - a;
						if(pos >= s && pos < i){
//							if(k != pos - 1) cerr << i << ' ' << j << ' ' << pos << '\n';
							dp[i][j] = sum[i - 1][j - 1] - sum[pos - 1][j - 1];
						}
						sum[i][j] = sum[i - 1][j] + dp[i][j];
//						cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
						if(dp[i][j]) m = min(m, j);
					}
					if(m <= n) ans += dp[i][m] == 2;
				}
			}
			cout << ans << '\n';
			continue;
		}
		//情况不太乐观，本来打算1h写T3T4 暴力的，现在只调出来了T3的暴力
		//刚刚看了一眼T4疑似极其复杂，暴力估计也难写，冷静冷静，先回去把T2完善了，争取A掉 
		
	}
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
