#include <bits/stdc++.h>
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define N 1000005
#define fi first
#define se second
#define ll long long
using namespace std;
int n,u,v,h[N],t,dfn[N],cnt,p[N],T,C,dep[N],c[N],cntt,ans,rt[2],siz[N],k,l;
ll f[N],g[N];
bool vis[N];
struct Ed{
	int v,nxt;
};
Ed e[N<<1];
inline void add(int u,int v){
	e[++t]=Ed{v,h[u]};
	h[u]=t;
}
struct ha{
	pair<int,int> mx;
	int la,laa;
};
struct haa{
	ha b[N<<2];
	inline void pu(int u,int la,int laa){
		b[u].la+=la;
		b[u].mx.fi+=la;
		if(laa) b[u].mx.se=laa;
	}
	inline void up(int u){
		b[u].mx=max(b[ls].mx,b[rs].mx);
	}
	inline void down(int u){
		pu(ls,b[u].la,b[u].laa);
		pu(rs,b[u].la,b[u].laa);
		b[u].la=b[u].laa=0;
	}
	void modify(int u,int l,int r,int L,int R,int rt){
		if(l>r) return ;
		if(l>=L&&r<=R){//printf("%d %d %d\n",l,r,b[u].mx.fi);
			pu(u,-1,rt);//printf("%d %d %d\n",l,r,b[u].mx.fi);
			return ;
		}
		down(u);
		if(L<=mid) modify(ls,l,mid,L,R,rt);
		if(R>mid) modify(rs,mid+1,r,L,R,rt);
		up(u);
	}
	void build(int u,int l,int r,int rt){
		if(l>r) return ;
		b[u].la=b[u].laa=0;
		if(l==r){
			b[u].mx={dep[p[l]],rt};
			return ;
		}
		build(ls,l,mid,rt);
		build(rs,mid+1,r,rt);
		up(u);
	}
};
haa b[2];
vector<int> d[2];
void dfs1(int u,int fa,int fl){
	dep[u]=dep[fa]+1;
	c[u]=cntt+1;
	siz[u]=1;
	f[u]=0;
	d[cntt].push_back(u);
	for(int i=h[u];~i;i=e[i].nxt) if(i!=fl&&i!=(fl^1)&&e[i].v!=fa){
		dfs1(e[i].v,u,fl);
		siz[u]+=siz[e[i].v];
		f[u]+=siz[e[i].v];
	} 
}
pair<ll,int> mn[2];
void dfs2(int u,int fa,int fl){
	if(!fa) g[u]=f[u];
	else g[u]=g[fa]-siz[u]+((int)d[cntt].size()-siz[u]);
	mn[cntt]=min(mn[cntt],{g[u],u});
	for(int i=h[u];~i;i=e[i].nxt) if(i!=fl&&i!=(fl^1)&&e[i].v!=fa) dfs2(e[i].v,u,fl);
}
inline void solve(int fl){
	int l=(int)d[0].size(),tmp=k;
	b[0].build(1,1,l,mn[0].se);
	b[1].build(1,l+1,n,mn[1].se);
	vis[mn[0].se]=vis[mn[1].se]=1;
	tmp-=1+(l!=n);
//	for(int i=1;i<=n;i++) printf("%d ",dep[i]);
//	putchar('\n');
//	printf("%d %d\n",mn[0].se,mn[1].se);
	b[0].modify(1,1,l,dfn[mn[0].se],dfn[mn[0].se],mn[0].se);
	for(int i=h[mn[0].se];~i;i=e[i].nxt) if(!vis[e[i].v]&&i!=fl&&i!=(fl^1))
		b[0].modify(1,1,l,dfn[e[i].v],dfn[e[i].v]+siz[e[i].v]-1,e[i].v)/*,printf("%d ",e[i].v)*/;
//	putchar('\n');
	if(mn[1].se){
		b[1].modify(1,l+1,n,dfn[mn[1].se],dfn[mn[1].se],mn[1].se);
		for(int i=h[mn[1].se];~i;i=e[i].nxt) if(!vis[e[i].v]&&i!=fl&&i!=(fl^1))
			b[1].modify(1,l+1,n,dfn[e[i].v],dfn[e[i].v]+siz[e[i].v]-1,e[i].v);
	} 
//	printf("%d %d ",mn[0].se,mn[1].se);
	while(tmp--){//printf("%d %d\n",b[0].b[1].mx.fi,b[1].b[1].mx.fi);
		if(b[0].b[1].mx.fi>b[1].b[1].mx.fi&&b[0].b[1].mx.se!=mn[0].se){
			int x=b[0].b[1].mx.se;
			b[0].modify(1,1,l,dfn[x],dfn[x],mn[0].se);
			for(int i=h[x];~i;i=e[i].nxt) if(!vis[e[i].v]&&i!=fl&&i!=(fl^1)) 
				b[0].modify(1,1,l,dfn[e[i].v],dfn[e[i].v]+siz[e[i].v]-1,e[i].v);
			vis[x]=1;//printf("%d ",x);
		}
		else{
			int x=b[1].b[1].mx.se;
			b[1].modify(1,l+1,n,dfn[x],dfn[x],mn[1].se);
			for(int i=h[x];~i;i=e[i].nxt) if(!vis[e[i].v]&&i!=fl&&i!=(fl^1))
				b[1].modify(1,l+1,n,dfn[e[i].v],dfn[e[i].v]+siz[e[i].v]-1,e[i].v);
			vis[x]=1;//printf("%d ",x);
		}
	}
//	putchar('\n');
	ans=min(ans,max(b[0].b[1].mx.fi,b[1].b[1].mx.fi));
}
void dfs3(int u,int fa,int fl){
	dep[u]=dep[fa]+1;
	siz[u]=1;
	dfn[u]=++cnt,p[cnt]=u;//printf("%d %d\n",u,cnt);
	for(int i=h[u];~i;i=e[i].nxt) if(e[i].v!=fa&&i!=fl&&i!=(fl^1)){
		dfs3(e[i].v,u,fl);
		siz[u]+=siz[e[i].v];
	} 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		memset(h,-1,sizeof(h));
		scanf("%d%d",&n,&k);
		t=1;
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		ans=(int)2e9;
		for(int i=0;i<n;i++){//printf("%d\n",i);
			d[0].clear(),d[1].clear();
			cntt=cnt=0;
			mn[0]=mn[1]={(ll)2e18,0};
			for(int j=1;j<=n;j++) c[j]=vis[j]=0;
			for(int j=1;j<=n;j++) if(!c[j]){
				dfs1(j,0,i<<1);
				dfs2(j,0,i<<1);//printf("%d %d\n",cntt,mn[cntt].fi);
				dfs3(mn[cntt].se,0,i<<1);
				rt[cntt]=j;
				cntt++;
			}
			solve(i<<1);//printf("%d\n",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
