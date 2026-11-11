#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 7;
int n, m, a[N];

template<typename T> inline void read (T &x) {
	x = 0; char c; int sign = 1;
	do {c = getchar(); if (c == '-') sign = -1;} while(!isdigit(c));
	do {x = x * 10 + c - '0'; c = getchar();} while (isdigit(c));
	x *= sign;
}

inline void print(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) 
		putchar(x + '0');
	else {
		print(x / 10);
		putchar(x % 10 + '0');
	}
}

int32_t main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n); read(m);
	if (m == 0 || n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		read(a[i]);
	}
	sort(a + 1, a + n + 1);
	int d = a[n] - a[n - 1], i;
	if (m < d) {
		cout << 0;
		return 0;
	}
	bool fg = 0;
	for (i = 2; i <= n; i ++) {
		int val = (i * (i - 1) / 2) * d;
		if (m < val) {
			fg = 1; break;
		}
	}
	if (fg) print(i - 1);
	else print(i);
	return 0;
}
