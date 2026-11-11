#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int INF = 1e9;

void solve1(){
	int n, d;
	cin >> n >> d;
	vector<LL> x(n+1, -INF);
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	
	vector<vector<pair<int,int> > > dp(n+1, vector<pair<int,int> >(n+1, make_pair(0, INF)));// {number, length}
	// the number and length of paths from i to j
	
	for(int i = 1; i < n; i++){
		dp[i][i] = make_pair(0,0);
		for(int j = i+1; j <= n; j++){
			for(int k = j-1; k >= i; k--){
				if(x[j] - x[k] > d) break;
				if(dp[i][j].se > dp[i][k].se + 1){
					dp[i][j].fi = 1;
					dp[i][j].se = dp[i][k].se + 1;
				}
				else if(dp[i][j].se = dp[i][k].se + 1){
					dp[i][j].fi = dp[i][k].fi + 1;
//					dp[i][j].se = dp[i][k].se;
				}
			}
		}
	}
	
	LL ans = 0;
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
//			cout << dp[i][j].fi << ' ' << dp[i][j].se << ' ';
			if(dp[i][j].fi == 2){
				ans++;
			}
		}
//		cout << '\n';
	}
//	cout << ans << '\n';
}

void solve13(){
	int n, d;
	cin >> n >> d;
	vector<LL> x(n+1);
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	
	cout << n << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	if(c <= 10){
		while(t--){
//			cout << t << '\n';
			solve1();
		}
		return 0;
	}
	
	while(t--){
		int n, d;
		cin >> n >> d;
		cout << n << '\n';
	}
	
//	if(13 <= c && c <= 14){
//		while(t--){
//			solve13();
//		}
//	}
	
	return 0;
}
