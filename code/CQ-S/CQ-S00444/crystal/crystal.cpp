#include <bits/stdc++.h>
#define re read()
#define wr(x) write(x)
#define sp putchar(' ')
#define endl puts("")
#define int long long

const int N = 5e5 + 10, INF = 0x3f3f3f3f;

using namespace std;

int read() {
	int y = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') f = c == '-' ? -1 : f, c = getchar();
	while (c >= '0' && c <= '9') y = (y << 1) + (y << 3) + (c ^ 48), c = getchar();
	return y * f;
}

void write(int x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48); 
} 

int a[N];
int n, m;
int pre[N];

bool check(int len) {
	for (int l = 1; l <= n - len + 1; l++) {
		int r = l + len - 1;
		if (m >= (r - l + 1) * a[r] - pre[r] + pre[l - 1]) return 1;
	}
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = re, m = re;
	int maxn = 0;
	for (int i = 1; i <= n; i++) a[i] = re;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	wr(l - 1), endl;
}
/*
5 5
1 2 4 8 9
*/
