#include <bits/stdc++.h>
//#define int long long
//#define double long double
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
int C, T;
int n, k;
vector<int> e[1000010];
int f[1000010];
int cnt;
inline int q(int x) {
	if(f[x] != x) f[x] = q(f[x]);
	return f[x];
}
inline void h(int x, int y) {
	x = q(x);
	y = q(y);
	if(x == y) return ;
	--cnt;
	f[y] = x;
}
struct node {
	int x, y;
};
int ans;
bool sel[1000010];
int lst[1000010];
void dfs(int dep, int scnt) {
	if(dep > n) {
		if(scnt != k) return ;
		int res = 0;
		cnt = k;
		for(int i = 1; i <= n; i++) f[i] = i;
		for(int i = 1; i <= n; i++) {
			for(auto x : e[i]) {
				if(sel[x] && sel[i]) h(x, i);
			}
		}
		if(cnt > 2) return ;
		queue<node> qu;
		for(int i = 1; i <= n; i++) {
			if(sel[i]) qu.push(node {i, 0});
			lst[i] = -1;
		}
		while(!qu.empty()) {
			node tmp = qu.front();
			qu.pop();
			if(lst[tmp.x] != -1) continue;
			lst[tmp.x] = tmp.y;
			res = max(res, tmp.y);
			for(auto x : e[tmp.x]) {
				if(lst[x] != -1) continue;
				qu.push(node {x, tmp.y + 1});
			}
		}
//		for(int i = 1; i <= n; i++) {
//			cout << sel[i] << ' ';
//		}
//		cout << endl;
//		cout << res << ' ' << ans << ' ' << cnt << endl;
		ans = min(ans, res);
		return ;
	}
	if(k - scnt > n - dep + 1) return ;
	dfs(dep + 1, scnt);
	if(scnt < k) {
		sel[dep] = true;
		dfs(dep + 1, scnt + 1);
		sel[dep] = false;
	}
}
int x, y;
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) e[i].clear();
		ans = n;
		for(int i = 1; i < n; i++) {
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1, 0);
		cout << ans << endl;
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
