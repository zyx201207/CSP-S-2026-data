#include<bits/stdc++.h>
namespace kimi{
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;
const int maxn = 2e6 + 10;
int n, m, d, q;
int W[maxn];
int dis[maxn], vis[maxn], idx;
vector<pii> G[maxn];
//idx=n+2*m
//O(idx log 2 * m)
int dij(int s, int t){
	for(int i = 0; i <= idx; i++) dis[i] = 0x3f3f3f3f, vis[i] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({0, s}), dis[s] = 0;
	while(!Q.empty()){
		auto u = Q.top().se;
		Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto a : G[u]) if(dis[u] + a.se < dis[a.fi]) dis[a.fi] = dis[u] + a.se, Q.push({dis[a.fi], a.fi});
	}
	return dis[t];
}
void add(int u, int v, int w){G[u].pb(v, w), G[v].pb(u, w);}
void T1(){while(q--) cout << 0 << endl;exit(0);}
void mian(){
	cin >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> W[i];
	if(n == 1) T1();
	idx = m + n;
	for(int i = 1, K; i <= n; i++){
		cin >> K;
		for(int j = 1, a, t; j <= K; j++){
			cin >> a >> t;
			add(a, ++idx, 0);
			add(m + i, idx, t);
		}
	}
	//O(q * (m log m))
	for(int i = 1, x, y; i <= q; i++){
		cin >> x >> y;
		cout << dij(x, y) + W[x] + W[y] << endl; 
	}
}
}using namespace kimi;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0); 
	int c, Test = 1;
	cin >> c;
	while(Test--) mian();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
