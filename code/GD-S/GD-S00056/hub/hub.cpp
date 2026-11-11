#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
int c, T;
int n, m;
basic_string<int> g[N];
int deg[N], col[N], vis[N];
int ans[N];
void clear(){
	for(int i = 0; i <= n; i++) g[i].clear(), deg[i] = 0, ans[i] = n;
}
queue<int> p, q;
int dfs(int x, int fx){
	col[x] = 1;
	int sum = 1;
	for(int y : g[x]) if(y != fx) sum += dfs(y, x);
	return sum;
}
void solve(int x, int y){
//	cout << x << "---" << y << '\n';
	for(int i = 1; i <= n; i++) deg[i] = g[i].size();
	deg[x]--; deg[y]--;
	for(int i = 1; i <= n; i++) col[i] = vis[i] = 0;
	int siz = dfs(x, y);
	while(!q.empty()) q.pop();
	while(!p.empty()) p.pop();
	for(int i = 1; i <= n; i++) if(deg[i] <= 1) q.push(i), vis[i] = 1;
	int del = 0, de1 = 0, de0 = 0;
	for(int w = 1; w <= n; w++){
		while(!q.empty()){
			int u = q.front();
			q.pop();
			del++;
			if(col[u] == 1) de1++;
			else de0++;
			for(int v : g[u]){
				if(x == u && y == v) continue;
				if(x == v && y == u) continue;
				deg[v]--;
				if(vis[v] || deg[v] > 1) continue;
				vis[v] = 1;
				p.push(v);
			}
		}
		swap(p, q);
//		cout << w << ' ' << del << ' ' << (de1 == siz) << ' ' << (de0 == n-siz) << '\n';
		ans[w] = min(ans[w], n-del+(de1 == siz)+(de0 == n-siz));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> m;
		clear();
		for(int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			g[x] += y;
			g[y] += x;
		}
		for(int i = 1; i <= n; i++){
			for(int j : g[i]){
				if(i < j) solve(i, j);
			}
		}
		for(int i = 0; i <= n; i++){
//			cout << i << ' ' << ans[i] << "?\n";
			if(ans[i] <= m){
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
} 
