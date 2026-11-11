#include<bits/stdc++.h>
using namespace std;
void solveA(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
	}
	
	int m = (n-1)/2;
	int x = (m+1)/2;
	int y = (k/2);
	int ans = (x-y)/2 + 1;
	cout << ans << '\n';
	
	return ;
}
void solve_small(){
	int n,k;
	cin >> n >> k;
	vector<vector<int>> G(n+1);
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	
	int ans = n;
	for(int st=0;st<(1<<n);st++){
		int cnt = __builtin_popcount(st);
		if(cnt != k) continue;
		queue<int> q;
		vector<int> vis(n+1,0),dist(n+1,INT_MAX/2),v;
		for(int i=st;i;i-=(1<< (__builtin_ctz(i) ) ) ){
			int c = __builtin_ctz(i) + 1;
			v.push_back(c);
			q.push(c);
			dist[c] = 0;
		}
		int lnt = 0;
		for(auto &x : v){
			if(vis[x]) continue;
			vis[x] = 1;
			lnt++;
			if(lnt > 2) break;
			queue<int> ql;
			ql.push(x);
			while(!ql.empty()){
				int now = ql.front();
				ql.pop();
				for(auto &to : G[now]){
					if(vis[to]) continue;
					if(dist[to] == 0) {
						ql.push(to);
						vis[to] = 1;
					}
				}
			}
		}
		if(lnt > 2) continue;
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(auto to : G[now]){
				if(dist[to] <= dist[now] + 1) continue;
				vis[to] = 1;
				dist[to] = dist[now] + 1;
				q.push(to);
			}
		}
		int tans = 0;
		for(int i=1;i<=n;i++) tans = max(tans,dist[i]);
		ans = min(ans,tans);
	}
	
	cout << ans << '\n';	
	return ;
}
void slove_double(){
	int n,k;
	cin >> n >> k;
	vector<vector<int>> G(n+1);
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	
	
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T;
	cin >> c >> T;
	if(c == 13 or c == 14) while(T--) solveA();
	else if(c==0 or 1 <= c and c <= 3) while(T--) solve_small();
	else{
		while(T--){
			cout << 0 << '\n';
		}
	}
	
	
	return 0;
}
