#include<bits/stdc++.h>
#define Crystal_poem return
#define code 0
#define ll long long
#define pair pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define pb push_back
using namespace std;
int const N = 1e6 + 5;
int t, n, k, dfn[N], c[N], rt, d[N], dep[N]; 
int ecnt, to[N << 1], nxt[N << 1], head[N];
bool col[N];
void addedge(int x, int y) {ecnt ++, to[ecnt] = y, nxt[ecnt] = head[x], head[x] = ecnt;}
struct Tree{
	int cnt, f[N], a[N];
	vector<int> st[20];
	void mem() {
		for(int i = 0; i < 20; i++) st[i].clear();
		cnt = 0;
	}
	void dfs(int x, int fa) {
		f[x] = fa;
		for(int i = head[x]; i; i = nxt[i]) {
			int y = to[i];
			if(y == fa) continue ;
			dep[y] = dep[x] + 1;
			dfs(y, x);
		}
	} 
	void dfs1(int x, int fa) {
		a[x] = st[0].size();
		st[0].pb(x);
		dfn[x] = ++cnt;
		c[cnt] = x;
		dep[x] = dep[fa] + 1;
		d[x] = 0;
		for(int i = head[x]; i; i = nxt[i]) {
			int y = to[i];
			if(y == fa) continue ;
			dfs1(y, x); st[0].pb(x);
			d[x] = max(d[x], d[y]);
		}
		d[x] ++;
	}
	void build() {
		int l = st[0].size(), p = (int)log2(l);
		for(int i = 1; i <= p; i++) {
			for(int j = 0; j + (1 << i) - 1 < l; j++) {
				if(dep[st[i - 1][j]] < dep[st[i - 1][j + (1 << i - 1)]]) {
					st[i].pb(st[i - 1][j]);
				}
				else st[i].pb(st[i - 1][j + (1 << i - 1)]);
			}
		}
	}
	int find_rt() {
		dfs(1, 0); int s = 0, k = 0;
		for(int i = 1; i <= n; i++) if(dep[i] > dep[s]) s = i;
		dfs(s, 0); 
		for(int i = 1; i <= n; i++) if(dep[i] > dep[k]) k = i; 
		int l = dep[k] / 2;
		while(l --) k = f[k];
		dfs1(k, 0); build();
		return k;
	}
	int lca(int x, int y) {
		x = a[x], y = a[y];
		if(x > y) swap(x, y);
		int p = (int)log2(y - x + 1);
		if(dep[st[p][x]] < dep[st[p][y - (1 << p) + 1]]) return st[p][x];
		return st[p][y - (1 << p) + 1];
	}
	int dis(int x, int y) {return dep[x] + dep[y] - dep[lca(x, y)] * 2;}
}A;
bool chk(int mid) {
	vector<int> v; int res = 0;
	for(int i = 1; i <= n; i++) if(d[i] == mid) v.pb(dfn[i]);
	if(!v.size()) return 1;
	memset(col, 0, sizeof(col));
	while(v.size() > 2) {
		sort(v.begin(), v.end());
		int mn = n + 1; pair h = {0, 0};
		for(int i = 1; i < v.size() - 1; i++) {
			int x = c[v[i - 1]], y = c[v[i]], z = c[v[i + 1]];
			int dis = A.dis(x, y) + 1 - col[x] - col[y];
			if(dis < mn) mn = dis, h = {x, y};
			dis = A.dis(y, z) + 1 - col[y] - col[z];
			if(dis < mn) mn = dis, h = {y, z}; 
		}
		if(res + mn > k) return 0;
		res += mn;
		vector<int> t;
		for(int i : v) {
			if(c[i] == h.fi || c[i] == h.se) continue ;
			t.pb(i);
		}
		v = t; int p = A.lca(h.fi, h.se);
		col[h.fi] = col[h.se] = col[p] = 1;
		v.pb(dfn[p]);
	}
	int mx = -1;
	for(int i = head[rt]; i; i = nxt[i]) {
		int y = to[i];
		if(d[y] < mid) mx = max(mx, d[y]);
	}
	if(mx == -1) return 1;
	mx ++;
	for(int i = 1; i <= n; i++) {
		if(col[i] && A.dis(i, rt) - (k - res) + mx <= mid) return 1;
	}
	return 0;
}
void mem() {
	memset(head, 0, sizeof(head));
	ecnt = 0; A.mem();
}
void solve() {
	mem();
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		addedge(x, y); addedge(y, x);
	}
	if(k >= n) return cout << 0 << '\n', void();
	int rt = A.find_rt();
	int l = 1, r = n, res = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(chk(mid)) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << res << '\n';
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c; cin >> c >> t;
	while(t--) solve();
	Crystal_poem code;
}
/*
首先无脑二分
然后你发现，对于一个深度限制，如果说我的子树内的最大深度刚好达到了k，那么在我这里放一定是不劣的对吧
首先二分毋庸置疑
然后，为了保险起见可以先把根设为中心？
然后求出所有子树内深度最大值刚好为 k 的，这些点必选
接着合并不就行了
就是你发现一开始是是这么多个联通块呀，然后用了几个啊，然后合并到lca嘛
就是每一次合并一定少一个连通块，那我只需要贪心去选合并所需要权值最小的即可
考虑怎么维护这个
这个只能1log，如果二分了的话只能n去chk
感觉可以bfs啊
欸或者，每个点记有几个子树深度大于？
然后你发现一个事情，就是如果你有超过 3 个子树深度大于你就是必选的
不过你发现其实是有点像最小生成树的
MST是n-1条边，这里是n-2条边
欸我先扫一遍，计算那个有几个子树深度大于等于，然后标记
然后跑bfs
然后你比如说跑到了一个点，发现它的子树大于1，那么它必然是某个点的lca，打标记然后统计贡献即可
然后如果你发现我跑到了一个已经被打了标记处理好的点直接扔掉不入队就行
不是我说，每个点离它最近的必然是dfs序上最近的啊，能不能这样处理
能不能加速
这样是n^2log的吧
没时间了随便写个暴力吧
可以用set
但是合并到只剩两个的时候还要特判一下那些在根周围小于dep的
这个好办 
我说我发现我不会找中心
额
我说中心就是直径的中点吧 

树形dp，设f_{i, 0/1, 0/1/2} 表示 i 子树内，i选不选，选了几个连通块的最少步数 
*/
