//subway
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
int c, n, m, d, q, w[514514], allocatedVNode = 0;
long long dis[614514], anss[114514];
std::unordered_map<int, char> *vis;
//The IDs of Virtual Nodes start from m + 6
std::vector<std::pair<int, int> > g[614514];
std::vector<std::pair<int, int> > qDest[514514];
int qs[514514];
long long Max(long long a, long long b) {return (a > b) ? a : b;}
int allocateVNode() {return (++allocatedVNode) + m + 5;}
void createTwoDirRoad(int x, int y, int w) {g[x].push_back({y, w});g[y].push_back({x, w});}
bool cmp(int &x, int &y) {return qDest[x].size() > qDest[y].size();}
void dfs(int x, int fa) {
	(*vis)[x] = 1;
	int i;
	for(i = 0; i < g[x].size(); i += 1) {
		if(g[x][i].first != fa && (dis[g[x][i].first] > dis[x] + g[x][i].second || (*vis)[g[x][i].first] == 0)) {
			dis[g[x][i].first] = dis[x] + g[x][i].second;
			dfs(g[x][i].first, x);
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	int i, j;
	for(i = 1; i <= m; i += 1) {
		scanf("%d", &w[i]);
		qs[i] = i;
	}
	while(n--) {
		int k;
		scanf("%d", &k);
		int vnode = allocateVNode();//subway Station
		while(k--) {
			int a, t;
			scanf("%d %d", &a, &t);
			createTwoDirRoad(vnode, a, t);
		}
	}
	for(i = 1; i <= q; i += 1) {
		int x, y;
		scanf("%d %d", &x, &y);
		qDest[x].push_back({y, i});
		qDest[y].push_back({x, i});
	}
	std::sort(qs + 1, qs + m + 1, cmp);
	for(i = 1; i <= m; i += 1) {
		if(qDest[qs[i]].size() == 0) continue;
		int allDone = 1;
		for(j = 0; j < qDest[qs[i]].size(); j += 1) {
			if(anss[qDest[qs[i]][j].second] == 0) {
				allDone = 0;
			}
		}
		if(allDone == 1) continue;
		vis = new std::unordered_map<int, char>;
		dis[qs[i]] = 0;
		dfs(qs[i], -1);
		delete vis;
		for(j = 0; j < qDest[qs[i]].size(); j += 1) {
			anss[qDest[qs[i]][j].second] = dis[qDest[qs[i]][j].first] + w[qs[i]] + w[qDest[qs[i]][j].first];
		}
	}
	for(i = 1; i <= q; i += 1) {
		printf("%lld\n", anss[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
