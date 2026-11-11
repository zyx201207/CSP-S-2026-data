#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define per(i,a,b) for(int i = (a);i >= (b);i--)

using namespace std;

typedef long long ll;

inline ll read(){
	static ll x,ch;
	x = 0;
	ch = getchar();
	while(ch < 48 || ch > 57) ch = getchar();
	while(48 <= ch && ch <= 57){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}

const int N = 513;
const int M = 500005;
const ll INF = 4e18;

inline void smi(ll &x,ll y){
	x = min(x,y);
}

int n,m,d,q;

int gc[M];
int g1[M][23];
ll g2[M][23];

ll tw[M];
ll dp[N][N];

inline void solve(){
	n = read(),m = read(),d = read(),q = read();
	rep(i,0,n) rep(j,0,n) dp[i][j] = INF;
	rep(i,0,n) dp[i][i] = 0;
	rep(i,1,m) tw[i] = read();
	{
		int k,a;
		ll t;
		rep(i,1,n){
			k = read();
			rep(j,1,k){
				a = read(),t = read();
				gc[a]++;
				g1[a][gc[a]] = i;
				g2[a][gc[a]] = t;
			}
		}
	}
	{
		int u,v;
		ll w;
		rep(i,1,m){
			for(int j = 1;j <= gc[i];j++){
				for(int k = j + 1;k <= gc[i];k++){
					if(j == k) continue;
					u = g1[i][j],v = g1[i][k];
					w = g2[i][j] + g2[i][k];
					smi(dp[u][v],w);
					dp[v][u] = dp[u][v];
				}
			}
		}
	}
	rep(k,1,n) rep(i,1,n){
		if(dp[i][k] == INF) continue;
		rep(j,1,n){
			if(dp[k][j] == INF) continue;
			smi(dp[i][j],dp[i][k] + dp[k][j]);
		}
	}
	ll ans;
	int x,y;
	while(q--){
		x = read(),y = read();
		ans = INF;
		for(int j = 1;j <= gc[x];j++){
			for(int k = 1;k <= gc[y];k++){
				smi(ans,g2[x][j] + g2[y][k] + dp[g1[x][j]][g1[y][k]]);
			}
		}
		printf("%lld\n",ans + tw[x] + tw[y]);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	c = read();
	solve(); 
	return 0;
}

