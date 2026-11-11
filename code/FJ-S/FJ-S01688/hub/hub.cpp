#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e6 + 5; 
int c, T, n, k, vis[N], cnt = 0, res, f[N];
vector<int> e[N];
void add(int u,int v){
	e[u].push_back(v);
}
int find(int x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void check(){
	for(int i = 1; i <= n ; i ++)
		f[i] = i;
	for(int i = 1; i <= n ; i ++){
		for(auto to : e[i]){
			if(vis[to] == vis[i] && find(to) != find(i))
				f[to] = f[i];
		}
	}
	for(int i = 1; i <= n ; i ++)
		cnt += (f[i] == i && vis[i] == 1);
}
int fd(int id, int fr, int sum){
	int t = sum + 1;
	for(auto p : e[id]){
		if(p == fr) continue;
		if(vis[p] == 1) {
			res = min(res , t);
			continue;
		} 
		else 
			fd(p, id, t);
	}
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T --){
		int ans = 1e9;
		cin >> n >> k;
		for(int i = 1; i <= n ; i ++)
			e[i].clear();
		for(int i = 1; i <= n - 1; i ++){
			int u, v;
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		int len = 1 << n;
		for(int i = 0; i < len ; i ++){
			int now = 0, ansp = 0;
			for(int j = 1; j <= n ; j ++){
				if(i & (1 << (j - 1)))
					vis[j] = 1;
				else
					vis[j] = 0;
				now += vis[j];
			}
			cnt = 0;
			check();
			if(now != k || cnt > 2) continue;
			for(int j = 1; j <= n ; j ++){
				if(vis[j]) continue;
				res = 1e9;
				fd(j, j, 0);
				ansp = max(ansp, res);
			}
			ans = min(ansp, ans);
		}
		cout << ans << '\n';
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
*/
