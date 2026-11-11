#include<bits/stdc++.h>
using namespace std;

int c, t, n, k;
int a[1000010];
vector<int> edge[1000010];

bool dfs(int dp, int pre) {
	if (dp == k + 1) {
		for (int i = 1; i <= n; i++) {
			
		}
	for (int i = pre + 1; i <= n; i++)
		a[dp] = i, dfs(dp + 1, i);
}

int main() {
	scanf("%d%d", &c, &t);
	while (t--) {
		for (int i = 1; i <= n; i++)
			edge[i].clear();
		scanf("%d%d", &n, &k);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			edge[u].push_back(v), edge[v].push_back(u);
		}
		dfs(1, 0);
	}
	return 0;
}
//ËãÁË 
