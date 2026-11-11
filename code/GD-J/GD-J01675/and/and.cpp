#include <bits/stdc++.h>
using namespace std;
int m,n,l[100005];
long long a[100005],maxx,ans1,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
		if (i == 1)
		{
			ans1 = a[i];
		}
		ans1 = ans1 & a[i];
	}
	if (m == 1)
	{
		cout << maxx;
	}
	else if (m == n)
	{
		cout << ans1;
	}
	else if (n <= 2000)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
	}
	else
	{
		sort(a + 1,a + n + 1);
		ans = a[n];
		for (int i = 2;i <= m;i++)
		{
			ans = ans & a[n - i + 1];
		}
		cout << ans;
	}
	return 0;
}
