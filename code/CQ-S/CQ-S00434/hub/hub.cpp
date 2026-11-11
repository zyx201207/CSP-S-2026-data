#include<bits/stdc++.h>
using namespace std;
#define int long long
int tt;
namespace Quirrel{
//tmp
int x,y;
//input
int n,m;
vector<int>g[100];
//dfs
int f[100],vis[100],ans,minn;
void dfs1(int x,int fa){
	if(f[x]==0)return ; 
	int y;vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		y=g[x][i];
		if(y==fa)continue;
		dfs1(y,x);
	}
}
void dfs2(int x,int fa,int dis){
	if(f[x]==1)minn=min(minn,dis);
	int y;
	for(int i=0;i<g[x].size();i++){
		y=g[x][i];
		if(y==fa)continue;
		dfs2(y,x,dis+1);
	}
} 
void dfs(int x){
	if(x==n+1){
		int cnt=0,cnt1=0,maxx=0;
		for(int i=1;i<=n;i++)cnt+=f[i];
		if(cnt!=m)return ;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(f[i]){
				cnt1++;dfs1(i,0);
			}
		}
		if(cnt1!=2)return ;
		for(int i=1;i<=n;i++){
			minn=n;dfs2(i,0,0);
			maxx=max(maxx,minn);
		}
		ans=min(ans,maxx);
		return ;
	}
	f[x]=1;dfs(x+1);
	f[x]=0;dfs(x+1);
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	ans=n;dfs(1);cout<<ans<<"\n";
	return 0;
}
//
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>tt>>tt;
	while(tt--)Quirrel::main();
	return 0;
}
/*
不会高档分
把这个15pts写了

Even the darkest night will end and the sun will rise. 
*/
