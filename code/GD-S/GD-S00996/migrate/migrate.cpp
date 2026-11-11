#include <bits/stdc++.h>
using namespace std;
int n;
long long d;
long long x[2000006];
int mn;
int cc = 0;
int ttt;
void dfs(int nw, int cnt)
{
	if(cnt > mn)
	{
		return;
	}
	if(nw == ttt)
	{
		if(cnt < mn)
		{
			mn = cnt;
			cc = 1;
		}
		else if(cnt == mn)
		{
			cc++;
		}
		return;
	}
	for(int i = nw + 1; i <= ttt && x[i] - x[nw] <= d; i++)
	{
		dfs(i, cnt + 1);
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &x[i]);
		}
		if(c == 0 || c == 12)
		{
			int anss = 0;
			int cntt = d / (x[2] - x[1]);
			for(int i = 1; i <= n - 1; i++)
			{
				if(i % cntt != 0 || i / cntt == 1)
				{
					anss += (n - i);
				}
			}
			cout << anss << '\n';
			continue;
		}
		int anss = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ttt = j;
				cc = 0;
				mn = 2100000000;
				dfs(i, 1);
				anss += (cc == 2);
			}
		}
		cout << anss << '\n';
	}
	return 0;
}

