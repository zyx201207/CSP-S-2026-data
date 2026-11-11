/**********************
 ~AUTHOR BY "ILWF^_^" 
 ~author by "ILWF^_^" 
**********************/
#include<bits/stdc++.h>
#define LM LLONG_MAX
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 105;
const ll mod = 1e9 + 7;
const ll INF = 1e18;
vector<ll> g[N];
ll vis[N] , isch[N] , dis[N];
ll n , k;
ll bfs(){
	fill(vis , vis + n + 1 , 0);
	ll cnt = 0;
	for(int i = 1;i <= n;i++){
		if(isch[i] == 1 && vis[i] == 0){
			cnt++;
			queue<ll> q;
			q.push(i);
			while(!q.empty()){
				ll P = q.front();
				q.pop();
				for(auto y : g[P]){
					if(vis[y] == 1 || isch[y] == 0) continue;
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
	if(cnt > 2) ILW INF;
	fill(vis , vis + n + 1 , 0);
	fill(dis , dis + n + 1 , INF);
	queue<ll> q;
	for(int i = 1;i <= n;i++) if(isch[i] == 1) dis[i] = 0 , vis[i] = 1 , q.push(i);
	while(!q.empty()){
		ll P = q.front();
		q.pop();
		for(auto y : g[P]){
			if(vis[y] == 1) continue;
			vis[y] = 1;
			dis[y] = dis[P] + 1;
			q.push(y);
		}
	}
	ll res = 0;
	for(int i = 1;i <= n;i++) res = max(res , dis[i]);
	ILW res; 
}
ll ans = 0;
void dfs(ll x , ll ch){
	if(x == n + 1){
		if(ch == k) ans = min(ans , bfs());
		ILW;
	}
	dfs(x + 1 , ch);
	isch[x] = 1;
	dfs(x + 1 , ch + 1);
	isch[x] = 0;
}
void solve(){
	cin >> n >> k;
	ans = INF;
	for(int i = 1;i <= n;i++) g[i].clear();
	for(int i = 1;i < n;i++){
		ll u , v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1 , 0);
	cout << ans << '\n';
}
int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c , t = 1;
	cin >> c >> t;
	while(t--) solve();
	ILW F; 
}
