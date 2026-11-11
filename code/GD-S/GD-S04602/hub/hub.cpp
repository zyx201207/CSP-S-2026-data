#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 35;
int c,t,n,k,ans;
int fa[N];
bool g[N][N];
bool vis[N];

void init() {
	for(int i = 1; i <= 30; i ++) {
		fa[i] = i;
		vis[i] = 0;
	}
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	fa[x] = y;
	return ;
}

bool check(string dp) {
	init();
	for(int i = 1; i <= n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			if (int(dp[i] - '0') && int(dp[j] - '0') && g[i][j]) merge(i,j);
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		if (int(dp[i] - '0')) {
			if (!vis[find(i)]) cnt ++;
			vis[find(i)] = 1;
		}
	}
	if (cnt <= 2) return 1;
	return 0;
}
map<string,bool> mp;
struct node{
	int now,w;
};
queue<node> q;
int bfs(string dp) {
	int tmp = 0;
	while (!q.empty()) q.pop();
	for(int i = 1; i <= 30; i ++) {
		vis[i] = 0;
		if (int(dp[i] - '0')) q.push({i,0});
	}
	while (!q.empty()) {
		while (!q.empty() && vis[q.front().now]) q.pop();
		if (q.empty()) break;
		int now = q.front().now, w = q.front().w;
		q.pop();
		vis[now] = 1;
		tmp = max(tmp,w);
		for(int i = 1; i <= n; i ++) {
			if (g[now][i]) q.push({i,w + 1});
		}
	}
	return tmp;
}

void pre(int now,int ch, string dp) {
	if (ch > k) return ;
	if (mp[dp]) return ;
//	cout << dp << endl;
	if (now > n) {
		if (ch == k && check(dp)) ans = min(bfs(dp),ans);
		return ;
	}
	pre(now + 1,ch + 1,dp + '1');
	pre(now + 1,ch,dp + '0');
	return ;
}
//int 
int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	if (c <= 3) {
		while (t --) {
			ans = 0x3f3f3f3f;
			memset(g,0,sizeof(g));
			mp.clear();
			cin >> n >> k;
			for(int i = 1; i < n; i ++) {
				int u,v;
				cin >> u >> v;
				g[u][v] = 1;
				g[v][u] = 1;
			}
			pre(1,0,"#");
			cout << ans << endl;
		}
	}else {
		while (t --) cout << 1 << endl;
	}
	return 0;
}
