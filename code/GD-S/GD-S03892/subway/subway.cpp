#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 5e5 + 10;
int test, n, m, k, C, a[N], b[N];
int f[N][35], d[N];
vector<pair<int, int> > edges[N];
inline void dfs(int x, int fa, int w){
	f[x][0] = fa;
	d[x] = d[fa] + w;
	for(auto Y : edges[x]){
		auto y = Y.first, w = Y.second;
		if(y == fa) continue;
		dfs(y, x, w);
	} 
}
inline int LCA(int u, int v){
	if(d[u] < d[v]) swap(u, v);
	
	int c = d[u] - d[v];
	for(int i = 0; c; i++, c /= 2)
		if(c & 1) u = f[u][i];
	
	if(u == v) return u;
	
	for(int i = 30; i >= 0; i--){
		if(f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	}
	return f[u][0];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &C, &n, &m, &k, &test);
	for(int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		int l;
		scanf("%d", &l);
		for(int j = 1; j <= l; j++){
			int x, t;
			scanf("%d%d", &x, &t);
			if(x == i){
				b[x] = t;
			}else{
				edges[i].push_back(make_pair(x, t));
				edges[x].push_back(make_pair(i, t));
			}
		}
	}
	dfs(1, -1, 1);
	for(int j = 1; j <= 30; j++){
		for(int i = 1; i <= m; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	}
	while(test--){
		int l, r;
		scanf("%d%d", &l, &r);
		int p = LCA(l, r);
		printf("%d\n", p);
	}
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
