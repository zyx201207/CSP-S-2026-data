#include<iostream>
#include<algorithm>
using namespace std;
const long long inf = 1e12 + 5;

int n;
long long m, a[500010], dis[500010], ans = -inf, tot, res[500010];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool flg = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 3; i <= n; i++)
	{
		if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])
		{
			flg = 1;
		}
	}
	sort(a + 1, a + n + 1);
	if(!flg)
	{
		ans = 1;
		for(int i = 2; i <= n; i++)
		{
			m -= (a[i] - a[i - 1]) * (i - 1);
			if(m < 0) break;
			ans++;
		}
		cout << ans << endl;
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			tot = m;
			for(int j = i - 1; j >= 1; j--)
			{
				tot -= a[i] - a[j];
				if(tot < 0)
				{
					break;
				}
				res[i] = i - j;
			}
			res[i]++;
		}
		for(int i = 1; i <= n; i++)
		{
			ans = max(res[i], ans);
		}
		cout << ans << endl;
	}
	return 0;
}
