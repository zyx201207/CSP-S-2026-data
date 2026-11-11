#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int N=1e6+5;
int n,k,dis[N],fa[N];
bool vis[N],vis1[N];
vector<int>g[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int t;
	ll d;
};
bool operator < (const node& i,const node& j){
	return i.d>j.d;
}
priority_queue<node>pq;
void add(int u,int v){
	int fu=find(u),fv=find(v);
	if(fu!=fv) fa[fu]=fv;
}
void dij(){
	while(!pq.empty()){
		node p=pq.top();
		pq.pop();
		for(int v:g[p.t]){
			if(p.d+1<dis[v]){
				dis[v]=p.d+1;
				pq.push({v,dis[v]});
			}
		} 
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);
	}
	int p=1<<n;
	int ans=INT_MAX;
	for(int t=0;t<p;t++){
		int x=t;
		int cnt=0;
		for(int i=1;i<=n;i++) vis[i]=0,fa[i]=i;
		for(int i=1;i<=n;i++){
			if(x&1) cnt++,vis[i]=1;
			x>>=1;
		}
		if(cnt!=k) continue;
		for(int u=1;u<=n;u++) for(int v:g[u]) if(vis[u]&&vis[v]) add(u,v);
		for(int i=1;i<=n;i++) vis1[i]=0;
		for(int i=1;i<=n;i++) vis1[find(i)]=1;
		int tot=0;
		for(int i=1;i<=n;i++) if(vis[i]&&vis1[i]) tot++;
		if(tot<=2){
			for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
			for(int i=1;i<=n;i++) if(vis[i]) pq.push({i,0}),dis[i]=0;
			dij();
			int maxn=0;
			for(int i=1;i<=n;i++) maxn=max(maxn,dis[i]);
			ans=min(ans,maxn);
		} 
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
