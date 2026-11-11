#include<bits/stdc++.h>
#define int long long
#define rint register int
#define endl '\n'
using namespace std;
const int N=1e5+5;
int C,T;
int n,K;
int ans=-1;
int fa[N];
bitset<N> vis;
vector<int> G[N];
int dis[N];
inline int find(const rint& x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
inline bool check(){
	for(rint i=1;i<=n;++i)
		fa[i]=i;
	
	for(rint u=1;u<=n;++u)
		if(vis[u])
			for(auto v:G[u])
				if(vis[v]) fa[find(v)]=find(u);
	rint cnt=0;
	for(rint i=1;i<=n;++i)
		if(vis[i]) cnt+=find(i)==i;
	
	return cnt<=2; 
}
inline void bfs(const rint& s){
	memset(dis,0,sizeof dis);
	queue<int> q;
	q.push(s);
	
	bitset<N> vis;
	vis[s]=1;
	while(!q.empty()){
		rint u=q.front();q.pop();
		for(auto v:G[u]) 
			if(!vis[v]) dis[v]=dis[u]+1,q.push(v),vis[v]=1;
	}
}
inline void dfs(const rint& k,const rint& cnt){
	if(cnt>K) return;
	if(k==n+1){
		if(cnt<K) return;
		if(check()){
		
			for(rint i=1;i<=n;++i)
				if(!vis[i]) bfs(i);
			
			rint res=0x3f3f3f3f3f3f3f3f;
			for(rint i=1;i<=n;++i)
				if(vis[i]) res=min(res,dis[i]);
			ans=max(res,ans);
		}
		return;
	}
	if((n-k+1==cnt)){
		vis[k]=1;
		dfs(k+1,cnt+1);
		vis[k]=0;
		return;
	}
	dfs(k+1,cnt);
	vis[k]=1;
	dfs(k+1,cnt+1);
	vis[k]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>C>>T;
	
	while(T--){
		ans=-1;
		for(rint i=1;i<=n;++i)
			G[i].clear();
		
		cin>>n>>K;
		
		for(rint i=1;i<n;++i)
		{
			rint u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		
		cout<<ans<<endl;
	}
	return 0;
}

