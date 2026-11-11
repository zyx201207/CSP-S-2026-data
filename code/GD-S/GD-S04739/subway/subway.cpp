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
int const N = 5e5 + 5, M = 5e2 + 5;
ll const inf = 0x3f3f3f3f3f3f3f;
int n, m, d, q, a[N];
ll f[M][M];
vector<pair> g[N];
void mn(ll &x, ll y) {x = min(x, y);}
void build() {
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= m; i++) {
//		cout << "sz: " << i << ' ' << g[i].size() << '\n';
		for(int j = 0; j < g[i].size(); j++) {
			auto x = g[i][j];
			for(int k = j + 1; k < g[i].size(); k++) {
				auto y = g[i][k];
//				cout << i << ' ' << x.fi << ' ' << y.fi << ' ' << x.se << ' ' << y.se << '\n';	
//				cout << "upd: " <<
				if(f[x.fi][y.fi] > 1ll * x.se + y.se) {
					f[x.fi][y.fi] = f[y.fi][x.fi] = 1ll * x.se + y.se;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) mn(f[i][j], f[i][k] + f[k][j]);
		}
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) cout << f[i][j] << ' ';
//		cout << '\n';
//	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c; cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int x, y; cin >> x >> y;
			g[x].pb({i, y});
		}
	}
	build();
	for(int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		ll w = inf;
		for(auto j : g[x]) {
			for(auto k : g[y]) {
				mn(w, f[j.fi][k.fi] + j.se + k.se);
			}
		}
		cout << w + a[x] + a[y] << '\n';
	}
	Crystal_poem code;
}
/*
难点在于读懂题目
首先就是那个线路应该就是连一个虚拟节点然后边权为 0 的边吧
然后就是，首先那个神秘的地铁口那个是不是不用管
我觉得并不需要给虚拟节点连边权为 0 的边吧
实际上你是步行的距离，那么我直接从虚拟节点连那个站台到大厅的边不就行了吗
然后我看一下复杂度要怎么优化
哦哦好的终于读懂题目了
硬跑dijk肯定是不行的，dijk是每个节点只出队一次，所以应该是mlogn级别的，或者mlogm
然后这个 d 大有玄机哦
也就是一个节点出发最多连 d 条边
然后
？
为什么不能floyd
hyw
不是不是 m是节点数
什么
虚拟节点只会有500个
那我先从虚拟节点开始
大概可以这样做吧
不过你mlogm已经很卡卡了，再乘一个500不可能过啊
那我肯定是要处理出一个虚拟节点到所有实际节点的最短路
那么能不能这样剪枝，就是记录一下处理了哪些虚拟节点到所有的最短路，然后如果遍历到虚拟节点
但是你发现虚拟节点的个数也很少啊，能不能在这上面搞点事情 
我去然后我直接倒闭了
额你发现我对于虚拟点跑floyd也许是可以的
我觉得你如果要用上20的话，那就是，其实相当于在交汇点之间两两连边是吗
现在基本思路就是，首先我肯定不能预处理两个真实节点的最短路，那么对于1e5组询问
我应该是枚举交汇点，只要处理出每个交汇点到实际节点的最短路就行了
问题就在这里
我能不能枚举1去哪里，2从哪里进入
好像可以 
数组千万要看好啊！！！ 
*/
