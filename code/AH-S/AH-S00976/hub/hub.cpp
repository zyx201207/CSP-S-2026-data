#include<cstdio>
#include<algorithm>
using namespace std;
#define f(x,y,z) for(int x=y;x<=z;x++)
#define g(x,y,z) for(int x=y;x>=z;x--)
// #define ll long long
#define N 1000005
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
int n,m,c,t;
struct node{
	int next,to;
}edge[N*2];
int head[N],cnt=0;
void addedge(int u,int v){
	cnt++;
	edge[cnt]={head[u],v};
	head[u]=cnt;
}
int f[N][20],dep[N],id[N];
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa)continue;
		f[v][0]=u;
		dfs1(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	g(i,18,0)
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
	if(u==v)return u;
	g(i,18,0)
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return f[u][0];
}
bool vis[N],col[N];
void dfs(int u,int fa){
	vis[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa||col[v]==0)continue;
		dfs(v,u);
	}
}
int ANS;
void cl(){
	f(i,1,n)vis[i]=0;
	int cc=0;
	f(i,1,m){
		if(vis[id[i]])continue;
		if(cc>=2)return;
		dfs(id[i],0),cc++;
	}
	int ans=0;
	f(i,1,n){
		if(col[i])continue;
		int ll=n+1;
		f(j,1,m){
			int k=lca(id[j],i);
			ll=min(ll,dep[i]+dep[id[j]]-2*dep[k]);
		}
		ans=max(ans,ll);
	}
	// f(i,1,m)printf("%d ",id[i]);
	// printf("\n%d\n",ans);
	ANS=min(ANS,ans);
}
void dfs2(int u,int cnt){
	if(n-u+1<m-cnt+1)return;
	if(cnt>m){
		cl();
		return;
	}
	dfs2(u+1,cnt);
	id[cnt]=u,col[u]=1;
	dfs2(u+1,cnt+1);
	col[u]=0;
}
void CL(){
	n=read(),m=read(),ANS=n+1;
	f(i,1,n-1){
		int u=read(),v=read();
		addedge(u,v),addedge(v,u);
	}
	dfs1(1,0);
	f(i,1,n)f(j,1,18)f[i][j]=f[f[i][j-1]][j-1];
	dfs2(1,1);
	printf("%d\n",ANS);
	f(i,1,n)head[i]=0;cnt=0;
	f(i,1,n)f(j,0,18)f[i][j]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--)CL();
	return 0;
}