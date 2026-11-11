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
const int N = 2e6 + 5;
ll x[N];
int nxt[N];
namespace subA {
	void solve()
	{
		ll n = read(), d = read();
		for (int i = 1; i <= n; i++) x[i] = read();
		ll k = x[2] - x[1];
		if (d <= k || d >= x[n] - x[1]) return puts("0"), void();
		d /= k;
		ll len = 2 * d - 1;
		writech(n - len, '\n');
	}
}
void solve()
{
	ll n = read(), d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n, pos = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (x[mid] - x[i] <= d) l = mid + 1, pos = mid;
			else r = mid - 1;
		}
		nxt[i] = pos;
	}
	vector<int> tmp;
	ll ans = 0;
	for (int u = 1; u < n; u++)
		for (int v = u + 1; v <= n; v++)
		{
			tmp.clear(), tmp.pb(u);
			int now = u;
			while (nxt[now] > now)
			{
				now = min(nxt[now], v);
				tmp.pb(now);
				if (now == v) break;
			}
			if (now != v) continue;
			int len = tmp.size();
			int tot = 0;
			for (int i = 1; i < len - 1; i++)
			{
				int cnt = 0;
				for (int j = tmp[i - 1] + 1; j < tmp[i]; j++)
					if (nxt[j] >= tmp[i + 1]) cnt++;
				if (cnt == 1) tot++;
				if (tot > 1) break;
			}
			if (tot == 1) ans++;
		}
	writech(ans, '\n');
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), T = read();
//	c = 11;
	if (c == 11 || c == 12)
	{
		while (T--) subA::solve();
		return 0;
	}
	while (T--) solve();
	return 0;
}
/*
start coding at 15:29
finish coding bruteforce 24pts at 15:42

*/
