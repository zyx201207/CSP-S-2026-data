#include <bits/stdc++.h>
using namespace std;

int const N = 2e5 + 10;

int a[N], d[N], ans, n;

bool flag1 = true, flag2 = true;

bool check(int x)
{
	x++;
	while(x != 1)
	{
		if(x % 2 == 1) return false;
		x /= 2;
	}
	return true;
}

void dfs(int p, int m, int k)
{
	if(p > n) return ;
	if(m == 0)
	{
		ans = max(ans, k);
		return ;
	}
	for(int i = p + 1; i <= n; i++)
	{
		if(k == -1) dfs(i, m - 1, a[i]);
		else dfs(i, m - 1, k & a[i]);
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i == 1) d[i] = a[i];
		else d[i] = d[i - 1] & a[i];
		if(check(a[i]) == false) flag1 = false;
		if(i > 1 && a[i] - a[i - 1] != 1) flag2 = false;
	}
	if(n == m)
	{
		cout << d[n];
		return 0;
	}
	if(flag1 == true)
	{
		sort(a + 1, a + 1 + n);
		cout << a[n - m + 1];
		return 0;
	}
	if(flag2 == true) {
		if(n == 1) cout << 0;
		else if(n == 2 || n == 3) cout << 2;
		else cout << 0;
	}
	dfs(1, m, -1);
	cout << ans;
	return 0;
}
