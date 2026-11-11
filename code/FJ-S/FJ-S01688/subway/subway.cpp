#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e6 + 5; 
struct node{
	int n, p;
	inline bool operator < (const node _) const{
		if(n == _.n) return p < _.p;
		return n < _.n;
	}
};
vector<node>e[N];
int c, n, m, d, q, t[505][20005], a[505][20005], w[N], k[N], u, v, res = 1e18, b[N];
map< node , int > mp;
void dfs(int id, int cnt, int now){
	if(id == v){
		res = min(res, cnt);
		return; 
	}
	for(auto g : e[id]){
		if(k[g.n] == g.p) continue;
		int gogogo = t[now][mp[(node){now, id}]];
		if(id != u && now != g.n)
			gogogo += t[g.n][mp[(node){g.n, id}]]; 
		dfs(a[g.n][g.p + 1], gogogo, g.n);
	} 
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m ; i ++)
		cin >> w[i];
	for(int i = 1; i <= n ; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			cin >> a[i][j] >> t[i][j];
			e[a[i][j]].push_back((node){i, j});
			mp[(node){i, a[i][j]}] = t[i][j];
		}
		b[i] = 0;	
	} 
	while(q --){
		res = 1e18;
		cin >> u >> v;
		int ans = w[u] + w[v];
		b[u] = 1;
		dfs(u, 0, -1);
		b[u] = 0;
		cout << ans + res << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
