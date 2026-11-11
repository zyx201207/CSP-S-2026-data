#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,k;
struct edge{int v,ne;}e[2000005];
int idx,h[1000005];
inline void add(int u,int v){
	e[++idx]={v,h[u]};h[u]=idx;
	e[++idx]={u,h[v]};h[v]=idx;
}
int f[1000005];
inline int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int vis[1000005];
inline bool check(){
	int sum=k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int u=1;u<=n;u++)
		if(vis[u])
			for(int i=h[u];i;i=e[i].ne){
				int v=e[i].v;
				if(!vis[v]||find(u)==find(v))continue;
				f[find(u)]=find(v),sum--;
			}
	return (sum<=2);
}
stack<int>st;
int Vis[1000005];
inline void init(){while(!st.empty()){Vis[st.top()]=0;st.pop();}}
inline int bfs(int u){
	queue<pair<int,int> >q;
	q.push({u,0});
	while(!q.empty()){
		pair<int,int>p=q.front();q.pop();
		int u=p.first,dis=p.second;
		if(Vis[u])continue;
		Vis[u]=1;st.push(u);
		if(vis[u]){init();return dis;}
		for(int i=h[u];i;i=e[i].ne){
			int v=e[i].v;
			if(Vis[v])continue;
			q.push({v,dis+1});
		}
	}
	return 0;
}
inline int dis(){
	int mx=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		mx=max(mx,bfs(i));
	}
	return mx;
}
int ans;
inline void dfs(int u,int sum){
	if(u>n){
		if(sum==k&&check())ans=min(ans,dis());
		return ;
	}
	vis[u]=0;
	dfs(u+1,sum);
	vis[u]=1;
	dfs(u+1,sum+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			add(u,v);
		}
		ans=INT_MAX,dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=idx;i++)e[i]={0,0};
		for(int i=1;i<=n;i++)h[i]=0;idx=0;
	}
	return 0;
}
