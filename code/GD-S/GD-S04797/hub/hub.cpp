#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

const int N = 2e5 + 5;
const int mod = 998244353;
const int inf = 4e18;

int zh, T, n, k;
int fa[N], vis[N], dis[N];
vector<int> g[N];
pii e[N];

int find(int x){
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

int bfs(int x){
	queue<int> q;
	q.push(x);
	for (int i = 1; i <= n; i++) dis[i] = inf;
	dis[x] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		if (vis[u]) return dis[u];
		for (auto v : g[u]){
			if (dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return inf;
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> zh >> T;
	while (T--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++) cin >> e[i].fir >> e[i].sec, g[e[i].fir].pb(e[i].sec), g[e[i].sec].pb(e[i].fir);
		int ans = inf;
		for (int i = 0; i < (1 << n); i++){
			if (__builtin_popcount(i) != k) continue;
			for (int j = 1; j <= n; j++) vis[j] = (i >> (j - 1)) & 1, fa[j] = j;
			int mx = 0;
			for (int j = 1; j < n; j++){
				if (vis[e[j].fir] && vis[e[j].sec]) fa[find(e[j].sec)] = find(e[j].fir);
			}
			set<int> st;
			for (int j = 1; j <= n; j++){
				if (vis[j] == 1) st.insert(find(j));
				mx = max(mx, bfs(j));
			}
			if (st.size() == 2) ans = min(ans, mx);
		}
		cout << ans << endl;
	}
	return 0;
}
