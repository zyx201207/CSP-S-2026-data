#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
const int N=1e6+10;
vector<int> mp[N];
int dis[N];
int vis[N];
int tag[N];
void dfs(int u){
	vis[u]=1;
	for(auto v:mp[u]){
		if(dis[v]) continue;
		if(vis[v]) continue;
		dfs(v);
	}
}
void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<n;i++) mp[i].clear();
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	int ans=inf;
	for(int S=0;S<(1<<n);S++){
		for(int i=0;i<n;i++){
			dis[i]=inf;
			vis[i]=0;
		}
		vector<int> g;
		for(int i=0;i<n;i++){
			if(S>>i&1){
				g.push_back(i);
				dis[i]=0;
			}
		}
		if(g.size()!=m) continue;
		int cnt=0;
		for(auto v:g){
			if(!vis[v]){
				cnt++;
				dfs(v);
			}
		}
		if(cnt<=2){
			//cout<<S<<"\n";
			queue<int> q;
			for(auto v:g) q.push(v);
			while(q.size()){
				int u=q.front();q.pop();
				for(auto v:mp[u]){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
			int res=0;
			for(int i=0;i<n;i++) res=max(res,dis[i]);
			//for(int i=0;i<n;i++) cout<<dis[i]<<" ";cout<<"\n";
			ans=min(ans,res);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}
