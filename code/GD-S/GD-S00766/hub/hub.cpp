#include<bits/stdc++.h>
using namespace std;
#define ve vector
#define pb push_back
const int N=1e6+5;
int U[N],V[N],f[N],lb[N],d[N],F[N];
ve<int>q,e[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void dfs(int u,int fa){
	d[u]=d[F[u]=fa]+1;
//	cerr<<u<<' '<<d[u]<<'\n';
	int x=lb[fa],y=lb[x];
	lb[u]=(d[fa]-d[x]==d[x]-d[y]?y:fa);
	for(int v:e[u])if(v^fa)dfs(v,u);
}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	while(d[x]>d[y])x=(d[lb[x]]>=d[y]?lb[x]:F[x]);
	while(x^y)(lb[x]^lb[y]?(x=lb[x],y=lb[y]):(x=F[x],y=F[y]));
	return x;
}
int mxd[N],Mxd[N],CK,ct,w[N],g[N];
void check(int u){
	mxd[u]=Mxd[u]=0,w[u]=1e9,g[u]=0;
	for(int v:e[u])if(v^F[u])check(v);
	for(int v:e[u])if(v^F[u]){
		if(d[u]+CK-w[v]-1>=mxd[u])mxd[u]=0;
		if(d[u]+CK-w[v]-1>=Mxd[u])Mxd[u]=0;
		if(d[v]+CK-w[u]-1<mxd[v]){
			if(mxd[v]>mxd[u])
				Mxd[u]=mxd[u],mxd[u]=mxd[v];
			else if(mxd[v]>Mxd[u])Mxd[u]=mxd[v];
			if(d[v]+CK-w[u]-1<g[v]&&g[v]){
				g[u]=max(g[u],g[v]);
			}
		}
		w[u]=min(w[u],w[v]+1);
	}
	if(CK-w[u]<0){
		if(d[u]>mxd[u])Mxd[u]=mxd[u],mxd[u]=d[u];
		else if(d[u]>Mxd[u])Mxd[u]=d[u];
	}
	if(mxd[u]-d[u]>=CK)++ct,mxd[u]=Mxd[u]=w[u]=g[u]=0;
	else if(Mxd[u]+mxd[u]-2*d[u]>=CK)
//		cerr<<"**"<<u<<' '<<Mxd[u]<<' '<<mxd[u]<<' '<<g[u]<<'\n',
		g[u]=max(g[u],mxd[u]);
}
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++)
		cin>>U[i]>>V[i],e[U[i]].pb(V[i]),e[V[i]].pb(U[i]);
	if(n==k){cout<<0<<'\n';return;}
	dfs(1,0);
	if(k==2){
		int l=1,r=n-1,mid;
		while(l<=r)mid=l+r>>1,ct=0,CK=mid,
//			cerr<<"****"<<mid<<'\n',
			check(1),ct+=(g[1]>0),
//			cerr<<g[1]<<' '<<ct<<'\n',
			(ct<=k?r=mid-1:l=mid+1);
		cout<<r+1<<'\n';return;
	}
	if(n<=10){
		int ans=1e9;
		for(int i=0;i<(1<<n);i++){
			int ct=0;q.clear();
			for(int j=1;j<=n;j++)
				if(i&(1<<j-1))++ct,q.pb(j);
			if(ct!=k)continue;
			for(int j=1;j<=n;j++)f[j]=j;
			for(int j=1;j<n;j++)
				if((i&(1<<U[j]-1))&&(i&(1<<V[j]-1)))
					f[find(U[j])]=find(V[j]);
			int res=0;
			for(int j:q)if(find(j)==j)++res;
			if(res!=2)continue;
			int mx=0;
			for(int j=1;j<=n;j++)if(!(i&(1<<j-1))){
				int dis=1e9;
				for(int k:q)
					dis=min(dis,d[j]+d[k]-2*d[lca(j,k)]);
//					cerr<<j<<' '<<k<<' '<<lca(j,k)<<'\n';
				mx=max(mx,dis);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<'\n';
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,_;cin>>c>>_;
	while(_--)solve();
	return 0;
}
