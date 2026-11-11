#include <iostream>
#include <vector>
#include <queue>

bool valid(std::vector<int>* graph, const int start, const int end, const int limit)
{
	std::queue<std::pair<int, int>> pushed;
	pushed.push({ start, 0 });

	int min_loc = -1, min_count = 0;
	while (!pushed.empty())
	{
		std::pair<int, int> now = pushed.front();
		pushed.pop();

		if (min_loc > -1 && now.second > min_loc)
		{
			continue;
		}
		else if (now.first == end)
		{
			if (min_loc == -1)
			{
				min_loc = now.second;
				min_count++;
				continue;
			}
			else if (min_count <= 1)
			{
				min_count++;
				continue;
			}
			else
			{
				return false;
			}
		}

		for (int x : graph[now.first])
		{
			pushed.push({ x, now.second + 1 });
		}
	}

	return min_count == 2;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int test_index, t;
	std::cin >> test_index >> t;

	while (t--)
	{
		int n, limit;
		std::cin >> n >> limit;

		int* all = new int[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> all[i];
		}

		std::vector<int>* graph = new std::vector<int>[n];
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (std::abs(all[j] - all[i]) <= limit)
				{
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (valid(graph, i, j, limit))
				{
					count++;
				}
			}
		}

		std::cout << count << std::endl;
	}

	return 0;
}
