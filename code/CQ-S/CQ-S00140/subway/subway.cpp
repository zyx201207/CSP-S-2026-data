#include <bits/stdc++.h>
using namespace std;
#define ls (p<<1)
#define rs (p<<1|1)
const int N = 1e6 + 5;
struct edge {
	int x, w;
};
struct node {
	int a, b, c;
};
int c, n, m, D, q, fa[N], k, f[N][20], d[N];
long long dep[N], W[N];
vector <edge> v[N]; 
node a[N];
bool cmp (node x, node y) {
	return x.c < y.c;
}
int Find(int x) {
	if(x == fa[x]) return x;
	int res = Find(fa[x]);
	fa[x] = res;
	return res;
}
void dfs(int x, int fat) {
	f[x][0] = fat, d[x] = d[fat] + 1;
	for(int i = 0; i < v[x].size(); i++) {
		edge y = v[x][i];
		if(y.x != fat) {
			dep[y.x] = dep[x] + y.w;
			dfs(y.x, x);
		}
	}
}
int lca(int x, int y) {
	if(d[x] < d[y]) swap(x, y);
	for(int i = 19; i >= 0; i--) {
		if(f[x][i]) {
			if(d[f[x][i]] >= d[y]) {
				x = f[x][i];
			}
		}
	}
	for(int i = 19; i >= 0; i--) {
		if(f[x][i] && f[y][i]) {
			if(d[f[x][i]] != d[f[y][i]]) {
				x = f[x][i];
				y = f[y][i];
			}
		}
	}
	if(x == y) return x;
	else return f[x][0];
	return -114514;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> c >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) cin >> W[i];
	for(int i = 1; i <= n; i++) {
		int l;
		cin >> l;
		for(int j = 1; j <= l; j++) {
			int x, d;
			cin >> x >> d;
			k++;
			a[k] = {x, i + m, d};
		}
	}
	for(int i = 1; i <= n + m; i++) fa[i] = i;
	sort(a + 1, a + k + 1, cmp);
	for(int i = 1; i <= k; i++) {
		int fx = Find(a[i].a), fy = Find(a[i].b);
		if(fx != fy) {
			v[a[i].a].push_back({a[i].b, a[i].c});
			v[a[i].b].push_back({a[i].a, a[i].c});
			fa[fx] = fy;
//			cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c << '\n';
		}
	}
	dfs(1, 0);
	for(int i = 1; i <= 19; i++) {
		for(int j = 1; j <= n + m; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		int L = lca(x, y);	
//		cout << L << ' ' << f[L][0] << ' ' << dep[f[L][0]]<< '\n';
//		cout << dep[x] + dep[y] - 2 * dep[L] << '\n';
		cout << dep[x] + dep[y] - 2 * dep[L] + W[x] + W[y] << '\n';
	}
	return 0;
}
