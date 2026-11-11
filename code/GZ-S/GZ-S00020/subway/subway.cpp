//GZ-S00020 郑淇予 贵阳市第一中学
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ll long long
using namespace std;
const int N = 505, M = 500005;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll dp[N][N], w[M];
//8*5e2*5e2 = 2e6 = 2MB
//8*5e5 = 4e6 = 4MB

struct Edge{
	int to, next, w;
}e[M];
int head[M], cnt;
//4*4*5e5 = 8e6 = 8MB

void addd(int x, int y, int w){
	e[++cnt] = {y, head[x], w};
	head[x] = cnt;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	FOR(i, 1, m){
		scanf("%lld", &w[i]);
	}
	FOR(i, 1, n){
		int k;
		scanf("%d", &k);
		FOR(j, 1, k){
			int a, t;
			scanf("%d%d", &a, &t);
			addd(a, i, t);
		}
	}
	memset(dp, '?', sizeof(dp));
	FOR(i, 1, n)dp[i][i] = 0;
	FOR(j, 1, m){
		vector<pair<int, int> > link;
		for(int i = head[j]; i; i = e[i].next){
			int l = e[i].to;
			for(auto nd : link){
				int r = nd.first, w = nd.second;
				dp[l][r] = min(dp[l][r], 1ll*e[i].w+w);
			}
			if(e[i].next)link.push_back({l, e[i].w});
		}
	}
	FOR(k, 1, n){
		FOR(i, 1, n){
			FOR(j, i, n){
				dp[j][i] = dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				//if(k == n)cout << k << '#' << i << '#' << j << ' ' << dp[k][i][j] << endl;
			}
		}
	}
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = INF;
		for(int i = head[x]; i; i = e[i].next){
			int l = e[i].to, wl = e[i].w ;
			for(int j = head[y]; j; j = e[j].next){
				int r = e[j].to, wr = e[j].w;
				ans = min(ans, 1ll*w[x]+w[y]+wl+wr+dp[l][r]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
