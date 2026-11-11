#include<bits/stdc++.h>

#define int long long 
#define N 200010

using namespace std;

int n, m;
int a[N];
string c[N];
int ans1 = -1;
int ad;

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans1 = max(ans1, a[i]);
	}
	if (m == 1)
	{
		cout << ans1 << '\n';
	}
	else if (m == 2)
	{
		int ans2 = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ans2 = max(ans2, (a[i] & a[j]));
			}
		}
		cout << ans2; 
	}
	else if (m == n)
	{
		int ans3 = a[1];
		for (int i = 2; i <= n; i++)
		{
			ans3 &= a[i];
		}
		cout << ans3;
	}
	else if (m == n - 1)
	{
		sort(a + 1, a + n + 1);
		int ans4 = a[2];
		for (int i = 3; i <= n; i++)
		{
			ans4 &= a[i];
		}
		cout << ans4;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
