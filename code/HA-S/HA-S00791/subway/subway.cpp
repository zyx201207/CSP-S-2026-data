#include<bits/stdc++.h>
#define LL long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define fi first
#define se second
using namespace std;

const int N = 500 + 10, M = 2e4 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int C, n, m, d, Q, num, a[N][M];
LL w[M], t[N][M];
struct Node {
	int line, pos, id;
};
vector<Node> nd[M];
vector<pair<int, LL> > edge[M];

LL dis[M];
bool vis[M];
priority_queue<pair<LL, int> > q;
void dijks(int s) {
	rep(i, 1, num) dis[i] = INF, vis[i] = 0;
	dis[s] = 0;
	q.push({0, s});
	while(q.size()) {
		int u = q.top().se; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(pair<int, LL> e : edge[u]) {
			int v = e.fi;
			if(dis[v] > dis[u] + e.se) {
				dis[v] = dis[u] + e.se;
				q.push({-dis[v], v});
			}
		}
	}
}

void solve() {
	cin >> C >> n >> m >> d >> Q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		int k; cin >> k;
		int u, v = 0, tf = num + 1;
		rep(j, 1, k) {
			cin >> a[i][j] >> t[i][j];
			u = a[i][j];
			nd[u].pb({i, j, ++num});
			if(j != 1) edge[num].pb({v, 0}), edge[v].pb({num, 0});
			v = num;
		}
		edge[tf].pb({v, 0}), edge[v].pb({tf, 0}); //连环 
	}
	rep(k, 1, m) {
		if((int)nd[k].size() == 1) continue;
		int li = (int)nd[k].size() - 1;
		rep(i, 0, li) {
			rep(j, i + 1, li) {
				Node nw1 = nd[k][i], nw2 = nd[k][j];
				LL val = t[nw1.line][nw1.pos] + t[nw2.line][nw2.pos];
				edge[nw1.id].pb({nw2.id, val}), edge[nw2.id].pb({nw1.id, val});
			} //建中转点之间的边 
		}
	}
	rep(i, 1, Q) {
		int x, y; cin >> x >> y;
		LL ans = INF;
		for(Node st : nd[x]) {
			LL val1 = w[x] + t[st.line][st.pos], val23 = INF;
			dijks(st.id);
			for(Node ed : nd[y]) {
				LL val3 = w[y] + t[ed.line][ed.pos];
				val23 = min(val23, dis[ed.id] + val3);
			}
			ans = min(ans, val1 + val23);
		}
		cout << ans << '\n';
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int TIME1 = clock();
	solve();
	int TIME2 = clock();
#ifdef LOCAL
	cerr << "\n----------------------RUN OVER\n";
	cerr << TIME2 - TIME1 << "ms passed\n";
#endif
	return 0;
}

/*
注意到n、d都很小，思考一下性质
值可能很大，记得开LL
先想如何建图
建图的话可以把一条路线经过的所有点依次相连，边权为0
对于中转点（同一个编号），可能出现在不同的路线上
把在不同路线上的同一个点映射成不同的编号，彼此相连，边权为其在两个路线上路径和
这样建图应该是在时间允许范围内的，刚好可以用上d<=20这个条件 
如何记贡献
只有出发点、结束点、中转点能造成贡献
其中若出发点是中转点，则贡献可变，否则贡献固定
那么贡献就分为三部分
在图上转移的贡献、初始贡献（地铁口到站厅+站厅到站台）、结束贡献（同上） 
对于多次询问怎么办？ 
*/
