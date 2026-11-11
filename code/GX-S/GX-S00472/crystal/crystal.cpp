#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using ll = long long;

int main()
{
	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	
	ll n, m;
	std::cin >> n >> m;
	std::vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	std::partial_sum(a.begin(), a.end(), a.begin());
	ll sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum = (a[i] - a[i - 1]) * (i + 1) - a[i];
		if (sum == m)
		{
			std::cout << i + 1;
			break;
		}
		else if(sum > m)
		{
			std::cout << i;
			break;
		}
	}
}
