#include<bits/stdc++.h>
using namespace std;
uint8_t buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 =(p1 = buf) + fread(buf, 1, 1 << 20, stdin)), *p1++)
int readint() {
	int k = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) {
		if (c == '-')
			f = -1;
	}
	for (; isdigit(c); c = gc()) {
		k = k * 10 + (c - '0');
	}
	return f * k;
}

long long readll() {
	long long k = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) {
		if (c == '-')
			f = -1;
	}
	for (; isdigit(c); c = gc()) {
		k = k * 10 + (c - '0');
	}
	return f * k;
}

const int N = 500005;
int n;
uint64_t m;
long long min_a = 0x3f3f3f3f3f3f3f3f;
vector<long long> a;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = readint(), m = readll();
	a.reserve(n);
	for (int i = 0; i < n; i++) {
		long long x = readll();
		a.push_back(x);
		min_a = min(min_a, x);
	}
	sort(a.begin(), a.end());
	uint64_t ans = 0;
	__int128 dx = 0;
	for (long long i = 0; i < n && dx <= m; i++) {
		ans++;
		if (i + 1 != n && a[i] != a[i + 1]) {
			dx += (__int128)((__int128)a[i + 1] - (__int128)a[i]) * (i + 1);
		}
	}
	cout << ans << '\n';
}
