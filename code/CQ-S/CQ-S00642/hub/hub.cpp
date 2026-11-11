#include<bits/stdc++.h>
#define int long long
#define popcount __builtin_popcount
using namespace std;
namespace SubTask1to3{
	const int maxn=1e2+10;
	struct DSU{
		int fa[maxn];
		void init(int n){
			for(int i=1;i<=n;i++)fa[i]=i;
		}
		int find(int u){
			if(u==fa[u])return u;
			return fa[u]=find(fa[u]);
		}
		bool merge(int u,int v){
			u=find(u);v=find(v);
			if(u==v)return false;
			fa[u]=v;return true;
		}
	}D;
	vector<int>G[maxn];int dis[maxn];
	void solve(){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<=n-1;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans=n;
		for(int S=2;S<(2<<n);S+=2){
			if(popcount(S)!=k)continue;
			D.init(n);
			for(int u=1;u<=n;u++)
				if(S>>u&1)for(int v:G[u])
					if(S>>v&1)D.merge(u,v);
			int cnt=0;
			for(int u=1;u<=n;u++)
				if(S>>u&1)cnt+=D.find(u)==u;
			if(cnt>2)continue;
			memset(dis,0x3f,sizeof dis);
			queue<int>q;
			for(int u=1;u<=n;u++)
				if(S>>u&1)q.push(u),dis[u]=0;
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int v:G[u])
					if(dis[v]>dis[u]+1)
						dis[v]=dis[u]+1,q.push(v);
			}
			int res=0;
			for(int u=1;u<=n;u++)
				res=max(res,dis[u]);
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
}
namespace SubTask4to20{
	const int maxn=1e6+10;
	vector<int>G[maxn];
	int dp1[maxn],dp2[maxn],fa[maxn],g[maxn],dis[maxn],rk[maxn],vis[maxn];
	void dfs1(int u,int f){
		dp1[u]=dp1[fa[u]=f]+1;
		for(int v:G[u])
			if(v!=f)dfs1(v,u);
	}
	void dfs2(int u,int f){
		dp2[u]=dp2[fa[u]=f]+1;
		for(int v:G[u])
			if(v!=f)dfs2(v,u);
	}
	void solve(){
		int n,k;cin>>n>>k;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<=n-1;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1,0);
		int s=1;
		for(int i=2;i<=n;i++)
			if(dp1[s]<dp1[i])s=i;
		dfs2(s,0);
		int t=s;
		for(int i=2;i<=n;i++)
			if(dp2[t]<dp2[i])t=i;
		int tot=0;
		for(int u=t;u;u=fa[u])g[++tot]=u;
		vector<int>op;
		if(k==1){
			op.push_back(g[tot/2]);
		}else{
			int p=(tot/2+1)/2,q=3*tot/4;
			for(int i=1;i<=tot;i++)rk[i]=i;
			sort(rk+1,rk+tot+1,[&](int x,int y){return min(abs(x-p),abs(x-q))<min(abs(y-p),abs(y-q));});
			for(int i=1;i<=min(k,tot);i++)op.push_back(g[rk[i]]),vis[g[rk[i]]]=true;
			for(int i=1;i<=k-min(k,tot);i++)
				if(!vis[i])op.push_back(i);
		}
		memset(dis,0x3f,sizeof dis);
		queue<int>q;
		for(int u:op)q.push(u),dis[u]=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v:G[u])
				if(dis[v]>dis[u]+1)
					dis[v]=dis[u]+1,q.push(v);
		}
		int res=0;
		for(int u=1;u<=n;u++)
			res=max(res,dis[u]);
		cout<<res<<'\n';
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		if(1<=c&&c<=3)SubTask1to3::solve();
		else SubTask4to20::solve();
	}
	return 0;
}
