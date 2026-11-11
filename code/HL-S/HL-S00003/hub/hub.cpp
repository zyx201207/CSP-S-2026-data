#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000;
int c, T, n, k, b[N], tot, vis[N];
int idx, h[N], e[2*N], nxt[2*N];
void add(int u, int v){
	nxt[++idx] = h[u];
	h[u] = idx;
	e[idx] = v;
}
int dfs(int u, int fa){
	int s = 1;
	vis[u] = tot;
	for(int i = h[u]; i; i = nxt[i]){
		int v = e[i];
		if(v == fa || b[v] == 0) continue;
		s += dfs(v, u); 
	}
	return s;
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) h[i] = 0;
		idx = 0;
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		int res = 0x3f3f3f3f;
		for(int t = 0; t < (1<<n); t++){
			int s = 0;
			for(int i = 1; i <= n; i++){
				if(((t>>(i-1))&1) == 1) b[i] = 1, s++;
				else b[i] = 0;
			}
			if(s != k) continue;
			tot++;
			int sum = 0, o = 2;
			for(int i = 1; i <= n; i++){
				if(b[i] && vis[i] != tot && o) sum += dfs(i, i), o--;
			}
			if(o != 0 || sum != k) continue;
			queue<pair<int, int> >q;
			for(int i = 1; i <= n; i++) if(b[i]) q.push({i, 0});
			int ans = 0;
			while(q.size()){
				int u = q.front().first, dis = q.front().second;
				q.pop();
				ans = max(ans, dis);
				for(int i = h[u]; i; i = nxt[i]){
					int v = e[i];
					if(b[v]) continue;
					b[v] = 1;
					q.push({v, dis+1});
				}
			} 
			res = min(res, ans);
		}
		cout << res << '\n';
	}
	return 0;
}