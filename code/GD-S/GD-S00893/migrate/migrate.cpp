#include <bits/stdc++.h>
using namespace std;

int c, t;
int n;
long long d;
long long x[2000005];
int lst[2000005], nxt[2000005];
int lft[2000005], rgt[2000005];

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		memset(lft, 0, sizeof(lft));
		memset(rgt, 0, sizeof(rgt));
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		int p = 1;
		for (int i = 1;i <= n;i++)
		{
			while (x[i] - x[p] > d) p++;
			lst[i] = p;
		}
		p = n;
		for (int i = n;i >= 1;i--)
		{
			while (x[p] - x[i] > d) p--;
			nxt[i] = p;
		}
		long long ans = 0;
		for (int i = 1;i <= n;i++)
		{
			if (nxt[i] < n)
			{
				int j = nxt[nxt[i] - 1];
				if (j <= nxt[i] || j <= nxt[nxt[i] - 2]) continue;
				rgt[i]++;
				lft[j]++;
				ans++;
			}
			else break;
		}
		for (int i = 2;i <= n;i++)
		{
			if (lst[i] == i - 1)
			{
				lft[i] += lft[i - 1];
				ans += lft[i - 1];
			}
		}
		for (int i = n - 1;i >= 1;i--)
		{
			if (nxt[i] == i + 1)
			{
				rgt[i] += rgt[i + 1];
				ans += rgt[i + 1];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
