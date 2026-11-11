#include <bits/stdc++.h>
#define ft first
#define sd second
#define md make_pair
#define pb push_back
#define gc getchar
#define pc putchar
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
ll read()
{
	ll res = 0, f = 1; char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = gc();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = gc();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
const int N = 5e5 + 5;
ll a[N], sum[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = read(); ll m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i, pos = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (1ll * (i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) r = mid - 1, pos = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - pos + 1ll);
	}
	write(ans);
	return 0;
}
/*
finish coding at 14:41
*/
