#include<bits/stdc++.h> 
#define int long long 
using namespace std;
const int inf=1e11;
int c,t,n,k,fa[1000005],ans,dis[1000005];
vector<int> g[1000005];
bool vis[1000005];
void dfs1(int faa,int u){
	fa[u]=faa;
	for(auto v:g[u]){
		if(v==faa) continue;
		dfs1(u,v);
	}
	return ;
}
void dfs3(int fa,int u,int val){
	dis[u]=min(dis[u],val);
	for(auto v:g[u]){
		if(v==fa) continue;
		dfs3(u,v,val+1);
	}
	return ;
}
void js(int f){
	dfs3(0,f,0);
	return ;
}
void dfs2(int d,bool *vis){
	if(d>k){
		int sum=0,res=0;
		dis[0]=inf;
		for(int i=1;i<=n;i++){
			if(vis[i]&&vis[fa[i]]==0) sum++,dis[i]=0;
			else dis[i]=inf;
		}
		//cout<<sum<<"\n";
		if(sum<=2){
			for(int i=1;i<=n;i++){
				if(vis[i]) js(i);
			}
			for(int i=1;i<=n;i++) res=max(res,dis[i]);
			ans=min(ans,res);
		}
		//cout<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			//cout<<i<<"\n";
			dfs2(d+1,vis);
			vis[i]=0;
		}
	}
	return ;
}
void solve(){
	cin>>n>>k;
	ans=inf;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	dfs1(0,1);
	//for(int i=1;i<=n;i++)  cout<<fa[i]<<" ";
	dfs2(1,vis);
	cout<<ans<<"\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/
