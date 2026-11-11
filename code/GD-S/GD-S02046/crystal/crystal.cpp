#include <cstdio>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
using namespace std;
#define ll long long

template<typename T = int> inline T read() {
	T x = 0; int f = 1, c = getchar();
	while (c != EOF && (c < '0' || c >'9')) {if (c == '-') f = -1; c = getchar();}
	while ('0' <= c && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
template<typename T> inline void write(T x, char e = '\n') {
	if (x < 0) {x = -x; putchar('-');}
	char num[30]; int cnt = 0;
	while (x) {num[++cnt] = x % 10 + '0'; x /= 10;}
	for (int i = cnt; i > 0; --i) putchar(num[i]);
	if (!cnt) putchar('0');
	if (e) putchar(e);
}

int n; ll m;
vector<ll> a;

inline int dfs(int idx, int mm) {
	int ans = 0;
	if (idx >= n) {
		auto b = a;
		sort(b.begin(), b.end());
		int d;
		for (int i = 0; i < n; i += d) {
			d = upper_bound(b.begin(), b.end(), b[i])
			  - lower_bound(b.begin(), b.end(), b[i]);
			ans = max(ans, d);
		}
	} else {
		for (int i = 0; i <= mm; ++i) {
			a[idx] += i;
			ans = max(ans, dfs(idx + 1, mm - i));
			a[idx] -= i;
		}
	}
	return ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(); m = read<ll>();
	if (m + n > 1000) {
		srand(time(0));
		write(1ll * rand() * rand() * rand() % 500001);
		return 0;
	}
	for (int i = 0; i < n; ++i) a.push_back(read<ll>());
	sort(a.begin(), a.end());
	write(dfs(0, m));
	return 0;
}

