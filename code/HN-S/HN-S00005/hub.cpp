#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 5;

int c_, n, k, dis[N], ans, fa[N], siz[N], lst[N];
vector<int> g[N];
bool f[N];
queue<int> q;

int Find(int x){
	return (fa[x] == x ? x : fa[x] = Find(fa[x]));
}

void fusion(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy){
		if(siz[fx] < siz[fy]){
			swap(fx, fy);
		}
		fa[fy] = fx, siz[fx] += siz[fy];
	}
}

void bfs(){
	for(int i = 1; i <= n; i++){
		if(f[i]){
			dis[i] = 0;
			q.push(i);
		}else{
			dis[i] = 1e9;
		}
	}
	while(!q.empty()){
		int item = q.front();
		q.pop();
		for(int it : g[item]){
			if(dis[it] == 1e9){
				dis[it] = dis[item] + 1;
				q.push(it);
			}
		}
	}
	int Max = 0;
	for(int i = 1; i <= n; i++){
		Max = max(Max, dis[i]);
	}
	ans = min(ans, Max);
}

void ck(){
	for(int i = 1; i <= n; i++){
		fa[i] = i, siz[i] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(f[i]){
			for(int it : g[i]){
				if(f[it]){
					fusion(i, it);
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(f[i]) cnt += (Find(i) == i);
	}
	if(cnt > 2){
		return;
	}
	bfs();
}

void solve_dfs(int x, int cnt){
	if(cnt > k){
		return;
	}
	if(k - cnt > n - x + 1){
		return;
	}
	if(x == n){
		if(cnt == k){
			ck();
		}
		return;
	}
	f[x] = 1;
	solve_dfs(x + 1, cnt + 1);
	f[x] = 0;
	solve_dfs(x + 1, cnt);
}

void dfs(int u, int fa){
	dis[u] = dis[fa] + 1;
	lst[u] = fa;
	for(int it : g[u]){
		if(it != fa){
			dfs(it, u);
		}
	}
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	for(int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(c_ == 1){
		ans = 1e9;
		solve_dfs(1, 0);
		cout << ans << '\n';
		return;
	}
	if(n <= 3 || n == k){
		cout << n - k << '\n';
		return;
	}
	if(c_ == 13 || c_ == 14){
		int D = (n + 1) / 2;
		if(k >= n / 2){
			cout << "1\n";
			return;
		}
		int x = (D - k + 4) / 3;
		cout << (D - x + 1) / 2 << '\n';
		return;
	}
	fill(dis, dis + n + 1, 0);
	dis[0] = -1;
	dfs(1, 0);
	int rt = 0;
	for(int i = 1; i <= n; i++){
		if(dis[i] > dis[rt]){
			rt = i;
		}
	}
	dfs(rt, 0);
	rt = 0;
	for(int i = 1; i <= n; i++){
		if(dis[i] > dis[rt]){
			rt = i;
		}
	}
	int D = dis[rt];
	for(int i = 1; i <= D / 2; i++){
		rt = lst[rt];
	}
//	cout << D << '\n';
//	cout << (D - k + 4) / 3 << '\n';
	int x = (D - k + 4) / 3;
	cout << (D - x + 1) / 2 << '\n';
//	dfs()
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> c_ >> T;
	while(T--){
		solve();
	} 
	return 0;
}
