#include<bits/stdc++.h>
using namespace std;
const int Maxn=1000005;
vector<int> adj[Maxn];
int n,m;
namespace sub1{
	bool flg[Maxn];
	int dep[Maxn],cur,ans;
	void dfs(int u,int fa){
		cur=max(cur,dep[u]);
		for(int i=0;i<(int)(adj[u].size());++i){
			int v=adj[u][i];if (v==fa||flg[v]) continue;
			dep[v]=dep[u]+1;dfs(v,u);
		}
	}
	void clr(int u){
		flg[u]=0;
		for(int i=0;i<(int)(adj[u].size());++i){
			int v=adj[u][i];if (!flg[v]) continue;
			clr(v);
		}
	}
	void work(){
		scanf("%d%d",&n,&m);ans=n;
		for(int i=1,u,v;i<n;++i){scanf("%d%d",&u,&v);adj[u].push_back(v);adj[v].push_back(u);}
		for(int S=0;S<(1<<n);++S){
			cur=0;int cnt=0,ct=0;
			for(int i=0;i<n;++i) flg[i+1]=(S>>i)&1;
			for(int i=1;i<=n;++i) if (flg[i]){dep[i]=0;++cnt;dfs(i,0);}
			for(int i=1;i<=n;++i) if (flg[i]){++ct;clr(i);}
			if (cnt&&cur<ans&&cnt<=m&&ct<=2) ans=cur;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i){adj[i].clear();flg[i]=0;}
	}
}
namespace sub2{
	int dep[Maxn],rt,z,top,stk[Maxn],ans;
	bool flg[Maxn];
	void dfs(int u,int fa){
		for(int i=0;i<(int)(adj[u].size());++i){
			int v=adj[u][i];if (v==fa) continue;
			dep[v]=dep[u]+1;dfs(v,u);
		}
	}
	void dfs2(int u){
		flg[u]=1;stk[++top]=u;
		if (u==rt) return ;
		for(int i=0;i<(int)(adj[u].size());++i){
			int v=adj[u][i];
			if (dep[v]==dep[u]-1) dfs2(v);
		}
	}
	int L[Maxn],R[Maxn],mxd[Maxn];
	void dfs3(int u,int fa){
		mxd[u]=0;
		for(int i=0;i<(int)(adj[u].size());++i){
			int v=adj[u][i];if (v==fa||flg[v]) continue;
			dfs3(v,u);mxd[u]=max(mxd[v]+1,mxd[u]);
		}
	}
	void work(){
		scanf("%d%d",&n,&m);
		for(int i=1,u,v;i<n;++i){scanf("%d%d",&u,&v);adj[u].push_back(v);adj[v].push_back(u);}
		dep[1]=0;dfs(1,0);rt=1;
		for(int i=1;i<=n;++i) if (dep[i]>dep[rt]) rt=i;
		dep[rt]=0;z=rt;dfs(rt,0);
		for(int i=1;i<=n;++i) if (dep[i]>dep[z]) z=i;
		top=0;dfs2(z);ans=top/2;
		for(int i=1;i<=top;++i) dfs3(stk[i],0);
		for(int i=1;i<=top;++i) L[i]=max(L[i-1],mxd[stk[i]]+i);
		for(int i=top;i;--i) R[i]=max(R[i+1],mxd[stk[i]]+top-i+1);
		for(int i=1;i<top;++i) ans=min(ans,max(L[i]/2,R[i+1]/2));
		printf("%d\n",ans);
		for(int i=1;i<=n;++i){adj[i].clear();flg[i]=0;L[i]=R[i]=0;}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--){
		if (c<=3) sub1::work();
		else if (c==7||c==11||c==12) sub2::work();
	}
	return 0;
}
