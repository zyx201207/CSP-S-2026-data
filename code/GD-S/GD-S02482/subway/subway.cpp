#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d,e,x,y,t,q,w[500005],dp[505][505],ans;
struct ff{
	int n,t;
};
vector <ff> v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &a, &b, &d, &q);
	for(int i = 1; i <= b; i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= a; i++){
		scanf("%lld", &e);
		for(int j = 1; j <= e; j++){
			scanf("%lld%lld", &x, &y);
			v[x].push_back({i,y});
		}
	}
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= a; j++){
			dp[i][j] = 1e18;
		}
		dp[i][i] = 0;
	}
	for(int i = 1; i <= b; i++){
		for(int j = 0; j < v[i].size(); j++){
			for(int k = 0; k < v[i].size(); k++){
				dp[v[i][j].n][v[i][k].n] = min(dp[v[i][j].n][v[i][k].n],v[i][j].t + v[i][k].t);
			}
		}
	}
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= a; j++){
			for(int k = 1; k <= a; k++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 1; i <= q; i++){
		scanf("%lld%lld", &x, &y);
		ans = 1e18;
		for(int j = 0; j < v[x].size(); j++){
			for(int k = 0; k < v[y].size(); k++){
				ans = min(ans,v[x][j].t + v[y][k].t + dp[v[x][j].n][v[y][k].n]);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
} 
