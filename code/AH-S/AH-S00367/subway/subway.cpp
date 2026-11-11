#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX=1000000000000000000;
LL c,n,m,d,q,w[500005],k,a,t,dp[505][505],x,y,ans;
vector<pair<LL,LL> > g[500005];
int main(void) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(LL i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(LL i=1;i<=n;++i) {
		for(LL j=1;j<=n;++j) dp[i][j]=MAX;
		dp[i][i]=0;
	}
	for(LL i=1;i<=n;++i) {
		scanf("%lld",&k);
		while(k--) {
			scanf("%lld%lld",&a,&t);
			for(pair<LL,LL> p:g[a]) {
				dp[i][p.first]=min(p.second+t,dp[i][p.first]);
				dp[p.first][i]=min(p.second+t,dp[p.first][i]);
			}
			g[a].push_back({i,t});
		}
	}
	for(LL r=1;r<=n;++r)
		for(LL i=1;i<=n;++i)
			for(LL j=1;j<=n;++j)
				if(dp[i][r]!=MAX&&dp[r][j]!=MAX&&dp[i][j]>dp[i][r]+dp[r][j]) dp[i][j]=dp[i][r]+dp[r][j];
	while(q--) {
		scanf("%lld%lld",&x,&y),ans=MAX;
		for(pair<LL,LL> p:g[x])
			for(pair<LL,LL> P:g[y]) ans=min(ans,w[x]+w[y]+dp[p.first][P.first]+p.second+P.second);
		printf("%lld\n",ans);
	}
	return 0;
}
