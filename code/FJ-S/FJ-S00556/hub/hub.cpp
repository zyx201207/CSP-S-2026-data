#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int c,t;
int n,k;
vector<int> g[(int)1e6+5];
bool flag[15];
bool vis[15];
int dis[15];
int ans;
void dfs2(int now,int fath){
	vis[now]=true;
	for(int i=0;i<g[now].size();i++){
		if(g[now][i]==fath||!flag[g[now][i]]) continue;
		dfs2(g[now][i],now);
	}
}
void dfs3(int now,int fath,int dep){
	dis[now]=min(dis[now],dep);
	for(int i=0;i<g[now].size();i++){
		if(g[now][i]==fath) continue;
		dfs3(g[now][i],now,dep+1);
	}
}
void dfs(int stp){
	if(stp>n){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++) vis[i]=false;
		for(int i=1;i<=n;i++){
			if(!flag[i]) continue;
			cnt1++;
			if(!vis[i]){
				cnt2++;
				dfs2(i,0);
			}
		}
		if(cnt1!=k||cnt2>2) return;
		for(int i=1;i<=n;i++) dis[i]=1e9;
		for(int i=1;i<=n;i++){
			if(flag[i]){
				dfs3(i,0,0);
			}
		}
		int maxn=0;
		for(int i=1;i<=n;i++) maxn=max(maxn,dis[i]);
		ans=min(ans,maxn);
		return;
	}
	flag[stp]=true;
	dfs(stp+1);
	flag[stp]=false;
	dfs(stp+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=1e9;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
I've tried my best.

Thanks all who gave me the chance to take part in the contest.
*/

