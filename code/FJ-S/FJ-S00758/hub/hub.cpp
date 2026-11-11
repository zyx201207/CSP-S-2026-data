#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;
const int N=110;
using ll=long long;
int dp[N][N][N];
int dep[N],dis[N],siz[N],fa[N];
vector<int> e[N];
int n,k;
void dfs(int u){
	siz[u]=1;
	for(int v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		siz[u]+=siz[v];
		dis[u]=max(dis[v]+1,dis[u]);
	}
	dp[u][1][0]=0;
	dp[u][0][0]=0;
	for(int d=1;d<=dis[u];++d){
		dp[u][1][d]=0;
		for(int v:e[u]){
			if(v==fa[u])continue;
			for(int m=min(k,siz[u]);m;--m){
				for(int j=0;j<=m;++j)
					for(int x=0;x<d;++x)
						dp[u][m][d]=min(dp[u][m][d],dp[u][m-j][d]+dp[v][j][x]+d+1+x);
			}
		}	
	}
	
}
bool check(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	do{
		if(u==v)return 1;
		u=fa[u];
	}while(u);
	return 0;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
int ans=1e9;
	for(int r=1;r<=n;++r){
		memset(dp,0x3f3f3f3f,sizeof dp);
		for(int i=1;i<=n;++i)dep[i]=dis[i]=0;
		dep[r]=1;
		dfs(r);
		if(r==1){
//			for(int i=1;i<=n;++i)cout<<dp[i][2][1]<<"\n";
		}
		for(int i=1;i<=n;++i)
		for(int d=0;d<=dis[i];++d)ans=min(ans,dp[i][k][d]);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				for(int m=1;m<k;++m)
					for(int d1=1;d1<=dis[i];++d1)
					for(int d2=1;d2<=dis[j];++d2)
					if(!check(i,j))ans=min(ans,dp[i][m][d1]+dp[j][k-m][d2]+dep[i]+dep[j]+d1+d2);
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	for(cin>>c>>t;t;--t)solve();
	return 0;
}
