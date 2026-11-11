#include <bits/stdc++.h>
using namespace std;
const int N=500+5,D=21,M=5e5+5;
vector<int>G[N];
int dp[M][N];
int mxcol[N],mxlin[M],cnt;int id[M][N],t[M][N],a[M][D],k[M],k2[N];
vector<int>a1,a2;
void dfs(int cnt1,int cnt2){
	for(int i=1;i<=cnt1;i++){
		for(int j=1;j<=n;j++){
			if(t[a1[i]][j]){
				dp[a1[i]][j]=min(dp[a1[i]][j],min(mxcol[j],mxlin[a1[i]])+t[a1[i]][j]);mxcol[j]=min(mxcol[j],dp[a1[i]][j]);
				mxlin[a1[i]]=min(mxlin[a1[i]],dp[a1[i]][j]);a2.push_back(j);
			}
	}}
	for(int i=1;i<=cnt2;i++){
		for(int j=1;j<=m;j++){
			if(t[j][a2[i]]){
				dp[j][a2[i]]=min(dp[j][a2[i]],min(mxcol[a2[i]],mxlin[j])+t[j][a2[i]]);mxcol[a2[i]]=min(mxcol[a2[i]],dp[j][a2[i]]);
				mxlin[j]=min(mxlin[j],dp[j][a2[i]]);a1.push_back(j);
				
			}
		}
	}
	cnt1=unique(a1.begin(),a1.end())-a1.begin(),cnt2=unique(a2.begin(),a2.end())-a2.begin();
	if(cnt1<=m||cnt2<=n)dfs();
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%d",&a[i][j]);scanf("%d",&t[i][a[i][j]]);
		}
	}
	while(q--){
		int u,v;scanf("%d%d",&u,&v);
		memset(dp,0x3f,sizeof(dp));memset(mxlin,0x3f,sizeof(mxlin));memset(mxcol,0x3f,sizeof(mxcol));
		for(int i=1;i<=m;i++){
			if(t[i][u]){dp[i][u]=t[i][u],		mxlin[u]=min(mxlin[u],dp[i][u]);a1.push_back(i);
				for(int j=1;j<=n;j++)if(j!=u&&t[i][j])dp[i][j]=t[i][j]+dp[i][u],mxcol[j]=dp[i][j];a2.push_back(j);
				}
			}
		int cnt1=unique(a1.begin(),a1.end())-a1.begin(),cnt2=unique(a2.begin(),a2.end())-a2.begin();
		if(cnt1<=m||cnt2<=n)dfs(cnt1,cnt2);
		int ans=1e9;
		for(int i=1;i<=m;i++){
			ans=min(ans,dp[i][v]);
		}
		printf("%d\n",ans+w[u]+w[v]);
	}
	
	return 0;
}
