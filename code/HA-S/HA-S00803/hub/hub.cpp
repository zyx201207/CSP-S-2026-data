#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,k,t,n,fa[1000005],dis[15][15],ans;
bool belong[1000005];
vector<int>G[1000005];
int Find(int x){
	if(x==fa[x])return x;
	return fa[x]=Find(fa[x]);
}
bool vis[15];
void dfs(int K){
	if(K==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=belong[i];
//			if(belong[i])printf("%lld ",belong[i]);
		}
		if(cnt!=k)return;
		memset(vis,0,sizeof(vis));
		for(int u=1;u<=n;u++)fa[u]=u;
		for(int u=1;u<=n;u++){
			for(auto v:G[u]){
				if(belong[u]!=0&&belong[v]!=0){
					fa[Find(u)]=Find(v);
				}
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(belong[i])vis[Find(i)]=1;
		}
		for(int i=1;i<=n;i++){
			if(vis[i])cnt++;
		}
		if(cnt>2)return;
		int mmax=0;
		for(int i=1;i<=n;i++){
			int mmin=1e18;
			for(int j=1;j<=n;j++){
				if(belong[j]){
					mmin=min(mmin,dis[i][j]);
				}
			}
			mmax=max(mmax,mmin);
		}
		ans=min(ans,mmax);
//		printf("----------\n");
//		for(int i=1;i<=n;i++){
////			cnt+=belong[i];
//			if(belong[i])printf("%lld ",i);
//		}
//		printf("\n%lld\n",mmax);
//		printf("----------\n");
		return;
	}
	for(int i=0;i<=1;i++){
		belong[K]=i;
		dfs(K+1);
	}
}
#undef int
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	#define int long long
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=1e18;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)G[i].clear();
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				}
			}
		}
//		printf("**********\n");
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				printf("%lld ",dis[i][j]);
//			}
//			printf("\n");
//		}
//		printf("**********\n");
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
