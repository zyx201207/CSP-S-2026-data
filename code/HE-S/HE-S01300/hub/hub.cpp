#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c , t , n , k;
int ans ;
vector<int> edge[N];
bool vis[N];
bool f[N] , f2[N];
void dfs1(int x , int fa){
	f[x] = 1;
	for(int i = 0 ; i <= edge[x].size() ; i ++){
		int y = edge[x][i];
		if(y == fa) continue;
		if(vis[y]) dfs1(y , x);
	}
}
int dfs2(int x , int dep , int fa){
	if(vis[x]) return dep;
	else if(f2[x]) return 1e9;
	f2[x] = 1;
	int sum = 1e9;
	for(int i = 0 ; i <= edge[x].size() ; i ++){
		int y = edge[x][i];
		if(y == fa) continue;
		sum = min(ans , dfs2(y , dep + 1 , x));
	}
	return sum;
}
void dfs(int x , int k){
	if(k == 0){
		for(int i = 1 ; i <= n ; i ++) f[i] = 0;
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(vis[i] && !f[i]) cnt ++ , dfs1(i , 0);
		}
		if(cnt > 2) return;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= n ; j ++) f2[j] = 0; 
			ans = max(ans , dfs2(i , 0 , 0));
		}
		return;
	}
	else if(x > n && k) return;
	vis[x] = 1;
	dfs(x + 1 , k - 1);
	vis[x] = 0;
	dfs(x + 1 , k);
}
int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin >> c >> t;
	int u , v;
	while(t --){
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i ++){
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1 , k);
		cout << ans << "\n";
	}
	return 0;
}
