#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
int c,t,n,k,dis[15][15],ans=1e9;
void dfs(int u,int f,int rt){
	for(auto v: g[u]){
		if(v==f)continue;
		dis[v][rt]=dis[u][rt]+1; 
		dis[rt][v]=dis[v][rt];
		dfs(v,u,rt);
	}
}
bool cz[15];
int qry(int u,int f){
	int ans=0;
	for(auto v: g[u]){
		if(v==f)continue;
		ans+=qry(v,u);
		if(cz[u]&&cz[v])ans--;	
	}
	if(cz[u])ans++;
	return ans;
}
bool check(){
	return qry(1,0)<=2;
}
void dfs_(int nw,int sel){
	if(sel>2)return ;
	
	if(nw==n){
		if(sel!=k)return ;
		if(!check())return ;
		int z=0;
		for(int i=1;i<=n;i++){
			int q=1e9;
			for(int j=1;j<=n;j++){
				if(cz[j])q=min(q,dis[i][j]);
			}
			z=max(z,q);
		}
		ans=min(ans,z);
		return ;
	}
	cz[nw+1]=1;
	dfs_(nw+1,sel+1);
	cz[nw+1]=0;
	dfs_(nw+1,sel);
}
void solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	for(int i=1;i<=n;i++)dfs(i,0,i);
	dfs_(0,0);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)cz[i]=0,g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=0;
		}
	}
	ans=1e9;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
}
/*
15pts
*/
