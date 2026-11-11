#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int MAXN=3e5+5;
const int MAXM=24;
const int MAXQ=(1<<10)+5;

int c,t,n,K,ans,edgeid=1,head[MAXN],f[MAXN][MAXM],dep[MAXN],id[MAXQ],cnt[MAXQ],lb[MAXQ],stk[MAXN],fa[MAXN],siz[MAXN];

struct Road{
	int nxt,to;
}edge[MAXN<<1];

inline void add_edge(int u,int v){
	edge[++edgeid]={head[u],v},head[u]=edgeid;
	return;
}

inline void dfs(int now,int fa){
	for (int i=1;i<=21;i++) f[now][i]=f[f[now][i-1]][i-1];
	for (int i=head[now];i;i=edge[i].nxt){
		int ed=edge[i].to;
		if (ed==fa) continue;
		dep[ed]=dep[now]+1,f[ed][0]=now;
		dfs(ed,now);
	}
	return;
}

inline int LCA(int u,int v){
	if (dep[u]<dep[v]) swap(u,v);
	for (int i=21;i>=0;i--){
		if (dep[f[u][i]]>=dep[v]) u=f[u][i];
		if (u==v) return v;
	}
	for (int i=21;i>=0;i--) if (f[u][i]!=f[v][i]){
		u=f[u][i],v=f[v][i];
	}
	return f[u][0];
}

inline int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}

inline int Find(int now){
	return fa[now]==now?fa[now]:fa[now]=Find(fa[now]);
}

inline bool check(int checknum){
	int cnt=0,tmp=K;
	for (int i=1;i<=n;i++) if (checknum&(1<<(i-1))) stk[++cnt]=i;
	for (int i=1;i<=cnt;i++) fa[stk[i]]=stk[i],siz[stk[i]]=1;
	for (int i=1;i<=cnt;i++) for (int j=1;j<=cnt;j++){
		if (f[stk[i]][0]==stk[j]){
			int fu=Find(stk[i]),fv=Find(stk[j]);
			if (fu==fv) continue;
			if (siz[fu]<siz[fv]) swap(fu,fv);
			tmp--,siz[fu]+=siz[fv],fa[fv]=fu;
		}
	}
	return tmp<=2;
}

inline void subtask1(){
	for (int i=1;i<=n;i++) id[1<<(i-1)]=i;
	for (int i=1;i<(1<<n);i++){
		lb[i]=(i&-i),cnt[i]=cnt[i^lb[i]]+1;
		if (cnt[i]!=K||!check(i)) continue;
		int lst=0;
		for (int j=1;j<=n;j++){
			if (i&(1<<(j-1))) continue;
			int res=inf;
			for (int k=i;k;k-=lb[k]) res=min(res,dis(j,id[lb[k]]));
			lst=max(lst,res);
		}
		ans=min(ans,lst);
	}
	return;
}

inline void prework(){
	scanf("%d%d",&n,&K);
	edgeid=1;
	for (int i=1;i<=n;i++) head[i]=0;
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	dep[1]=1,dfs(1,-1);
	return;
}

inline void solve(){
	ans=inf;
	if (n<=10) subtask1();
	else if (K==n) ans=0;
	else{
		int m=n/2+1;
		
	}
	printf("%d\n",ans);
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	for (int i=1;i<=t;i++) prework(),solve();
	return 0;
}
