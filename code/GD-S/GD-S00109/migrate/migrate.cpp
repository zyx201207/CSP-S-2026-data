#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using pli = pair<ll, int>;

const int N = 5e3 + 5;
ll a[N];
vector<int> g[N];

int d[N][N];
int cnt[N][N];
bool vis[N][N];
void bfs(int s) {
	queue<int> q;
	q.push(s);
	d[s][s] = 0;
	vis[s][s] = true;
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(int v : g[u]) {
			if(d[s][u] + 1 < d[s][v]) {
				d[s][v] = d[s][u] + 1;
				cnt[s][v] = 1;
				if(!vis[s][v]) q.push(v);
				vis[s][v] = true;
			} else if(d[s][u] + 1 == d[s][v]) cnt[s][v]++;
		}
	}
}

void solve() {
	ll n, dd;
	cin >> n >> dd;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) g[i] = {};
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(a[j] - a[i] > dd) break;
			g[i].push_back(j);
		}
	}
	
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	ll ans = 0;
	for(int i = 1; i <= n; i++) bfs(i);


	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(cnt[i][j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, T;
	cin >> c >> T;
	while(T--) {
		solve();
	}
	return 0;
}

