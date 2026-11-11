#include<bits/stdc++.h>
using namespace std;
const int N=1005;//!!
int c,n,k,dth[N],fa[N][5],fat[N];
vector<int>g[N];
int find(int x){
	return fat[x]==x?x:fat[x]=find(fat[x]);
}
void dfs(int u,int Fa){
	dth[u]=dth[Fa]+1;
	fa[u][0]=Fa;
	for(int i=1;i<=4;i++)	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:g[u]){
		if(v==Fa)	continue;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dth[x]<dth[y])	swap(x,y);
	for(int i=4;i>=0;i--){
		if(dth[x]-(1<<i)>=dth[y])	x=fa[x][i];
	}
	if(x==y)	return x;
	for(int i=4;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}
void init(){
	for(int i=1;i<=n;i++)	g[i].clear();
	memset(fa,0,sizeof(fa));
	memset(dth,0,sizeof(dth));
}
void sub1(){
	dfs(1,0);
	vector<int>bl(n+1),vis(n+1);
	int fin=1e9;
	for(int S=1;S<(1<<n);S++){
		for(int i=1;i<=n;i++)	fat[i]=i,vis[i]=bl[i]=0;
		int ge=0;
		for(int i=1;i<=n;i++)	if((S>>(i-1))&1)	vis[i]=1,ge++;
		if(ge!=k)	continue;
		for(int u=1;u<=n;u++){
			for(int v:g[u]){
				if(!vis[v]||!vis[u])	continue;
				int fu=find(u),fv=find(v);
				if(fu!=fv)	fat[fu]=fv;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i])	bl[find(i)]=1;
		}
		int sum=0;
		for(int i=1;i<=n;i++)	if(bl[i])	sum++;
		if(sum>2)	continue;
		int ans=0;
		for(int i=1;i<=n;i++){//Ã»ÓÐÐÞ½¨ 
			if(vis[i])	continue;
			int sin=1e9;
			for(int j=1;j<=n;j++){
				if(vis[j]){
					int ll=lca(i,j);
					sin=min(sin,dth[i]+dth[j]-dth[ll]*2);
				}
			}	
			ans=max(ans,sin);
		}
		fin=min(fin,ans);
	}
	cout<<fin<<"\n";
}
void solve(){
	cin>>n>>k;
	init();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(c<=3)	sub1();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;cin>>c>>T;
	while(T--)	solve();
	return 0;
}
/*
16
*/
