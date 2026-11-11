#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;

int n;
ll m;
int dp[MAXN]; // dp[u] : 前 u 个数都可以合成最少需要多少次操作 

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
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = readll();
	vector<ll> a(n + 1);
	dp[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = readll();
	}
	sort(a.begin() + 1, a.end());
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	if (m >= dp[n]) cout << n << '\n';
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (dp[i] <= m && dp[i + 1] > m)
			{
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}
