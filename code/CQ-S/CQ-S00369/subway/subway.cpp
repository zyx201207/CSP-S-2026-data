#include<bits/stdc++.h>
using namespace std;
const int N = 505;
struct node{
	int to, t;
};
int c, n, m, d, q;
int w[N];
bool vis[N];
vector<node> g[N];
void dfs(int s, int e){
	int ans = w[s];
	vis[s] = 1;
	for(auto i : g[e]){
		int x = i.to, y = i.t;
		if(vis[x]) continue;
		vis[x] = 1;
		ans += y;
	}
	cout << ans + w[e] << endl;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++ ){
		cin >> w[i];
	}
	for(int i = 1, k; i <= n; i ++ ){
		cin >> k;
		for(int j = 1, a, b; j <= k; j ++ ){
			cin >> a >> b;
			g[a].push_back({j, b});
			g[j].push_back({a, b});
		}
	}
	for(int i = 1, x, y; i <= q; i ++ ){
		cin >> x >> y;
		dfs(x, y);
		for(int j = 1; j <= m; j ++ ) vis[j] = 0;
	}
	return 0;
} 

