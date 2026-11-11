#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e6 + 5;

int t, c;
int n;
ll d;
ll x[MAXN];
bool vis[MAXN];

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

ll readll()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while (t--)
	{
		n = read(), d = readll();
		for (int i = 1; i <= n; i++)
		{
			vis[i] = true;
		}
		int f = n + 1;
		bool ok = false;
		for (int i = 1; i <= n; i++)
		{
			x[i] = readll();
			if (x[i] - x[i - 1] > d)
			{
				ok = true;
				f = i;
				break;
			}
		}
		if (ok)
		{
			for (int i = f + 1; i <= n; i++)
			{
				x[i] = readll();
			}
		}
		int ans = 0;
		for (int i = 1; i <= f - 1; i++)
		{
			for (int j = 2; j <= f - 1; j++)
			{
				if (vis[i] && vis[j] && x[j] - x[i] >= 2 * d - 1 && (x[j] - x[i] + 1) % d == 0) ans++;
			}
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++)
		{
			x[i] = 0;
		}
	}
	return 0;
}
