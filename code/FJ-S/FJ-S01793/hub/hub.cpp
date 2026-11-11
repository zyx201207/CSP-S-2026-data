#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Edge{int to,nxt;}e[15<<1];
int c,T,n,k,tot,head[15],fa[15],sizz[15],vis[15],g[15][15],mn;
int dep[15],siz[15],son[15],top[15],fat[15];
inline void link(int u,int v){
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}
inline int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(sizz[x]<sizz[y])x^=y,y^=x,x^=y;
	sizz[x]+=sizz[y],fa[y]=x;
}
inline void dfs1(int u){
	dep[u]=dep[fat[u]]+1;siz[u]=1;
	for(int i=head[u],v;i;i=e[i].nxt){
		if((v=e[i].to)!=fat[u]){
			fat[v]=u;dfs1(v);siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])son[u]=v;
		}
	}
}
inline void dfs2(int u,int topf){
	top[u]=topf;
	if(son[u])dfs2(son[u],topf);
	for(int i=head[u],v;i;i=e[i].nxt){
		if((v=e[i].to)!=fat[u]&&v!=topf)dfs2(v,v);
	}
}
inline int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])u^=v,v^=u,u^=v;
		u=fat[top[u]];
	}
	return dep[u]<dep[v]?u:v; 
}
inline void dfs(int x,int col){
	if(x==n+1){
		if(col!=k)return;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(int j=1;j<=n;j++){
					if(vis[i]&&vis[j]&&g[i][j])merge(i,j);
				}
			}
		}
		int ct=0,ans=0;
		for(int i=1;i<=n;i++)ct+=find(i)==i&&vis[i];
		if(ct>2)return;
		for(int i=1;i<=n;i++){
			int cur=0x3f3f3f3f;
			if(vis[i])continue;
			for(int j=1;j<=n;j++){
				if(vis[j])cur=min(cur,dep[i]+dep[j]-(dep[lca(i,j)]<<1));
			}
			ans=max(ans,cur);
		}
		mn=min(ans,mn);
		return;
	}
	if(col<k){
		vis[x]=1;dfs(x+1,col+1);vis[x]=0;
	}
	dfs(x+1,col);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--&&scanf("%d%d",&n,&k)==2){
		mn=0x3f3f3f3f;
		memset(fat,0,sizeof(fat));
		memset(siz,0,sizeof(siz));
		memset(son,0,sizeof(son));
		memset(top,0,sizeof(top));
		memset(dep,0,sizeof(dep));
		memset(head,0,sizeof(head));
		memset(g,0,sizeof(g));
		tot=0;
		for(int i=1,x,y;i<n;i++){
			scanf("%d%d",&x,&y);
			g[x][y]=g[y][x]=1;
			link(x,y);link(y,x);
		}
		for(int i=1;i<=n;i++)fa[i]=i,sizz[i]=1;
		dfs1(1);dfs2(1,1);dfs(1,0);
		printf("%d\n",mn);
	}
}
