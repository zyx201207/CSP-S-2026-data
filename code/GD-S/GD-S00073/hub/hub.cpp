#include<bits/stdc++.h>
using namespace std;
const int N=4005,inf=1e9;
int c,T,n,m,x,y,p,q,ans,fa[N],col[N],Fa[N][2],sz[N],d[N],nf[N],g[N],h[N],f[N][N],dis[N][N],mn[N][2];
vector<int> v[2],G[N];
void DFS(int x,int lx){
	fa[x]=lx;
	for(auto y:G[x]){
		if(y==lx) continue;
		DFS(y,x);
	}
}
void DFS2(int x,int lx,int *dis){
	for(auto y:G[x]){
		if(y==lx) continue;
		dis[y]=dis[x]+1;
		DFS2(y,x,dis);
	}
}
void dfs(int x,int lx){
	sz[x]=1,d[x]=0,f[x][1]=0;
	for(int i=2;i<=m;i++) f[x][i]=inf;
	col[x]=q;
	for(auto y:G[x]){
		if(y==lx||y==p) continue;
		Fa[y][q]=x;
		dfs(y,x);
		d[x]=max(d[x],d[y]+1);
		for(int i=1;i<=sz[x]+sz[y];i++) nf[i]=inf;
		for(int i=1;i<=sz[x];i++){
			for(int j=1;j<=sz[y];j++){
				nf[i+j]=min(nf[i+j],max(f[x][i],f[y][j]));
			}
			nf[i]=min(nf[i],max(f[x][i],d[y]+1));
		}
		for(int i=1;i<=sz[x]+sz[y];i++) f[x][i]=nf[i];
		sz[x]+=sz[y];
	}
	v[q].push_back(x);
//	printf("%d:",x);
//	for(int i=1;i<=sz[x];i++){
//		printf("%d ",f[x][i]);
//	}
//	printf("\n");
}
int dfs2(int x,int lx,int st,int o){
	int res=0;
	for(auto y:G[x]){
		if(y==lx||(x==st&&Fa[y][o]==x)||col[y]!=col[x]) continue;
		res=max(res,dfs2(y,x,st,o)+1);
	}
	return res;
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1,0);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		DFS2(i,0,dis[i]);
	}
	ans=inf;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++) mn[j][0]=mn[j][1]=inf;
		v[0].clear(),v[1].clear();
		p=i,q=0;
//		printf("::%d\n",i);
		dfs(i,fa[i]);
		q=1;
//		printf("------\n");
		dfs(1,0);
//		printf("\n");
		for(int o=0;o<=1;o++){
			for(auto x:v[o]){
				int t=dfs2(x,0,x,o);
//				printf("&&&&&&&&&%d->%d\n",x,t);
				for(int j=1;j<=m;j++){
					mn[j][o]=min(mn[j][o],max(f[x][j],t));
				}
			}	
		}
		for(int j=1;j<m;j++){
//			printf("%d*%d %d\n",j,mn[j][0],mn[m-j][1]);
			ans=min(ans,max(mn[j][0],mn[m-j][1]));
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) solve();
	return 0;
}
