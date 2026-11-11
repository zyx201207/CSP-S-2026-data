#include "bits/stdc++.h"
using namespace std;
int n,k,minn;
int r[100001],w[100001],bz[1000001],fa[100001],dep[100001],depson[100001];
vector<int> g[100001];
void dfs(int x,int lst){
	fa[x]=lst,dep[x]=dep[lst]+1;
	for(int i:g[x])
		if(i!=lst) dfs(i,x);
}
void dg2(int x){
	r[x]=1;
	for(int i:g[x])
		if(!r[i] && w[i]) dg2(i);
} 
int dis(int u,int v){
	for(int i=1;i<=n;i++) bz[i]=-1;
	for(int i=0;u;u=fa[u],i++) bz[u]=i;
	for(int j=0;;v=fa[v],j++)
		if(bz[v]!=-1) return bz[v]+j;
}
void dg(int x,int p){
	if(p>k) return;
	if(x>n){
		if(p!=k) return;
		int cnt=0;
		for(int i=1;i<=n;i++) r[i]=0; 
		for(int i=1;i<=n;i++){
			if(!w[i] || r[i]) continue;
			cnt++;
			dg2(i);
			if(cnt>2) return;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int res=1e9;
			for(int j=1;j<=n;j++)
				if(w[j]) res=min(res,dis(i,j));
			ans=max(ans,res);
		}
		minn=min(minn,ans);
		return;
	}
	w[x]=1;
	dg(x+1,p+1);
	w[x]=0;
	dg(x+1,p);
}
int main(void){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++)
			cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		dfs(1,0);
		minn=1e9;
		dg(1,0);
		cout<<minn<<"\n";
		for(int i=1;i<=n;i++) g[i].clear();
	}
	fclose(stdin);
	fclose(stdout);
}
