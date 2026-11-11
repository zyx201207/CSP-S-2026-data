#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define endl putchar('\n')
using namespace std;
int read()
{
	int sum = 0, f = 1;
	char ch = getchar();
	for (ch;ch < '0' || ch > '9';ch = getchar()) if (ch == '-') {f = -1;}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void gmax(int &x, int y)
{
	if (y > x) x = y;
}
void gmin(int &x, int y)
{
	if (y < x) x = y;
}
const int N = 5e5 + 5;
int n, m, a[N], sum[N];
int findpos(int R)
{
	int l = 1, r = R - 1, ret = R;
	while (l <= r)
	{
		int mid = l + r >> 1;
		int tmp = sum[R - 1] - sum[mid - 1];
		if (a[R] * (R - mid) <= m + tmp) ret = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ret;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int r = 1;r <= n;r++) gmax(ans, r - findpos(r) + 1);
	write(ans);
	return 0;
}
