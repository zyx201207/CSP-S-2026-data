#include<bits/stdc++.h>
#define int long long
#define debug puts("\n--------------")
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

inline int read() {
	int x = 0, k = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') k = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * k;
}

inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + '0');
	return;
}

const int N = 5e5 + 50;
int n, m, ans;
int a[N];
int sum[N];
queue<int> que;
int siz;

inline void solve() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", " w", stdout);
	
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		que.push(i);
		++siz;
		int s = a[i] * (siz - 1) - (sum[i - 1] - sum[que.front() - 1]);
		while (!que.empty() && s > m) {
			que.pop();
			--siz;
			s = a[i] * (siz - 1) - (sum[i - 1] - sum[que.front() - 1]);
		}
		ans = max(ans, siz);
	}
	
	write(ans);
	putchar('\n');
	return;
}

int32_t main() {
	solve();
	return 0;
}
