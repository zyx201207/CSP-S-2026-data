#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int n , k;
int h[2*N] , nxt[2*N] , to[2*N] , cnt , dis[N] , d[N];

bool vis[N] , vis1[N];

void add (int u , int v) {
	nxt[++cnt] = h[u];
	h[u] = cnt;
	to[cnt] = v; 
}

int popcnt (int x) {
	int cnt = 0;
	while (x) {
		cnt++;
		x -= x & (-x);
	}
	return cnt;
}

void dfs (int x , int fa) {
	for (int i = h[x] ; i ; i = nxt[i]) {
		int v = to[i];
		if (v == fa) continue;
		d[v] = d[x] + 1;
		dfs (v , x);
	}
}

void dfs1 (int x , int fa) {
	vis1[x] = 1;
	for (int i = h[x] ; i ; i = nxt[i]) {
		int v = to[i];
		if (v == fa) continue;
		if (vis[v]) 
			dfs1 (v , x);
	}
}

void solve () {
	cin >> n >> k;
	cnt = 0;
	for (int i = 1 ; i <= n ; i++) h[i] = 0;
	for (int i = 1 ; i < n ; i++) {
		int u , v;
		cin >> u >> v;
		add (u , v) , 
		add (v , u);
	}
	int ans = 1e18;
	for (int i = 0 ; i < (1 << n) ; i++) {
		int x = popcnt(i);
		if (x != k) continue;
		for (int j = 1 ; j <= n ; j++)
			if ((1 << (j-1)) & i) vis[j] = 1;
			else vis[j] = 0;
		for (int j = 1 ; j <= n ; j++) vis1[j] = 0;
		for (int j = 1 ; j <= n ; j++) dis[j] = 1e18;
		int cnt = 0;
		for (int j = 1 ; j <= n ; j++)
			if (vis[j] && !vis1[j])
				dfs1 (j , 0) , cnt++;
		if (cnt > 2) continue;
		for (int j = 1 ; j <= n ; j++) {
			if (vis[j]) {
				for (int k = 1 ; k <= n ; k++) d[k] = 1e18;
				d[j] = 0;
				dfs (j , 0);
				for (int k = 1 ; k <= n ; k++) dis[k] = min (d[k] , dis[k]); 
			}
		}
		if (cnt > 2) continue;
		int maxd = 0;
		for (int k = 1 ; k <= n ; k++)
			maxd = max (maxd , dis[k]);
		ans = min (ans , maxd);
	}
	cout << ans << endl;
}

signed main () {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int cid , T;
	cin >> cid >> T;
	while (T--)
		solve();	
	return 0;
}
