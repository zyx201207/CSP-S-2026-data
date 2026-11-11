#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace io {
	const int N = 1 << 20;
	char buf[N], *p = buf, *q = buf;
	
	inline int gc() {
		if (p == q) { q = (p = buf) + fread(buf, 1, N, stdin); if (p == q) return EOF; }
		return (unsigned char)*p++;
	}
	
	template<typename T>
	inline bool read(T &x) {
		x = 0; int f = 1, c = gc();
		while (c < '0' || c > '9') { if (c == EOF) return 0; if (c == '-') f = -1; c = gc(); }
		while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = gc();
		x *= f;
		return 1; 
	}
}
using io::read;

const int N = 2e6 + 10;
int n; ll d;
int x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c, t;
	read(c); read(t);
	while (t--) {
		read(n); read(d);
		for (int i = 1; i <= n; i++) cin >> x[i];
	}
	
	return 0;
}

