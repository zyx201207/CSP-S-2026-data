#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n, k;
int fa[N];
int find(int u){ return fa[u] == u ? u : fa[u] = find(fa[u]); }
struct edge{ int u, v; } E[N];
vector<int> e[N]; 
void adde(int u, int v){ e[u].push_back(v); }
bool is[N]; 
int dis[N];
void bfs(int st){
	for(int i = 1; i <= n; i++) dis[i] = n + 1;
	queue<int> q; dis[st] = 0, q.push(st);
	while(q.size()){
		int u = q.front(); q.pop();
//		cout << u << '\n';
		for(auto &v: e[u])
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1, q.push(v); 
			}
	}
}
void sol(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 1, u, v; i < n; i++){
		cin >> u >> v, E[i] = {u, v};
		adde(u, v), adde(v, u);
	}
	int ans = n;
//	cout << __builtin_popcount(9) << '\n';
	for(int S = 0; S < (1 << n); S++){
		if(__builtin_popcount(S) != k) continue;
		for(int i = 1; i <= n; i++) is[i] = 0, fa[i] = i;
		for(int i = 1; i <= n; i++)
			if(S >> (i - 1) & 1) is[i] = 1;
		for(int i = 1; i < n; i++)
			if(is[E[i].u] && is[E[i].v]) fa[find(E[i].v)] = find(E[i].u);
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(is[i]) cnt += find(i) == i; 
		}
		if(cnt > 2) continue;
//		cout << S << '\n';
		int mx = 0;
		for(int i = 1; i <= n; i++){
			bfs(i);
			int mn = n + 1;
			for(int j = 1; j <= n; j++)
				if(is[j]) mn = min(mn, dis[j]);
			mx = max(mx, mn);
		}
		ans = min(mx, ans);
//		break;
	}
	cout << ans << '\n';
} 
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, T; cin >> c >> T;
	while(T--) sol();
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9



看看T4.
一个树.
选择k个点,要求这些点在树中形成不超过2个连通块,则其称为一个方案
对于一个方案,其权值为:max f(i) in S, f(i)为i到S其他点的最小dis. 
求出所有合法方案的最小权值.
最小化 最大的dis
什么鬼东西.
暴力复杂度:2^n n^2
15pts
how A?

*/
