#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 9, N = 1e7 + 9, inf = 2147483647;
int c, n, m, d, q, w[M], k[555], a[555][555], t[555][555];
int h[N], tot, dis[N];
int x, y;
bool vis[N];
struct E{
	int to, with, ne; 
}e[N];
void add(long long u, long long v, long long w){
	e[++tot].ne = h[u];
	e[tot].with = w;
	e[tot].to = v;
	h[u] = tot;
}
vector<int> zt1[M], zt2[M];
priority_queue<int> Q;
void dij(){
	for(int i = 1; i <= N; i++){
		vis[i] = false;
		dis[i] = inf;
	}
	dis[x] = 0;
	Q.push(x);
	while(!Q.empty()){
		int pos = Q.top();
		Q.pop();
		if(vis[pos]){
			continue;
		}
		vis[pos] = true;
		for(int i = h[pos]; i; i = e[i].ne){
			int yy = e[i].to;
			if(vis[yy]){
				continue;
			}
			if(dis[pos] > dis[yy] + e[i].with){
				dis[pos] = dis[yy] + e[i].with;
			}
			Q.push(yy);
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%d%d", &a[i][j], &t[i][j]);
			zt1[a[i][j]].push_back(i);
			zt1[a[i][j]].push_back(j);
			if(j > 1){
				add(a[i][j - 1], a[i][j], 0);
				add(a[i][j], a[i][j - 1], 0);
			}
		}
	}
	for(int i = 1; i <= q; i++){
		scanf("%d%d", &x, &y);
//		dij();
		printf("%d\n", w[x] + w[y]);
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j < zt1[i].size(); j++){
//			int x = zt1[i][0], y = zt2[i][0];
//			add(a[x][y], a[zt1[i][j]][zt2[i][j]], t[x][y] + t[zt1[i][j]][zt2[i][j]]);
//		}
//	}
	
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3 
//1 2
