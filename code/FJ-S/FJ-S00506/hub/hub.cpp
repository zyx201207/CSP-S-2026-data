#include <bits/stdc++.h>
using namespace std; 
const int N = 1000 + 5;  
int ID, tim, n, K, ans, vis[N], V[N], D[N];    
vector<int> G[N]; 
void chk(int u, int p) {
	if(vis[u]) V[u] = 1; 
	else return; 
	for(int v : G[u]) {
		if(v != p) chk(v, u);  
	}
	return; 
} 
void bfs(int u, int p, int dist) { 
	for(int v : G[u]) {
		if(v == p) continue; 
		if(vis[v]) D[v] = 0; 
		else D[v] = min(D[v], dist + 1), bfs(v, u, dist + 1);  
	} 
	return; 
}
int solve() {
	for(int i = 1; i <= n; i++) {
		V[i] = 0; 
		if(!vis[i]) D[i] = n; 
		else D[i] = 0; 
	}	
	int cnt = 0; 
	for(int i = 1; i <= n; i++) {
		if(V[i] || !vis[i]) continue; 
		chk(i, i); 
		cnt++; 
		if(cnt > 2) return n; 
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) bfs(i, i, 0); 
	} 
	int mxdis = 0;  
	for(int i = 1; i <= n; i++) mxdis = max(mxdis, D[i]); 
	return mxdis; 
}
void dfs(int step, int cnt) {
	if(step == n + 1) {
		ans = min(ans, solve()); 
		return; 
	} 
	if(cnt == K) dfs(step + 1, cnt); 
	else {
		vis[step] = 1; 
		dfs(step + 1, cnt + 1); 
		vis[step] = 0; 
		dfs(step + 1, cnt); 
	}
	return; 
}
void Main() {
	scanf("%d %d", &n, &K); 
	for(int i = 1; i <= n; i++) vis[i] = 0, G[i].clear(); 
	ans = n; 
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v); 
		G[u].push_back(v); 
		G[v].push_back(u); 
	} 
	if(n <= 10) {
		dfs(1, 0); 
		printf("%d\n", ans); 
		return; 
	} 
	for(int i = 1; i <= n; i++) { 
		vis[i] = 1;
		for(int j = 1; j <= n; j++) {
			if(j == i) continue; 
			vis[j] = 1; 
			ans = min(ans, solve()); 
			vis[j] = 0; 
		} 
		vis[i] = 0; 
	} 
	printf("%d\n", ans);
	return; 
}
int main() {
	freopen("hub.in", "r", stdin); 
	freopen("hub.out", "w", stdout); 
	scanf("%d %d", &ID, &tim); 
	while(tim--) Main(); 
	return 0; 
}
