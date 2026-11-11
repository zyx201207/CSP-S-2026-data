#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 500005
#define N 505
int c,n,m,d,q,w[M],k[N],dp[N][N];
vector<pair<int,int> >r[N],zn[M];
signed main(){
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,63,sizeof(dp));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1,x,y;j<=k[i];j++) scanf("%lld%lld",&x,&y),r[i].push_back(make_pair(x,y)),zn[x].push_back(make_pair(i,y));
	}
	for(int i=1;i<=n;i++) sort(r[i].begin(),r[i].end()),dp[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<zn[i].size();j++)
			for(int k=j+1;k<zn[i].size();k++)
				dp[zn[i][j].first][zn[i][k].first]=min(dp[zn[i][j].first][zn[i][k].first],zn[i][j].second+zn[i][k].second);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dp[i][j]=dp[j][i]=min(dp[i][j],dp[j][i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dp[i][j]>dp[i][k]+dp[k][j]) dp[i][j]=dp[i][k]+dp[k][j];
	for(int i=1,x,y,ans;i<=q;i++){
		scanf("%lld%lld",&x,&y),ans=LLONG_MAX;
		for(int j=0;j<zn[x].size();j++)
			for(int k=0;k<zn[y].size();k++)
				ans=min(ans,dp[zn[x][j].first][zn[y][k].first]+w[x]+w[y]+zn[x][j].second+zn[y][k].second);
		printf("%lld\n",ans);
	}
	return 0;
}
