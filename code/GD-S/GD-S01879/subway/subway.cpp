#include<bits/stdc++.h>
#define int long long
using namespace std;
int d[1500007];
int c, n, m, di, q;
struct node{
	int to, v;
};
vector<node> g[1500007];//iµØÌú¿Úi+nÕ¾Ìüi+n+?Õ¾Ì¨
void dij(int s){
	fill(d, d + m + m + n + 1, LONG_LONG_MAX);
	priority_queue<pair<int, int>> q;
	q.push({0, s});
	d[s] = 0;
	while(!q.empty()){
		int w = q.top().second;
		q.pop();
		for(auto u : g[w]){
			if(d[u.to] > d[w] + u.v){
				d[u.to] = d[w] + u.v;
				q.push({d[u.to], u.to});
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> di >> q;
	for(int i = 1; i <= m; i++){
		int ww;
		scanf("%lld", &ww);
		g[i].push_back({i + m, ww});
		g[i + m].push_back({i, ww});
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t;
			scanf("%lld%lld", &a, &t);
			g[a + m].push_back({m + m + i, t});
			g[m + m + i].push_back({a + m, t});
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		dij(l);
		cout << d[r] << '\n';
	}
	return 0;
}
