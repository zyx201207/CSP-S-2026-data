#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
constexpr int N = 2e5 + 5, mod = 998244353;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<char> c(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	int i = 1, j = n;
	i64 ans = 0;
	while (i <= j)
	{
		if (c[i] == c[j])
		{
			if (a[i] > a[j])
			{
				a[i] -= a[j];
				j--;
			}
			else
			{
				a[j] -= a[i];
				i++;
			}
		}
		else
		{
			if (a[i] > a[j])
			{
				ans += a[j];
				a[i] -= a[j];
				j--;
			}
			else
			{
				ans += a[i];
				a[j] -= a[i];
				i++;
			}
		}
	}
	cout << ans;
	return 0;  
}
