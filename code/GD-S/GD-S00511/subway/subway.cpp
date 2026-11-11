#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, pri, w[1800], ans;
bool vis[1800]; 
vector<pair<int, int> > E[1800];
void dfs(int x, int y, int qwq) {
	qwq += w[x];
	if(x == y) {
		ans = min(ans, qwq);
		return;
	}
	for(pair<int, int> k : E[x]) {
		if(vis[k.first]) continue;
		vis[k.first] = 1;
		dfs(k.first, y, qwq + k.second);
		vis[k.first] = 0;
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >>c >>n >>m >>d >>q;
	for(int i = 1; i <= m; i++) {
		cin >>w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k; cin >>k;
		for(int j = 1; j <= k; j++) {
			int qwq, wac; cin >>qwq >>wac;
			pri++;
			E[qwq].push_back({m + pri, wac});
			E[m+pri].push_back({qwq, wac});
		}
	}
	while(q--) {
		ans = 0x3f3f3f3f;
		for(int i = 1; i <= 1600; i++) vis[i] = 0;
		int x, y; cin >>x >>y;
		dfs(x, y, 0);
		cout <<ans <<endl;
	}
}
