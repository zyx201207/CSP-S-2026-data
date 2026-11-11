#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 5e5 + 10;

struct Edge {
	int v, nxt;
}e[N << 1];

int C;
int n, k;
int head[N], cnt;

void add(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int _;
	cin >> C >> _;
	while (_--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		int m = (n + 1) / 2;
		cout << (m - k) / 4 + 1 << '\n';
	}
	
	return 0;
}
