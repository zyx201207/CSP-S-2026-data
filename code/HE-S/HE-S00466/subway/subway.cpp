#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int rd(){
	char ch; int zjjg = 0;
	while(ch = getchar()){
		if(ch == ' ' || ch == '\n') break;
		zjjg = zjjg * 10 + ch - '0';
	}return zjjg;
}
const int N = 5e5 + 10;
int c , n , m , d , p , w[N] , dp[510][510] , sj[N][30];
vector <int> zt[N];

signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	c = rd() , n = rd() , m = rd() , d = rd() , p = rd();
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			dp[i][j] = pow(2 , 60);
	for(int i = 1 ; i <= n ; i++) dp[i][i] = 0;
	for(int i = 1 ; i <= m ; i++) w[i] = rd();
	for(int i = 1 ; i <= n ; i++){
		int k = rd();
		for(int j = 1 , x , y ; j <= k ; j++){
			x = rd() , y = rd();
			zt[x].push_back(i);
			sj[x][zt[x].size() - 1] = y;
		}
	}for(int i = 1 ; i <= m ; i++)
		for(int j = 0 ; j < zt[i].size() ; j++)
			for(int k = 0 ; k < zt[i].size() ; k++){
				if(j == k) continue;
				int u = zt[i][j] , v = zt[i][k];
				dp[u][v] = dp[v][u] = sj[i][j] + sj[i][k];
			}
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			for(int k = 1 ; k <= n ; k++)
				if(k != i && k != j && i != j)
					dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
	for(int i = 1 , x , y ; i <= p ; i++){
		x = rd() , y = rd();
		int ans = 10e18;
		for(int j = 0 ; j < zt[x].size() ; j++)
			for(int k = 0 ; k < zt[y].size() ; k++){
				int u = zt[x][j] , v = zt[y][k];
				ans = min(ans , sj[x][j] + sj[y][k] + dp[u][v]);
			}
		ans += w[x] + w[y];
		cout << ans << endl;
	}
	return 0;
}
 
