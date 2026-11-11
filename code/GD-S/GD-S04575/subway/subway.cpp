#include<bits/stdc++.h>
#define mmin(a,b) ((a)>(b))?(b):(a)
 #define mmax(a,b) ((a)<(b))?(b):(a)
using namespace std;
typedef long long ll;
const ll N = 505 , M = 5e5 + 5 , INF = LONG_LONG_MAX;
ll n , m , d , q , w[M] , dp[N][N];
vector<ll> sw[M] , swt[M];
int main(){
	
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	cin >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			dp[i][j] = INF;
	for(int i = 1;i <= n;i++) dp[i][i] = 0;
	ll k , a , t;
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a >> t;
			for(int g = 0;g < sw[a].size();g++){
				ll w = sw[a][g] , ti = swt[a][g];
				dp[i][w] = dp[w][i] = mmin(dp[w][i] , ti+t);
			}
			sw[a].push_back(i);
			swt[a].push_back(t);
		}
	}
	for(k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(dp[i][k] != INF && dp[k][j] != INF)
					dp[i][j] = mmin(dp[i][j] , dp[i][k]+dp[k][j]);
//	for(int i = 1;i <= n;i++,cout<<endl)
//		for(int j = 1;j <= n;j++)
//			cout << dp[i][j] << ' ';
	ll x , y , ans;
	while(q--){
		ans = INF;
		cin >> x >> y;
		for(int i = 0;i < sw[x].size();i++){
			ll wx = sw[x][i] , tx = swt[x][i];
			for(int j = 0;j < sw[y].size();j++){
				ll wy = sw[y][j] , ty = swt[y][j];
				if(dp[wx][wy] == INF) continue;
				ans = mmin(ans , dp[wx][wy]+tx+ty);
			}
		}
		ans += w[x] + w[y];
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
