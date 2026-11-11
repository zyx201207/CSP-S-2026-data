#include <bits/stdc++.h>
using namespace std;

int n, m, vis[200050], ll[10];
long long arr[200050], ans = -1;

void dfs(int now, long long an, int cnt)//scxuanlejige
{
	if (cnt == m)
	{
		//cout << "ans== " << now << " " << an << " " << cnt << '\n';
		ans = max(ans, an);
		return;
	}	
	if (now > n)
	{
		return;
	}
	long long la = an;
	an &= arr[now];
	//cout << now << " " << an << " " << cnt << '\n';
	dfs(now + 1, an, cnt + 1);
	dfs(now + 1, la, cnt);
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	long long maxn = -1, maxnn = -1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		maxnn = max(maxnn, arr[i]);
	}
	if (n == 1)
	{
		cout << arr[1] << '\n';
		return 0;
	}
	if (m == 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			maxn = max(maxn, arr[i]);
		}
		cout << maxn << '\n';
		return 0;
	}
	if (n <= 20)
	{
		for (int i = 1; i <= n - m + 1; ++i)
		{
			dfs(i + 1, arr[i], 1);
		}
		cout << ans << '\n';
		return 0;
	}
	
	if (m == 2)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j <= n; ++j)
			{
				long long kk = (arr[i] & arr[j]);
				maxn = max(maxn, kk);
			}
		}
		cout << maxn << '\n';
		return 0;
	}
	if (m == n)
	{
		maxn = arr[1];
		for (int i = 2; i <= n; ++i)
		{
			maxn &= arr[i]; 
		}
		cout << maxn << '\n';
		return 0;
	}
	if (m == n - 1)
	{
		long long we = 0, maxlowbi = -1;
		for (int i = 1; i <= n; ++i)
		{
			int kkk = arr[i] & -arr[i];
			if (kkk > maxlowbi)
			{
				maxlowbi = kkk;
				we = i; 
			}
		}
		maxn = arr[1];
		for (int i = 2; i <= n; ++i)
		{
			if (we == i)
			{
				continue;
			}
			maxn &= arr[i]; 
		}
		cout << maxn << '\n';
		return 0;
	}
	if (maxnn < 4)
	{
		int cur = m, noo = maxnn, ans = maxnn;
		for (int i = 1; i <= n; ++i)
		{
			ll[arr[i]]++;
		}
		while (cur > 0)
		{
			if (ll[noo] != 0)
			{
				ans &= noo;
				cur -= ll[noo];
			}
			noo--;
		}
	}
	return 0;
} 
