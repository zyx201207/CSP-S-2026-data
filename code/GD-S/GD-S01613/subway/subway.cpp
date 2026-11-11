#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int c , n , m , s , q;
int w[N] , t[N][N];
long long ans , minn;
vector<int> g[N];
long long dfs(int u , int v , int fa) {
	if(u == v) {
		minn = min(minn , ans);
		return minn;
	}
	for(int e : g[u]) {
		if(e != fa) {
			ans += t[e][u];
			dfs(e , v , u);
		}
	}
}
int main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> s >> q;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++) {
		int k , u = 0;
		cin >> k;
		for(int j = 1;j <= k;j++) {
			int x , y;
			cin >> x >> y;
			if(u == 0) continue;
			t[i][x] = y;
			g[x].push_back(u);
			g[u].push_back(x);
			u = x;
		}
	}
	long long cnt = 0;
	for(int i = 1;i <= q;i++) {
		int r , l;
		cin >> l >> r;
		cnt += w[l] + w[r];
		cnt += dfs(l , r , 0);
		cout << cnt << '\n';
		cnt = 0;
	}
	return 0;
}
