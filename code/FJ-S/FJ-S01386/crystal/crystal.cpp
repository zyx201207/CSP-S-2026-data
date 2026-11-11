#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005
long long a[MAXN], pre[MAXN];
int ans = 1;

long long getsum(int l, int r)
{
	return pre[r] - pre[l - 1] - 1ll * (a[r] - a[l - 1]) * (l - 1);
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + 1ll * (a[i] - a[i - 1]) * (i - 1);
	}
	int l = 1;
	for (int r = 1; r <= n; r++)
	{
		while (getsum(l, r) > m) 
		{
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
