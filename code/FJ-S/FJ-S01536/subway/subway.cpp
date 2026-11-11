#include <bits/stdc++.h>
using namespace std;

typedef long long intL;
const int maxn = 5e2 + 6;
const int maxm = 5e5 + 6;

struct node{
	intL to, s;
};

intL c, n, m, d, q, ans;
int x, y;
intL w[maxm];
vector<node> g[maxm + maxn];
bool vis[maxm + maxn];
map<pair<int, int>, intL> mint;

void bfs();

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++)
		scanf("%lld", &w[i]);
	for(int i = 1, k;i <= n;i++){
		scanf("%d", &k);
		for(int j = 1, a, t;j <= k;j++){
			scanf("%d%d", &a, &t);
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	for(int i = 1;i <= q;i++){
		scanf("%d%d", &x, &y);
		memset(vis, false, sizeof vis);
		if(mint[{x, y}] == 0){
			ans = 2e18;
			bfs();
			printf("%lld\n", ans);
			mint[{x, y}] = mint[{y, x}] = ans;
		}
		else
			printf("%lld\n", mint[{x, y}]);
	}
	return 0;
}

void bfs(){
	queue<node> q;
	q.push({y, w[x] + w[y]});
	vis[y] = true;
	while(!q.empty()){
		intL u = q.front().to, ns = q.front().s;
		q.pop();
		if(ns > ans)continue;
		if(u == x){
			ans = ns;
			continue;
		}
		for(int i = 0;i < g[u].size();i++){
			intL v = g[u][i].to, s = g[u][i].s;
			if(!vis[v] || v == x){
				q.push({v, ns + s});
				if(v <= m)
					vis[v] = true;
			}
		}
	}
	return;
}
