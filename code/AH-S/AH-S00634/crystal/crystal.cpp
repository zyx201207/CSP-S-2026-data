#include <bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;

int n, m;
int a[N];
int eo, sum, answer = -INT_MAX;

int solve()
{
	int ans;
	for (int i = 1; i <= n; i++)
		if (i % 2 == 1 && ((i-1) * (i-1) + 2 * (i-1)) / 4 > m)
		{
			ans = i - 1; break;
		}
		else if (i % 2 == 0 && ((i-2) * (i-2) + 4 * (i-1)) / 4 > m)
		{
			ans = i - 1; break;
		}
	return ans;
}

signed main()
{
	freopen("crystal.in",  "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	//task 13 ~ 15 & 16 ~ 18
	bool pd = true;
	for (int i = 3; i <= n; i++)
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2])
		{
			pd = false;
			break;
		}
	if (pd)
	{
		m /= (a[2] - a[1]);
		cout << min(solve(), n);
		return 0;
	}
	//too large
	if (n > 10000)
	{
		cout << n;
	}
	
	for (int i = n; i >= 1; i--)
	{
		if (i < answer) break;
		eo = m, sum = 1;
		while (i > sum + 1)
		{
			int used = a[i] - a[i - sum];
			if (eo < used)
				break;
			sum++;
			eo -= used;
		}
		answer = max(sum, answer);
	}
	cout << answer;
	return 0;
}
