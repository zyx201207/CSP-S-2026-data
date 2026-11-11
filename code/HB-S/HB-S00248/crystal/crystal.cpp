#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long n, limit;
	std::cin >> n >> limit;

	long long* all = new long long[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> all[i];
	}

	std::sort(all, all + n);

	std::queue<long long> pushed;
	long long cost = 0, max_count = 1;
	pushed.push(all[0]);
	for (int i = 1; i < n; i++)
	{
		cost += (all[i] - pushed.back()) * pushed.size();
		pushed.push(all[i]);
		while (cost > limit)
		{
			cost -= all[i] - pushed.front();
			pushed.pop();
		}

		max_count = std::max(max_count, (long long)(pushed.size()));
	}

	std::cout << max_count << std::endl;

	return 0;
}
