#include <bits/stdc++.h>

long long n, m, total, res, ans, i, sum;
bool equal = true, equalDifference = true;
std::vector<long long> a(500005);

int Check();

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a[i];
		if (a[i] != i)
			equal = false;
	}
	
	if (equal == true)
	{
		std::cout << std::min(n, (long long)(sqrt(2 * m - 1) + 1));
		return 0;
	}
	
	std::sort(a.begin(), a.begin() + n - 1);

	for (int i = 1; i <= n; i++)
	{
		res = 0;
		total = m;
		for (int j = i - 1; j > 0; j--)
		{
			if (total >= (a[i] - a[j]))
			{
				total -= (a[i] - a[j]);
				res++;
			}
		}
		ans = std::max(ans, res);
	}
	
	std::cout << ans + 1;
	return 0;
}

