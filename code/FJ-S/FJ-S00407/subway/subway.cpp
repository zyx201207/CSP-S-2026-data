#include<bits/stdc++.h>
#define lll long long
using namespace std;
int n,m,d,q,edgg[510][510],w[500010];
vector<pair<int,int> > ve[500010];
lll dp[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&d,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int f=1;f<=n;f++) dp[i][f]=-1;
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1,a,t,k;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&a,&t);
			for(auto f:ve[a]){
				if(dp[i][f.first]==-1) dp[i][f.first]=dp[f.first][i]=f.second+t;
				else dp[i][f.first]=dp[f.first][i]=min((lll)f.second+t,dp[i][f.first]);
			}
			ve[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][k]==-1 or dp[k][j]==-1) continue;
				else if(dp[i][j]==-1) dp[i][j]=dp[j][i]=dp[i][k]+dp[k][j];
				else dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int f=1;f<=n;f++){
			cout<<dp[i][f]<<" ";
		} cout<<endl;
	}
	*/
	int frmm,tooo;
	while(q--){
		scanf("%d%d",&frmm,&tooo);
		lll minn=-1;
		for(auto i:ve[frmm]){
			for(auto f:ve[tooo]){
				if(minn==-1) minn=dp[i.first][f.first]+i.second+f.second;
				else minn=min(minn,dp[i.first][f.first]+i.second+f.second);
				//if(minn==32) cout<<i.first<<" "<<i.second<<" "<<f.first<<" "<<f.second<<endl;
			}
		}
		printf("%lld\n",w[frmm]+w[tooo]+minn);
		//cout<<minn;
	}
	return 0;
}
