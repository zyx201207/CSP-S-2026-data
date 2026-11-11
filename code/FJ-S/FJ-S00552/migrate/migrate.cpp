#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;

int c, t;
ll n, d, num;
ll a[N], dp[5005][5005];

void dfs(int s, int e, int w, int m){
	if(w == e && m == dp[s][e]){
		num++;
		return;
	}
	if(m >= dp[s][e]) return;
	for(int i = w + 1; i <= e; i++){
		if(a[i] - a[w] <= d){
			dfs(s, e, i, m + 1);
		}
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		memset(dp, 0x3f, sizeof(dp));
		memset(a, 0, sizeof(a));
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			for(int j = 1; j < i; j++){
				if(a[i] - a[j] <= d){
					dp[i][j] = dp[j][i] = 1;
				}
			}
		}
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(dp[i][j] == 0x3f3f3f3f || dp[i][j] == 1) continue;
				num = 0;
				dfs(i, j, i, 0);
				if(num == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
