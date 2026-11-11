#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
int a[500010];
int sum[500010];
int ans;

bool check(int l, int r)
{
	int now = sum[r] - sum[l] - (l - 1) * (a[r] - a[l]);
	return now <= m;
}

bool cmp(int x, int y)
{
	return x < y;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i ++)
	{
		sum[i] = sum[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	for(int i = 1; i <= n; i ++)
	{
		int l = i, r = n;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(check(i, mid))
			{
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans = max(ans, (r - i + 1));
	}
	cout << ans << '\n';
	return 0;
}
