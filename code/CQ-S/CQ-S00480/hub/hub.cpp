#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5,INF=1e18;
int c,t,n,k,timer,ans=INF;
vector<int> vt[N+5];
bool vis[N+5];
int dis[N+5];
queue<int> q;
inline void bfs1(int s){
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto v:vt[x]){
			if(dis[v]==INF&&vis[v]){
				dis[v]=dis[x]+1;
				q.push(v);
			}
		}
	}
}
inline int bfs2(){
	int res=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto v:vt[x]){
			if(dis[v]==INF){
				if(vis[v]) dis[v]=dis[x];
				else dis[v]=dis[x]+1;
				res=max(res,dis[v]);
				q.push(v);
			}
		}
	}
	return res;
}
inline void dfs(int x){
	if(x>k){
		int cnt=0;
		for(int i=1;i<=n;i++) dis[i]=INF;
		for(int i=1;i<=n;i++) if(vis[i]&&dis[i]==INF) bfs1(i),cnt++;
		if(cnt>2) return;
		for(int i=1;i<=n;i++) dis[i]=INF;
		for(int i=1;i<=n;i++) if(vis[i]){
			q.push(i);
			dis[i]=0;
		}
		ans=min(ans,bfs2());
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=INF;
		cin>>n>>k;
		for(int i=1,a,b;i<n;i++){
			cin>>a>>b;
			vt[a].push_back(b);
			vt[b].push_back(a);
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
} 
