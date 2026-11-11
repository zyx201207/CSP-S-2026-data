#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int c, n, m, d, q, ans = 0;
int w[N];
struct node{
	int a, t;
};
struct nod{
	int many;
	vector<int> id;
}vis[N];
vector<node> g[N];
void dfs(int depth, int end, int cur, int start) {	

	if(cur >= ans) return;
	if(depth == end) {
		ans = min(ans, cur + w[start] + w[end]);
		return;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j < g[i].size();j++) {
			node p = g[i][j];
			dfs(p.a, end, cur + p.t, start);
		}
	}
	return;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++) {
		int k;cin >> k;
		for(int j = 1;j <= k;j++) {
			int a, t;cin >> a >> t;
			g[i].push_back({ a,t });
			vis[a].many++;
		}
	}
	if(n == 2) {
		while(q--) {
			ans = INT_MAX;
			int start, end;cin >> start >> end;
			
		}
	}
	/*
	while(q--) {
		ans = INT_MAX;
		int start, end;cin >> start >> end;
		dfs(start, end, 0, start);
		cout << ans << '\n';
	}
	*/
	return 0;
}
