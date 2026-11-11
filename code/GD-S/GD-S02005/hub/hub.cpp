#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
vector<int> g[19];
bool b[19];
bool vis[19];
int dis[19][19];
int check(){
	memset(vis,0,sizeof vis);
	int cnt = 0;	
	for(int i = 1;i<=n;++i){
		if(vis[i] == 0&&b[i] == 1){
			cnt++;
			queue<int> q;
			q.push(i);
			while(q.size()){
				int u = q.front();q.pop();
				for(auto v:g[u]){
					if(vis[v] == 0&&b[v] == 1){
						vis[v] = 1;
						q.push(v);
					}
				}
			} 
		}
	}
	return cnt;
}
int ans = 1e18;
void work(int o){
	if(o == n+1){
		int p = 0;
		for(int i = 1;i<=n;++i){
			if(b[i]) p++;
		}
		if(p!=k) return ;
		if(check()>2) return ;
		int mx = 0;
		for(int i = 1;i<=n;++i){
			int mn = 1e18;
			for(int j = 1;j<=n;++j){
				if(!b[j]) continue;
				mn = min(mn,dis[i][j]);
			}
			mx = max(mx,mn);
		}
		ans = min(ans,mx);
		return ;
	}
	work(o+1);
	b[o] = 1;
	work(o+1);
	b[o] = 0;	
}
void lu(int i){
	queue<int> q;
	memset(vis,0,sizeof vis);
	q.push(i);
	dis[i][i] = 0;
	vis[i] = 1;
	while(q.size()){
		int u = q.front();q.pop();
		for(auto v:g[u]){
			if(vis[v]) continue;
			dis[i][v] = dis[i][u]+1;
			vis[v] = 1;
			q.push(v);
		}
	}
}
void solve(){
	cin>>n>>k;
	memset(dis,0,sizeof dis);
	for(int i = 1;i<=n;++i) g[i].clear();
	for(int i = 1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1;i<=n;++i){
		lu(i);
	}
	ans = 1e18;
	work(1);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
}
