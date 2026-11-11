// 6
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int T, T;
int n, m;
int hd[N], ver[M << 1], nxt[M << 1], idx = 0;

inline 
void add(int x, int y) {
	ver[++ idx] = y;
	nxt[idx] = hd[x];
	hd[x] = idx;
}

inline 
void init() {
	idx = 0;
	memset(hd, 0, sizeof hd);
}

inline 
void solve() {
	cin >> n >> m;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
//	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	
	cin >> T >> T;
	while (T --) init(), solve();
	
	return 0;
}

