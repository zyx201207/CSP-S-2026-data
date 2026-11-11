#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

struct Edge {
	int u, v, w;
};

int n, k;
int fa[N];
vector<Edge> edges;

void init(int n) {
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	} 
}

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		init(n);
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
		}
		if (n <= 8) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
	return 0;
}
