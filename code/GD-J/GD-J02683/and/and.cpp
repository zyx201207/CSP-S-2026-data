#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool b[200005];
int n, m, ans = -1e9;
bool cmp(int x, int y)
{
	return x > y;
}
void dfs(int step, int cnt)
{
	if (cnt > m) return ;
	if (step > n)
	{
		if (cnt != m) return ;
		int cnt = 0, res;
		for (int i = 1; i <= n; i++)
		{
			if (b[i]) 
			{
				if (cnt == 0) res = a[i];
				else res &= a[i];
				cnt++;
			}
		}
		ans = max(res, ans);
		return ;
	}
	b[step] = 0;
	dfs(step + 1, cnt);
	b[step] = 1;
	dfs(step + 1, cnt + 1);
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20) dfs(1, 0);
	else if (n <= 2000)
	{
		if (m == 1) 
		{
			for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
		}
		else if (m == 2)
		{
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					ans = max(ans, a[i] & a[j]);
		}
		else if (m == n)
		{
			ans = a[1];
			for (int i = 2; i <= n; i++) ans &= a[i];
		}
	}
	else
	{
		sort(a+1, a+n+1, cmp);
		ans = a[m];
	}
	cout << ans;
	return 0;
}
