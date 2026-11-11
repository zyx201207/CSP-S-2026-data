/**********************
 ~AUTHOR BY "ILWF^_^" 
 ~author by "ILWF^_^" 
**********************/
#include<bits/stdc++.h>
#define LM LLONG_MAX
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 500005 , M = 505;
const ll mod = 1e9 + 7;
const ll INF = 1e18;
ll w[N] , dp[M][M];
vector<pair<ll,ll>> g[N];
ll c , n , m , d , q;
void floyd(){
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
			}
		}
	}
}
void solve(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		ll k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			ll a , t;
			cin >> a >> t;
			g[a].push_back({i , t}); 
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j) dp[i][j] = 0;
			else dp[i][j] = INF;
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < (ll)g[i].size();j++){
			for(int k = j + 1;k < (ll)g[i].size();k++){
				ll val = g[i][j].second + g[i][k].second;
				dp[g[i][j].first][g[i][k].first] = min(dp[g[i][j].first][g[i][k].first] , val);
				dp[g[i][k].first][g[i][j].first] = min(dp[g[i][k].first][g[i][j].first] , val);
			}
		}
	}
	floyd();
	while(q--){
		ll x , y;
		cin >> x >> y;
		ll res = INF;
		for(int i = 0;i < (ll)g[x].size();i++){
			for(int j = 0;j < (ll)g[y].size();j++){
				res = min(res , g[x][i].second + g[y][j].second + dp[g[x][i].first][g[y][j].first]);
			}
		}
		cout << res + w[x] + w[y] << '\n'; 
	}
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	ILW F; 
}
