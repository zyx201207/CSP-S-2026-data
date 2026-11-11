#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
const int M = 2e5 + 5;
const int INF = -1e18;
const int mods[21] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
int n, m, a[M];
int dp[N][N];
bool flaga = 1, flagb = 1;
bool check(int x){
	for(int i = 0;i <= 20;i++){
		if(x+1 == mods[i]) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if(!check(n)) flagb = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(!check(a[i])) flaga = 0;
		if(a[i] != i-1) flagb = 0;
	}
	if(m == 1){
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0;
	}else if(flaga){
		sort(a + 1, a + n + 1);
		cout << a[n-m+1];
		return 0;
	}else if(flagb){
		int maxans = 1;
		for(int i = n-1;i >= 1;i--){
			if((i >> (m-1)) < 0) break;
			maxans = max(maxans, (i >> (m-1)));
		}
		cout << maxans;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 2;j <= m;j++){
			dp[i][j] = INF;
		}
	}
	dp[1][1] = a[1];
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if(j == 1){
				dp[i][j] = max({dp[i][j], dp[i-1][j], a[i]});
				continue;
			}
			dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i-1][j-1]&a[i]});
		}
	}
	cout << dp[n][m];
	return 0;
}
