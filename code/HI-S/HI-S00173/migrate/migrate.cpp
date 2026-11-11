// I often recall the past, For the CSP-S2026.
// WC 2027 give my dream
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define rep2(i, a, b) for(int i=a; i>=b; i--)
const int N = (int)2e6 + 10;

int n;

ll d, x[N], to[N], mx;
bool vis[2*N];
struct node {
	ll u, fa, cnt;
};
vector<int> g[N];

ll bfs(int st, int ed) {
//	cout << "bfs: [st, ed] = [ " << st << ", " << ed << "]" << endl;
	memset(to, 0, sizeof(to));
	queue<node> q;
	q.push({st, 0, 0});
	while (!q.empty()) {
		node u = q.front();
		if (u.u == ed && u.u != u.fa) {
			to[u.cnt]++;
		}
		q.pop();
		for (int v:g[u.u]) {
			if (v != u.fa) {
				q.push({v, u.u, u.cnt+1});
			} 
		}
	}
	
	int ans = 0;
	rep (i, 1, mx) {
//		cout << to[i] << ' ';
//		if (to[i] != 0 && to[i] != 2) break;
		if (to[i] == 2) {
//			cout << st << ' ' << ed << endl;
			ans++;
			break;
		}
	}
//	cout << endl;
	return ans;
}

void solve() {
	memset(x, 0, sizeof(x));
	memset(vis, 0, sizeof(vis));
	rep (i, 1, n) g[i].clear();
	mx = 0;
	cin >> n >> d;
	rep (i, 1, n) {
		cin >> x[i];
		mx = max(mx, x[i]);
		vis[(N+x[i])] = true;
	}
	
//	cout << "vis" << endl;
//	cout << endl;
	
	int dx = x[2]-x[1];
	bool flaga = true;
	rep (i, 2, n) {
		if (x[i]-x[i-1] != dx) {
			flaga = false;
			break;
		} 
	} 
	
	rep (i, 1, n) {
//		cout << "this is the link graph " << i << endl;
		rep (j, 1, d) {
			if (vis[N+x[i]+j]) {
				g[i].push_back(x[i]+j);
//				cout << x[i]+j << ' ';
			}
		}
//		cout << endl;
	}
	if (flaga) {
		if (dx > d) {
			cout << 0 << endl;
			return ;
		}
	}
	
	int ans = 0;
	rep (i, 1, n) {
		rep (j, i+1, n) {
			ans += bfs(x[i], x[j]);
		}
	}
	
	cout << ans << endl;
} 

int main() {
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	 
	int c, t = 1;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	// gg.
	return 0;
}
