#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read () {
	int w = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		w = w * 10 + c - '0';
		c = getchar();
	}
	return w * f;
}

const int mxn = 1e5 + 5 + 3e4;

int w[mxn];

vector<pair<int, int>> ptor[5000];
vector<pair<int, int>> rtop[5000];

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c = read();
	int n = read();
	int m = read();
	int d = read();
	int q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		int k = read();
		for (int j = 1; j <= k; j++) {
			int a = read();
			int t = read();
			ptor[a].push_back({i, t});
			rtop[i].push_back({a, t});
		}
	}
	while (q--) {
		int x = read();
		int y = read();
		ll ans = w[x] + w[y];
		dfs(int)
	}
	return 0;
}
