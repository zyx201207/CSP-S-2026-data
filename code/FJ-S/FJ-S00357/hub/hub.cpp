#include <bits/stdc++.h>
#define pub push_back
#define pob pop_back
using namespace std;
const int N = 105, inf = 1e9;
int c, T, n, k, f[N], rt, d[N][N], ans; bool vis[N];
vector <int> ed[N]; vector <int> v;
int zfind(int x){ return f[x] == x?x:f[x] = zfind(f[x]); }
void he(int x, int y){
	int z1 = zfind(x), z2 = zfind(y);
	if(z1 != z2) f[z1] = z2;
}
bool pd(){
	for(int i = 1;i <= n;i++) f[i] = i;
	for(int i = 1;i <= n;i++){
		for(auto j : ed[i]){
			if(vis[i] && vis[j]) he(i, j);
		}
	} 
	int cnt = 0;
	for(int i = 1;i <= n;i++) if(vis[i] && f[i] == i) cnt++;
	return cnt <= 2;
}
void calc(){
	int zd = 0, zx;
	for(int i = 1;i <= n;i++)
		if(!vis[i]){
			zx = inf;
			for(auto j : v) zx = min(zx, d[i][j]);
			zd = max(zd, zx);
		}
	ans = min(ans, zd);
}
void dfs(int sl, int lst){
	if(lst == n && sl < k) return;
	if(sl == k){
		if(!pd()) return;
		calc();
		return;
	}
	for(int i = lst + 1;i <= n;i++)
		if(!vis[i]){
			vis[i] = 1, v.pub(i);
			dfs(sl + 1, i), vis[i] = 0;
			v.pob();
		}
}
void dfs2(int x, int fa, int dep){
	d[rt][x] = dep;
	for(auto i : ed[x]) if(i != fa) dfs2(i, x, dep + 1);
}
int main(){
//	freopen("hub2.in", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			int u, v; cin >> u >> v;
			ed[u].pub(v), ed[v].pub(u);
		}
		for(int i = 1;i <= n;i++) rt = i, dfs2(i, 0, 0);
		ans = inf; dfs(0, 0); cout << ans << "\n";
		for(int i = 1;i <= n;i++) ed[i].clear();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
Ô¤¹À12·Ö 
*/
