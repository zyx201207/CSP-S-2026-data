#include <bits/stdc++.h>
#define N 2000005
using namespace std;

int c, T, n, k, vis[N], fa[N], dep[N], ans, ttt = N;

vector <int> edge[N];

void ddfs(int x) {
	dep[x] = dep[fa[x]] + 1;
	if(vis[x]) ans = min(ans, dep[x]);
	for(int y : edge[x]) {
		if(y == fa[x]) continue;
		fa[y] = x;
		ddfs(y);
	}
}

void dffs(int x) {
	for(int y : edge[x]) {
		if(!vis[y]) continue;
		if(y == fa[x]) continue;
		fa[y] = x;
		dffs(y);
	}
}

void dfs(int step, int now) {
	if(step == k + 1) {
//		for(int i = 1; i <= n; i++) cout << vis[i] << " ";
//		cout << "\n";
		for(int i = 1; i <= n; i++) fa[i] = dep[i] = 0;
		int cnt = 0;
		for(int i = 1; i <= n; i++) if(vis[i] && !fa[i]) cnt++, dffs(i);
		if(cnt > 2) return;
		int tt = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			for(int j = 1; j <= n; j++) fa[j] = dep[j] = 0;
			ans = N;
			ddfs(i);
//			for(int j = 1; j <= n; j++) cout << dep[j] << " ";
//			cout << "\n";
			tt = max(tt, ans - 1);
		}
//		cout << tt << "\n";
		ttt = min(ttt, tt);
		return;
	}
	for(int i = now + 1; i <= n; i++) {
		vis[i] = 1;
		dfs(step + 1, i);
		vis[i] = 0;
	}
}

int main(){
//	system("fc hub.out hub2.ans");
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) edge[i].clear();
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(c <= 3) {
			ttt = N;
			dfs(1, 0);
			cout << ttt << "\n";
		} else {
			
		}
	}
	return 0;
}



