#include<bits/stdc++.h>
using namespace std;
#define ll int
#define lpx 1000005
ll test,n,t,k,dist[lpx],zhong=0,zhong2=0,maxn=0;
bool vis[lpx];
vector<ll>linker[lpx];
void dfs(ll u,ll fa){
	for(auto v:linker[u]){
		if(v==fa)continue;
		dist[v]=dist[u]+1;
		if(dist[v]>dist[zhong])zhong=v;
		dfs(v,u);
	}
}
void dfs2(ll u,ll fa){
	for(auto v:linker[u]){
		if(v==fa)continue;
		dist[v]=dist[u]+1;
		maxn=max(maxn,dist[v]);
		if(dist[v]>dist[zhong2])zhong2=v;
		dfs2(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>test>>t;
	while(t--){
		cin>>n>>k;
		if(n==k){cout<<0<<"\n";continue;}
		zhong =0;
		zhong2=0;
		maxn=0;
		for(ll i=1;i<=n;++i){linker[i].clear();dist[i]=0;}
		for(ll i=1,a,b;i<=n-1;++i){
			cin>>a>>b;
			linker[a].push_back(b);
			linker[b].push_back(a);
		} 
		dfs(1,0);
		memset(dist,0,sizeof(dist));
		dfs2(zhong,0);
		cout<<maxn/k<<"\n";
	}
	return 0;
}
