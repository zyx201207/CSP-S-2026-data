#include<bits/stdc++.h>
using namespace std;

const int N = 20;
const int inf = 0x3f3f3f3f;

int c, t;
int n, k;
int fa[N][20];
int dep[N];
int uf[N];
int vis[N];


vector <int> edge[N];

int find(int x){
	return x == uf[x] ? x : uf[x] = find(uf[x]);
}

void dfs(int u, int f){
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	for(auto v : edge[u]){
//		int v = edge[u][i];
		if(v == f) continue ;
		dfs(v, u);
	}
	return ;
}

void prep(){
	for(int j = 1; j <= 19; j++){
		for(int i = 1; i <= n; i++){
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
	return ;
}

int lca(int x, int y){
	if(x == y) return 0;
	if(dep[x] < dep[y]) swap(x, y);
	int res = 0;
	for(int i = 19; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]){
			x = fa[x][i];
			res += (1 << i);
		}
	}
	if(x == y) return x;
	for(int i = 19; i >= 0; i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
			res += 2 * (1 << i);
		}
	}
	return res + 2;
}

int ans = INT_MAX;
int check(){
	int idd;
	for(int i = 1; i <= n; i++){
		if(vis[i]){
			idd = min(idd, i);
			if(vis[fa[i][0]]){
				uf[find(i)] = find(fa[i][0]);
			}
		}
	}
	
	int cnt = 0;
	int cur = 0;
	for(int i = 1; i <= n; i++){
		if(find(i) == i) cnt++;
		cur = max(cur, lca(i, idd));
	}
	if(cnt > 2) return inf;	
	return cur;
}

void choose(int pos ,int cnt){
	if(cnt > k){
		ans = min(ans, check());
		return ;
	}
	for(int i = pos + 1; i <= n; i++){
		vis[i] = 1;
		dfs(i, cnt + 1);
		vis[i] = 0;
	}
	return ;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	if(c >= 0 && c <= 2){
		while(t--){
			cin >> n >> k;
//			cout << n << k << endl;
			for(int i = 1; i < n; i++){
				int u, v;
				cin >> u >>v ;
				edge[u].push_back(v);
				edge[v].push_back(u);
				uf[i] = i;
			}
			uf[n] = n;
//			cout << "yes" << endl;
			dfs(1, 0);
//			cout << "yes" << endl;
			prep();
//			cout << "yes" << endl;
			choose(1, 1);
			
			cout << ans << endl;
		}
	}
	return 0;
}
