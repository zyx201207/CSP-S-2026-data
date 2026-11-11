//OIer真的有这么掉发吗，我把键盘掰开里面全是头发头皮屑
//600买SPBBZ的4小时的时长，还没网，游戏得自己写，太亏了 
//6:20天都黑了 
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn = 5e2 + 5;
const int maxm = 5e5 + 5;
int c, n, m, d, q;
vector<pair<int, int> >way[maxn];
vector<int>cnt[maxm];
int w[maxm];
int ans;
bool vis[maxm];
void dfs(int now, int ed, int t, int line) {
   	if (now == ed) {
   	   	ans = min(ans, t);
   	   	return;
   	}
   	for (int i = 0; i < way[line].size(); i++) {
   	   	if (vis[i]) {
   	   	   	continue;
   	   	}
   	   	vis[i] = 1;
   	   	int x = way[line][i].first;
   	   	int ww = way[line][i].second;
   	   	dfs(x, ed, t + ww, line);
   	   	vis[i] = 0;
   	}
   	for (int i:cnt[now]) {
   	   	if (i == line) continue;
   	   	int x;
   	   	for (int v = 0; v < way[i].size(); v++) {
   	   	   	if (way[i][v].first == now) x = v;
   	   	}
   	   	int nowid;
   	   	for (int v = 0; v < way[line].size(); v++) {
   	   	   	if (way[line][v].first == now) nowid = v;
   	   	}
   	   	if(x == way[i].size() - 1) continue;
   	   	int ww = way[i][x].second + way[line][nowid].second;
   	   	vis[x] = 1;
   	   	dfs(x, ed, t + ww, i);
   	   	vis[x] = 0;
   	}
}
signed main() {
   	ios::sync_with_stdio(false);
   	cin.tie(nullptr);
   	cout.tie(nullptr);
   	freopen("subway.in", "r", stdin);
   	freopen("subway.out", "w", stdout);
   	cin >> c >> n >> m >> d >> q;
   	for (int i = 1; i <= m; i++) {
   	   	cin >> w[i];
   	}
   	for (int i = 1; i <= n; i++) {
   	   	int k;
   	   	cin >> k;
   	   	for (int j = 1; j <= k; j++) {
   	   	   	int u, wi;
   	   	   	cin >> u >> wi;
   	   	   	way[i].push_back({u, wi});
   	   	   	cnt[u].push_back(i);
   	   	}
   	}
   	while (q--) {
   	   	int s, t;
   	   	cin >> s >> t;
   	   	ans = 0x3f3f3f3f;
   	   	for (int now:cnt[s]) {
   	   	   	dfs(s, t, w[s], now);
		}
		ans += w[t];
   	}
   	cout << ans;
   	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

地铁双向任意通行    
*/
