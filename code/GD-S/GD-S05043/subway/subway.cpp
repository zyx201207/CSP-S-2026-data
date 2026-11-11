#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N1 = 500000, N2 = 510, N3 = 1280;
ll c, n, m, d, q;
ll w[N1], k;
ll mn[N3][N3];//起点到某个点的最短距离
bool vis[100000];
struct Node{ll v, w;};
vector<Node> e[100000];
void add_edge(ll x, ll y, ll w){
	e[x].push_back({y, w});
	e[y].push_back({x, w});
}
void dfs(ll u, ll x){
	vis[u] = true;
	ll siz = e[u].size();
	for(ll i = 0;i < siz;++i){
		ll v = e[u][i].v, w = e[u][i].w;
		mn[x][u] = mn[u][x] = min(mn[x][v] + w, mn[x][u]);
	}
	for(ll i = 0;i < siz;++i)
		if(!vis[e[u][i].v])
			dfs(e[u][i].v, x);
}
//x——m+i(i为第i号线，最大为n)：虚拟节点，表示一整条线，建的边长为0
//x——x+m+n：表示该站在这一条线上的站台x到站厅的时间，换乘的时间只用计算到站厅的两条边 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1;i <= m;++i)
		cin >> w[i];
	for(ll i = 1;i <= n;++i){
		cin >> k;
		ll x, y;
		while(k--){
			cin >> x >> y;
			add_edge(x, i + m + 1, 0);
			add_edge(x, x + m + n + 5, y);
		}
	}
	while(q--){
		ll x, y;
		cin >> x >> y;
		if(x == y){
			cout << 0 << "\n";
			continue;
		}
		ll tot = w[x] + w[y];
		for(int i = 1;i <= m+m+n;++i)
			for(int j = 1;j <= m+m+n;++j)
				mn[i][j] = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1;i <= m+m+n;++i){
			for(int j = 0;j < e[i].size();++j){
				mn[i][j] = mn[j][i] = e[i][j].w;
			}
		}
		for(int j = 1;j <= n;++j){
			for(int i = 1;i <= m * 2 + n;++i)vis[i] = 0;
			mn[j][j] = 0;
			vis[x] = true;
			dfs(j, j);
		}
		cout << mn[x][y] + tot << "\n";
	}
	return 0;
}

/*输在不会无向有环图的最短路了啊*/
