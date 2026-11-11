#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const long long INF=1e18;
long long c,t,n,k,res,sz[N],dp[N];
vector<long long> g[N];
void dfs1(long long u,long long fa,long long dis){
	sz[u]=1,dp[1]+=dis;
	for(int i=0;i<g[u].size();i++){
		long long v=g[u][i];
		if(v==fa) continue;
		dfs1(v,u,dis+1);
		sz[u]+=sz[v];
	}
}
void dfs2(long long u,long long fa){
	for(int i=0;i<g[u].size();i++){
		long long v=g[u][i];
		if(v==fa) continue;
		dp[v]=dp[u]+sz[u]-2*sz[v];
		dfs2(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		res=INF;
		for(int i=1;i<=n;i++)
			g[i].clear();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			long long u,v; cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1,0,0);
		dfs2(1,0);
		for(int i=1;i<=n;i++)
			res=min(res,dp[i]);
		cout<<res<<'\n';
	}
	return 0;
}
/*
开始看成距离和了还以为如此模板
然后发现是距离 min
但是打了的换根 dp 也不能浪费 
毕竟只剩 10min 了 

我写的什么东西 

结算：100+[40,100]+[8,24]+eps 
*/
