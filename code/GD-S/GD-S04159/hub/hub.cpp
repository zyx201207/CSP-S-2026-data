//hub
#include <stdio.h>
#include <vector>
#include <queue>
int c, _, n, k, dis[114514], vis[114514], isOpera[114514];
std::vector<int> g[114514];
void dfs(int x, int fa) {
	vis[x] = 1;
	int i;
	for(i = 0; i < g[x].size(); i += 1) {
		if(g[x][i] != fa && vis[g[x][i]] == 0 && isOpera[g[x][i]] == 1) {
			dfs(g[x][i], x);
		}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d %d", &c, &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		int i;
		for(i = 1; i <= n; i += 1) g[i].clear();
		for(i = 1; i < n; i += 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int final = 0xFFFFFFF;
		for(i = 0; i < (1 << n); i += 1) {
			if(__builtin_popcount(i) == k) {
				int j;
				for(j = 1; j <= n; j += 1) dis[j] = 0xFFFFFFF, vis[j] = 0, isOpera[j] = 0;
				std::priority_queue<std::pair<int, std::pair<int, int> >, std::vector<std::pair<int, std::pair<int, int> > >, std::greater<std::pair<int, std::pair<int, int> > > > q;
				std::vector<int> lst;
				int cp = i;
				j = 1;
				while(cp > 0) {
					if((cp & 1) == 1) {
						q.push({0, {j, -1}});
						dis[j] = 0;
						isOpera[j] = 1;
						lst.push_back(j);
					}
					j += 1;
					cp >>= 1;
				}
				int cnt = 0;
				for(j = 0; j < lst.size(); j += 1) {
					if(vis[lst[j]] == 0) {
						dfs(lst[j], -1);
						cnt += 1;
						if(cnt > 2) break;
					}
				}
				if(cnt > 2) continue;
				while(q.empty() == 0) {
					int x = q.top().second.first, fa = q.top().second.second;
					int d = q.top().first;
					q.pop();
					if(d != dis[x]) continue;
					for(j = 0; j < g[x].size(); j += 1) {
						if(g[x][j] != fa && dis[g[x][j]] > dis[x] + 1) {
							dis[g[x][j]] = dis[x] + 1;
							q.push({dis[x] + 1, {g[x][j], x}});
						}
					}
				}
				int ans = 0;
				for(j = 1; j <= n; j += 1) {
					if(ans < dis[j]) {
						ans = dis[j];
					}
				}
				if(ans < final) {
					final = ans;
				}
			}
		}
		printf("%d\n", final);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
