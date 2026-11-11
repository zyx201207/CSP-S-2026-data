//GZ-S00146 贵阳市第九中学 向一坤 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5009;
int C,T;
int n,k,ans=0;
vector<int > vec[N];
int dt[13],mp[13][13],f[13];
int fid(int x){return ((x==f[x])?x:(f[x]=fid(f[x])));}
int fa[N][20],dep[N];
void dfs(int u,int faa){
	dep[u]=dep[faa]+1;fa[u][0]=faa;for(int i=1;i<=4;++i) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:vec[u]) if(v!=faa) dfs(v,u);}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(v,u);
	int cc=dep[u]-dep[v],cnt=0;
	for(int i=0;i<=4;++i) if((cc>>i)&1) u=fa[u][i],cnt+=(1<<i);
	if(u==v) return cnt;
	for(int i=4;i>=0;--i) if(fa[u][i]!=fa[v][i]){u=fa[u][i],v=fa[v][i],cnt+=(1<<(i+1));}
	return cnt+2;}
void check(){
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=k;++i){
		for(int j=1;j<i;++j){
			int u=dt[i],v=dt[j];
			if(!mp[u][v]) continue;
			if(u!=v) f[u]=v;}
	}int ltk=0,q=0;
	for(int i=1;i<=k;++i) if(f[dt[i]]==dt[i]) ++ltk;
	if(ltk>2) return ;
	for(int i=1;i<=n;++i){
		int p=0x3f3f3f3f;
		for(int j=1;j<=k;++j) p=min(p,lca(i,dt[j]));
		q=max(q,p);
	}ans=min(ans,q);
}
void dfs1(int x,int y){
	if(x==k+1){check();return ;}
	for(int i=y;i<=n;++i){dt[x]=i;dfs1(x+1,i+1);}}
void _n10(){dfs1(1,1);printf("%d\n",ans);}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);while(T--){
		scanf("%d%d",&n,&k);ans=n;
		for(int i=1;i<n;++i){
			int u,v;scanf("%d%d",&u,&v);if(C<=3) mp[u][v]=mp[v][u]=1;
			vec[u].push_back(v);vec[v].push_back(u);
		}dfs(1,0);
		if(C<=3) _n10();
		for(int i=1;i<=n;++i) vec[i].clear();
		memset(fa,0,sizeof(fa));memset(dep,0,sizeof(dep));memset(mp,0,sizeof(mp));
	}
	return 0;
}
/*
15pts 17:38
*/ 
