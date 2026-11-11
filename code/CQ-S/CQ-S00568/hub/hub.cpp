#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5,M=2e6+5;
int n,cnt,idx,head[N],dep[N],d[N],f[N];
int son[N],tot[N],st[N],siz[N],rt;
int dfn[N],id[N];
struct nnd {
	int to,next;
}eg[N<<1];
void add(int from,int to){
	eg[++cnt]={to,head[from]};
	head[from]=cnt;
}
void dfs1(int x,int fa){
	siz[x]=1,st[x]=fa,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=eg[i].next){
		int to=eg[i].to;
		if(to==fa)continue;
		dfs1(to,x),siz[x]+=siz[to];
		if(siz[to]>siz[son[x]])son[x]=to;
	}
}
void dfs2(int x,int tt){
	tot[x]=tt,dfn[x]=++idx,id[idx]=x;
	if(son[x])dfs2(son[x],tt);
	for(int i=head[x];i;i=eg[i].next){
		int to=eg[i].to;
		if(to!=st[x]&&to!=son[x])dfs2(to,to);
	}
}
int lca(int x,int y){
	while(tot[x]^tot[y]){
		if(dep[tot[x]]<dep[tot[y]])swap(x,y);
		x=st[tot[x]];
	} 
	return (dep[x]<dep[y])?x:y;
}
void init(){
	queue<int>q;
	for(int x=1;x<=n;x++)for(int i=head[x];i;i=eg[i].next)d[x]++;
	for(int i=1;i<=n;i++)if(d[i]==1)q.push(i),f[i]=1;
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=eg[i].next){
			int to=eg[i].to;
			if((--d[to])==1){
				q.push(to);
				f[to]=f[x]+1;
			}
		}
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		if(f[i]>f[rt])rt=i;
}
int fa[N],num[N];
bool vis[N],dis[N];
set<int>sst;
int find(int x){
	return (fa[x]==x)?x:(fa[x]=find(fa[x])); 
}
vector<int>dot[N];
int get(int w){
	for(int i=1;i<=n;i++)fa[i]=i,dis[i]=(f[i]<=w);
	for(int x=1;x<=n;x++){
		for(int i=head[x];i;i=eg[i].next){
			int to=eg[i].to;
			if(dis[x]==dis[to]){
				fa[find(x)]=find(to);
			}
		}
	}
	int ccnt=0,ans=0;
	for(int i=1;i<=n;i++){
		if(!dis[i]&&i==find(i))ccnt++;
		if(!dis[i])ans++;
	}
	if(ccnt==1){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int x=1;x<=n;x++){
			if(dis[x])continue;
			for(int i=head[x];i;i=eg[i].next)
				if(!dis[eg[i].to])d[x]++;
		}
		for(int x=1;x<=n;x++){
			if(d[x]^2)continue;
			for(int i=head[x];i;i=eg[i].next){
				int to=eg[i].to;
				if(!dis[to]&&d[to]==2){
					fa[find(x)]=find(to);
				}
			} 
		}
		for(int i=1;i<=n;i++){
			if(d[i]==2)num[find(i)]++;
		}
		int dt=0;
		for(int i=1;i<=n;i++)dt=max(dt,num[i]);
		ans-=dt;
	} else {
		for(int x=1;x<=n;x++){
			if(!dis[x])continue;
			bool v=1;
			for(int i=head[x];i;i=eg[i].next){
				v&=dis[eg[i].to];
			}
			if(!v)dot[find(x)].push_back(x);
		}
		for(int i=1;i<=n;i++){
			if(!dis[i]||find(i)!=i)continue;
			sst.clear();
			for(int x:dot[i]){
				if(sst.size()){
					
				} else {
				}
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	
	
	return 0;
}
/*
no!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Ð´²»Íê£¬¿Õ±¯ÇÐ £¡£¡£¡£¡ 
°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡£¡ 

Ò»¶¨ÒªÈ¥ WC °¡¡£
ÓÐ¹À·ÖÄÇÃ´¸ßÃ÷Äê»¹À´³äÇ®
CCF »ØÓ¦ÎÒµÄËßÇó°É qwq¡£ 
*/
