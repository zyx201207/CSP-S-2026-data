#include<bits/stdc++.h>
using namespace std;
const int M=1e6+100,inf=INT_MAX;
int c,T,l,r,n,mn,k,rt,dep[M],f[M],g[M],h[M][2],ans;
vector<int> e[M];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		f[u]=max(f[u],f[v]+1);
	}
	if(max(dep[u],f[u])<mn){
		mn=max(dep[u],f[u]);
		rt=u;
	}
	return;
}
void dfs2(int u,int mid,int fa){
	int lst=0,tot=0,ad[5]={};
	for(int v:e[u]){
		if(v==fa) continue;
		dfs2(v,mid,u);
		f[u]=max(f[u],f[v]+1);
		g[u]=max(g[u],g[v]-1);
		if(h[v][0]){
			if(tot<=1) ad[++tot]=h[v][0];
			else tot++;
			if(!h[u][0]) h[u][0]=h[v][0],h[u][1]=h[v][1],lst=v;
			else{
				h[u][1]+=h[v][1];
				h[u][0]=inf;
			}
		}
	}
	if(g[u]>=f[u]) f[u]=-inf;
	if(f[u]==mid){
		g[u]=mid;
		f[u]=-inf;
		if(h[u][0] && h[u][0]!=inf)
			h[u][0]=h[lst][1]+1;
		else h[u][1]=h[u][0]=1;
	}
	if(h[u][1]) h[u][1]++;
	if(u==rt && tot<=2) h[u][0]=ad[0]+ad[1];
}
bool check(int mid){
	for(int i=1;i<=n;i++){
		f[i]=h[i][0]=h[i][1]=0;
		g[i]=-inf;
	}
	dfs2(rt,mid,0);
//	for(int i=1;i<=n;i++){
//		cout<<f[i]<<' '<<g[i]<<' '<<h[i][0]<<' '<<h[i][1]<<'\n';
//	}
	return (min(h[rt][0],h[rt][1])<=k);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear(),f[i]=0,dep[i]=0;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	rt=0;mn=inf;dep[0]=-1;
	dfs(1,0);
	l=1;r=n,ans=n;
//	if(n==10) check(2);
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else l=mid+1;
	}
	cout<<ans<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

