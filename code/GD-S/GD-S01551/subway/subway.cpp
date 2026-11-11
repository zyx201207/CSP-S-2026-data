#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,q,S,T;
int w[5000005],t[5005][25],k[5005],dp[5005],a[5005][25],zzx;
struct node{
	int a,b;
};
int mp2[5005][5005];
vector<int>G[25][5005],xian[5005];
void dfs(int u,int zz,int fa){
	for(int i=0;i<G[zz][u].size();i++){
		int j=G[zz][u][i];
		if(j!=fa){
			if(dp[j]>dp[u]){
				dfs(j,zz,u);
				dp[j]=dp[u];
				if(j==T){
					zzx=xian[u][i];
				}
			}
		}
	}
	for(int i=0;i<xian[u].size();i++){
		for(int j=0;j<G[xian[u][i]][u].size();j++){
			if(xian[u][i]==zz){
				continue;
			}
			int v=G[xian[u][i]][u][j];
			if(v!=fa){
				int yy;
				if(dp[v]>dp[u]+mp2[zz][u]+mp2[xian[u][i]][u]){
					dp[v]=dp[u]+mp2[zz][u]+mp2[xian[u][i]][u];
					dfs(v,xian[u][i],u);
					if(v==T){
						zzx=xian[u][i];
					}
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>a[i][j]>>mp2[i][a[i][j]];
			xian[a[i][j]].push_back(i);
		}
		for(int j=1;j<=k[i];j++){
			for(int K=1;K<=k[i];K++){
				if(i!=j)continue;
				G[i][a[i][j]].push_back(a[i][K]);
			}
		}
	}
	while(q--){
		int ans=1e18;
		cin>>S>>T;
		for(int i=0;i<xian[S].size();i++){
			for(int ii=1;ii<=n;ii++){
				dp[ii]=1e18;
			}
			int j=xian[S][i];
			dp[S]=0;
			dfs(S,j,0);
			int yy=w[S]+w[T]+mp2[xian[S][i]][S]+dp[T]+mp2[zzx][T];
			ans=min(ans,yy);
		}
		cout<<ans<<endl;
	}
	return 0;
}
