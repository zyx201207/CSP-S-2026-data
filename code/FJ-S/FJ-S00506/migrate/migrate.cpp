#include <bits/stdc++.h> 
#define i64 long long 
using namespace std; 
const int N = 2e6 + 5; 
const int INF = 0x3f3f3f3f; 
int ID, tim, n, dis[N], f[N];   
i64 d, x[N], ans;  
void bfs(int s) {
	queue<int> q; 
	q.push(s); 
	for(int i = 1; i <= n; i++) dis[i] = INF, f[i] = 0;  
	f[s] = 1; 
	dis[s] = 0; 
	while(!q.empty()) {
		int u = q.front(); q.pop(); 
		for(int v = 1; v <= n; v++) {
			if(u == v || abs(x[u] - x[v]) > d) continue; 
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1; 
				f[v] = f[u];  
				q.push(v); 
			}
			else if(dis[v] == dis[u] + 1) f[v]++; 
		}
	} 
	for(int i = 1; i <= n; i++) if(f[i] == 2) ans++; 
	return; 
}
void Main() { 
	ans = 0; 
	scanf("%d %lld", &n, &d);  
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]); 
	} 
	for(int i = 1; i <= n; i++) {
		bfs(i); 
	}
	printf("%lld\n", ans / 2); 
	return; 
}
int main() {
	freopen("migrate.in", "r", stdin); 
	freopen("migrate.out", "w", stdout); 
	scanf("%d %d", &ID, &tim); 
	while(tim--) Main(); 
	return 0; 
}
