#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e5 + 10, M = 505;

int c, n, m, d, q;
int w[N], k[M];
vector<int> a[M], t[M]; 
vector<pair<int, int> > p[N];
int u, v;
ll ans;
bool vis[N];

int PM(int u, int h){
	for(auto e: p[u]){
		if(e.first == h)	return e.second;
	}
}

void dfs(int u, ll sum, int h){
	if(sum > ans)	return ;
	if(u == v){
		ans = min(ans, sum + (ll)t[h][PM(u, h) - 1] + w[u]);
		return ;
	}
	for(auto e: p[u]){
		int bh = e.first, pm = e.second;
		int val = 0;
		if(bh != h)	val = t[h][PM(u, h) - 1];
		if(pm + 1 <= k[bh] && !vis[a[bh][pm]]){
			int v = a[bh][pm];
			vis[v] = true;
			if(bh != h)	val += t[bh][pm - 1];
			dfs(v, sum + (ll)val, bh);
			vis[v] = 0;
		}
		if(pm - 1 > 0 && !vis[a[bh][pm - 2]]){
			int v = a[bh][pm - 2];
			vis[v] = true;
			if(bh != h)	val += t[bh][pm - 1];
			dfs(v, sum + (ll)val, bh);
			vis[v] = 0; 
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", &k[i]);
		for(int j = 1;j <= k[i];j++){
			int x, y;
			scanf("%d%d", &x, &y);
			a[i].push_back(x);
			t[i].push_back(y);
			p[x].push_back({i, j});
		}
	}
	for(int i = 1;i <= q;i++){
		scanf("%d%d", &u, &v);
//		for(int i = 1;i <= n;i++)	vis[i] = 0;
		ans = 1e18;
		vis[u] = true;
		for(auto e: p[u]){
			dfs(u, (ll)w[u], e.first);
		}
		vis[u] = 0;
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
