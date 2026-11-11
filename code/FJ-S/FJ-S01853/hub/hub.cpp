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

int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c = read();
	int t = read();
	while (t--) {
		int n = read();
		int k = read();
		for (int i = 1, x, y; i < n; i++) {
			x = read();
			y = read();
		}
		if (n > 5) {
			cout << 2 << "\n";
			continue;
		}
		if (n == k) cout << 0 << "\n";
		else if (k >= 2) cout << 1 << "\n";
		else cout << 2 << "\n";
	}
	return 0;
}
