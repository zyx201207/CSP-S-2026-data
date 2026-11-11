#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=15;
int c,t,n,k;
vector<int>vt[N];
int dep[N],lca[N][N],fa[N];
bool f[N],vis[N];
void dfs(int u,int fat){
	dep[u]=dep[fat]+1;
	fa[u]=fat;
	for(int v:vt[u]){
		if(v==fat)continue;
		dfs(v,u); 
	} 
	return;
}
bool check(){
	queue<int>q;
	for(int i=1;i<=n;i++)vis[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&f[i]){
			q.push(i);
			cnt++;
			vis[i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v:vt[u]){
					if(!f[v]||vis[v])continue;
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return cnt<=2;
}
int getlca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	while(dep[u]>dep[v])u=fa[u];
	while(u!=v){
		u=fa[u];v=fa[v];
	}
	return u;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)vt[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u); 
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)lca[i][j]=lca[j][i]=getlca(i,j);
		int ans=1145141919810;
		for(int mask=0;mask<(1<<n);mask++){
			int cnt=0;
			for(int j=0;j<n;j++)if((mask>>j)&1)cnt++;
			if(cnt!=k)continue;
			for(int j=0;j<n;j++)if(((mask)>>j)&1)f[j+1]=1;
			else f[j+1]=0;
			if(!check())continue;
//			for(int i=1;i<=n;i++)cout<<f[i]<<' ';
//			cout<<'\n';
			int maxx=0;
			for(int i=1;i<=n;i++){
				if(f[i])continue;
				int minn=1145141919810;
				for(int j=1;j<=n;j++){
					if(!f[j]||i==j)continue;
					minn=min(minn,dep[i]+dep[j]-2-2*(dep[lca[i][j]]-1));
				}
				maxx=max(maxx,minn);
			}
			ans=min(ans,maxx);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

*/
