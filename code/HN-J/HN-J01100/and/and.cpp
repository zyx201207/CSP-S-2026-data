#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],maxn = 0;
void dfs(int step,int cnt,int sum)
{
	if (step == n || cnt == m)
	{
		if (cnt == m) maxn = max(maxn,sum);
		return;
	}
	if (n - step < m - cnt) return;
	dfs(step + 1,cnt + 1,sum & a[step + 1]);
	dfs(step + 1,cnt,sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (n == m)
	{
		int k = a[1];
		for (int i = 2;i <= n;i++) k &= a[i];
		cout << k;
		return 0;
	}
	if (m == 1)
	{
		maxn = a[1];
		for (int i = 2;i <= n;i++) maxn = max(maxn,a[i]);
		cout << maxn;
		return 0;
	}
	if (n <= 20)
	{
		dfs(0,0,1024 * 1024 - 1);
		cout << maxn;
		return 0;
	}
	if (m == 1)
	{
		for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) maxn = max(maxn,a[i] & a[j]);
		cout << maxn;
		return 0;
	}
	if (m == n - 1)
	{
		for (int i = 1;i <= n;i++)
		{
		}
		cout << maxn;
		return 0;
	}
	int maxn = a[1];
	for (int i = 2;i <= n;i++) maxn = max(maxn,a[i]);
	if (maxn <= 3)
	{
		int x = 0,y = 0,z = 0;
		for (int i = 1;i <= n;i++)
		{
			x += (a[i] == 1);
			y += (a[i] == 2);
			z += (a[i] == 3);
		}
		if (y >= m) cout << 3;
		else if (y + z >= m) cout << 2;
		else cout << 1;
		return 0;
	}
	sort(a + 1,a + n + 1);
	cout << a[n - m + 1];
	return 0;
}
