#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> > t[500010];
long long a[500010];
long long dp[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;++i){
		dp[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;++j){
			int x,y;
			scanf("%lld%lld",&x,&y);
			t[x].push_back({i,y});
		}
	}
	
	for(int i=1;i<=m;++i){
		for(int j=0;j<(long long)t[i].size();++j){
			for(int k=j+1;k<(long long)t[i].size();++k){
				dp[t[i][j].first][t[i][k].first]=min(dp[t[i][j].first][t[i][k].first],t[i][j].second+t[i][k].second);
				dp[t[i][k].first][t[i][j].first]=dp[t[i][j].first][t[i][k].first];
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dp[i][k]==0x3f3f3f3f3f3f3f3f||dp[k][j]==0x3f3f3f3f3f3f3f3f){
					continue;
				}
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int l,r;
		scanf("%lld%lld",&l,&r);
		long long ans=3e18;
		for(int i=0;i<(long long)t[l].size();++i){
			for(int j=0;j<(long long)t[r].size();++j){
				ans=min(ans,dp[t[l][i].first][t[r][j].first]+t[l][i].second+t[r][j].second);
			}
		}
		ans+=a[l];
		ans+=a[r];
		printf("%lld\n",ans);
	}
	return 0;
} 
