#include<bits/stdc++.h>
using namespace std;
const int N=507,M=5e5+7;
long long dp[N][N],ww[M];
void floyd(long long n){
	long long i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
vector<pair<long long,long long> > g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,k,d,q,u,v,w,i,j,ans=0;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++){
		scanf("%lld",&ww[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&k);
		for(j=1;j<=k;j++){
			scanf("%lld%lld",&u,&w);
			g[u].push_back({i,w});
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dp[i][j]=0x3f3f3f3f;
			if(i==j) dp[i][j]=0;
		}
	}
	for(u=1;u<=m;u++){
		for(auto it:g[u]){
			for(auto jt:g[u]){
				i=it.first;
				j=jt.first;
				dp[i][j]=min(dp[i][j],it.second+jt.second);
			}
		}
	}
	floyd(n);
	while(q--){
		ans=0x3f3f3f3f;
		scanf("%lld%lld",&u,&v);
		for(auto it:g[u]){
			for(auto jt:g[v]){
				i=it.first;
				j=jt.first;
				ans=min(ans,dp[i][j]+it.second+jt.second);
			}
		}
		printf("%lld\n",ans+ww[u]+ww[v]);
	}
	return 0;
}

