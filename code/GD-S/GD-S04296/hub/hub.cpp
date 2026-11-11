#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100,INF = 1e9;
int n,k,ans;
bool use[N],re1[N],re2[N];
int dis[N][N];
vector<int> g[N];
void update(){
	int mx = 0;
	for(int i = 1;i <= n;i++){
		if(!use[i]){
			int mn = INF;
			for(int j = 1;j <= n;j++){
				if(use[j]){
					mn = min(mn,dis[i][j]);
				}
			}
			mx = max(mx,mn);
		}
	}
	ans = min(ans,mx);
}
void check(){
	for(int i = 1;i <= n;i++) re1[i] = re2[i] = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		cnt += use[i];
	}
	if(cnt != k) return ;
	queue<int> q1,q2;int p1 = 0,p2 = 0,sum1 = 0,sum2 = 0;
	for(int i = 1;i <= n;i++){
		if(use[i]) p1 = i;
	}
	q1.push(p1);
	re1[p1] = 1;
	while(q1.size()){
		int u = q1.front();q1.pop();
		for(int v : g[u]){
			if(re1[v]) continue;
			if(use[v]){
				re1[v] = 1;
				q1.push(v);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(re1[i] && use[i]){
			sum1++;
		}
		if(use[i] && !re1[i]) p2 = i;
	}
	if(sum1 == cnt){
		update();
		return ;
	}
	re2[p2] = 1;
	while(q2.size()){
		int u = q2.front();q2.pop();
		for(int v : g[u]){
			if(re2[v]) continue;
			if(use[v] && !re1[v]){
				re2[v] = 1;
				q2.push(v);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(re2[i] && use[i] && !re1[i]){
			sum2++;
		}
	}
	if(sum1 + sum2 != cnt) return ;
	update();
	return ; 
}
void brute(int x){
	if(x > n){
		check();
		return ;
	}
	use[x] = 1;
	brute(x+1);
	use[x] = 0;
	brute(x+1);
}
int vis[N],got[N]; 
void dfs1(int u){
	for(int v : g[u]){
		if(got[v]) continue;
		vis[v] = vis[u] + 1;
		got[v] = 1;
		dfs1(v);
	}
}
void solve(){
	cin>>n>>k;
	for(int i = 1;i < n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	//init
	ans = INF;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			dis[i][j] = INF;
		}
		use[i] = 0;
	}
	for(int i = 1;i <= n;i++){
		fill(vis+1,vis+n+1,0);
		fill(got+1,got+n+1,0);
		dis[i][i] = 0;
		got[i] = 1;
		dfs1(i);
		for(int j = 1;j <= n;j++){
			dis[i][j] = vis[j];
		}
	}
	
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	brute(1);
	cout<<ans<<"\n";
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}
