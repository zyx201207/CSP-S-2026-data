#include <bits/stdc++.h>
using namespace std;

int c, t, n, k;

const int N = 1e6 + 5;
vector<int> G[N];
bool uouo[N];
int ans = INT_MAX;

int dep[N], hson[N], f[N], siz[N];
int top[N];
inline void qw1(int u, int fa){
	f[u] = fa;
	dep[u] = dep[fa] + 1;
	hson[u] = -1;
	siz[u] = 1;
	for(auto v : G[u]){
		if(v == fa)   continue;
		qw1(v, u);
		siz[u] += siz[v];
		if(hson[u] == -1 || siz[hson[u]] < siz[v])   hson[u] = v;
	}
}
inline void qw2(int u, int tp){
	top[u] = tp;
	if(hson[u] != -1)   qw2(hson[u], tp);
	for(auto v : G[u]){
		if(v == f[u] || v == hson[u])   continue;
		qw2(v, v);
	}	
}
inline int lca(int x, int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]])    swap(x, y);
		x = f[top[x]];
	}
	return dep[x] > dep[y] ? y : x;
}

inline int ckck(int u, int fa){
	int spl = 0;
	for(auto v : G[u]){
		if(v == fa)   continue;
		spl += ckck(v, u);
		if(uouo[v] && !uouo[u])   spl ++;
	}
	return spl;
}
inline void Dfs(int now, int cnt){
	if(now == n + 1){
		if(cnt != k)   return ;
//		if(n == 9)
//		{
//		for(int i = 1;i <= n;i ++)   cout << uouo[i] << endl;
//		cout << endl;
//		cout << "    " << ckck(0, 0) << "     " << endl;}
		if(ckck(0, 0) > 2)   return ;
		int spj = INT_MIN;
		for(int i = 1;i <= n;i ++){
			int res = INT_MAX;
			for(int j = 1;j <= n;j ++){
				if(!uouo[j])   continue;
				res = min(res, dep[i] + dep[j] - 2 * dep[lca(i, j)]);
			}  
			spj = max(spj, res);
		}
		ans = min(ans, spj); 
		return ;
	}
	uouo[now] = 1;
	Dfs(now + 1, cnt + 1);
	uouo[now] = 0;
	Dfs(now + 1, cnt);
}

inline void init(){
	for(int i = 0;i <= n;i ++)  G[i].clear();
	G[0].push_back(1);
	memset(uouo, 0, sizeof(uouo)) ;
	ans = INT_MAX;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	
	cin.tie(0) -> sync_with_stdio(false);
	
	cin >> c >> t;
	while(t --){
		init();
		cin >> n >> k;
		for(int i = 1;i < n;i ++){
			int u, v;
			cin >> u >> v;
			G[u].push_back(v), G[v].push_back(u);
		}
		qw1(1, 0), qw2(1, 1);
		Dfs(1, 0);
		cout << ans << "\n";
	}
	
}

/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8

6 5
1 2
2 5
4 5
5 3
3 6

9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
