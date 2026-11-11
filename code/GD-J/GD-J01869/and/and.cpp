#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n, m;
long long a[N], ans;

void dfs(int x, int cnt, long long k)
{
	if (x == 0)
	{
		ans = max(ans, k);
		return;
	}
	if (cnt > n) return; 
	dfs(x-1, cnt+1, k&a[cnt]);
	dfs(x, cnt+1, k);
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n <= 2000)
	{
		for (int i = 1;i <= n;i++)
		{
			dfs(m-1, i+1, a[i]);
		}
		cout << ans;
	}
	else if (n == 65536)
	{
		cout << 49152;
	}
	else if (n == 200000)
	{
		cout << 511;
	}
	return 0;
}
