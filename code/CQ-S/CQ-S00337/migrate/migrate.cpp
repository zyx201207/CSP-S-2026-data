#include <bits/stdc++.h>
#define qwq std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long

inline int read(){
	int x = 0, f = 1; char h = getchar();
	while(!isdigit(h)){ if(h == '-') f = -f; h = getchar(); }
	while(isdigit(h)){ x = x * 10 + (h ^ 48); h = getchar(); }
	return x * f;
}

const int N = 2e6 + 10, inf = 0x3f3f3f3f3f3f3f3f;
int n, d, ans, a[N], r[N];

namespace sub123{
	const int M = 2e3 + 10;
	std::vector <int> e[M];
	struct Node{ int val, tim; } f[M][M];

	inline void bfs(int s){
		for(int i = 1; i <= n; ++i) f[s][i] = {inf, 0};
		std::queue <int> q; q.push(s); f[s][s] = {0, 1};
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(auto &v : e[u]){
				if(f[s][v].val == f[s][u].val + 1) f[s][v].tim += f[s][u].tim;
				else if(f[s][v].val > f[s][u].val + 1) f[s][v] = {f[s][u].val + 1, f[s][u].tim}, q.push(v);
			}
		}
	}
	inline void solve(){
		for(int i = 1; i <= n; ++i) e[i].clear(); ans = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = i - 1; j && a[i] - a[j] <= d; --j) e[j].push_back(i);
		for(int i = 1; i <= n; ++i) bfs(i);
		for(int i = 1; i <= n; ++i)
			for(int j = i + 1; j <= n; ++j) ans += (f[i][j].tim == 2);
		printf("%lld\n", ans);
	}
}

namespace sub4{
	inline void solve(){
		int k = d / (a[2] - a[1]);
		if(k > 1) printf("%lld\n", std::max(0ll, n - (k * 2) + 1));
		else printf("0\n");
	}
}

bool isdxsl(){
	for(int i = 1; i + 2 <= n; ++i) if(a[i + 1] - a[i] != a[i + 2] - a[i + 1]) return 0;
	return 1;
}

int32_t main(){
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	int c = read(), T = read();
	while(T--){
		n = read(), d = read();
		for(int i = 1; i <= n; ++i) a[i] = read();
		if(n <= 1000) sub123::solve();
		else if(isdxsl()) sub4::solve();
	}
	return 0;
}
/*
发现存在的条件是。
尽力飞行以后到达最后一个岛，但是可以把中途有一个换成少飞行一下也能到。
神秘想法，直接往后dfs，只跑r[i],r[i]-1,r[i]-2三个点。
然后就是玄学复杂度。不如直接暴力建图，看那些点的最短路次数是2，O(n^2)。
17:12 40pts。上个厕所刷新一下。
思考等差数列的性质是什么。每一个位置可以固定向后连k条边。
然后发现只有差值为2k-1的点对才能对答案有贡献。
17:34 48 pts
*/
