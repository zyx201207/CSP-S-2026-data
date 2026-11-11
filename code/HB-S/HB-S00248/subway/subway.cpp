#include <iostream>
#include <vector>
#include <climits>

struct Edge
{
	unsigned long long end;
	unsigned long long weight;
};

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	unsigned long long test_index, n, m, limit, t;
	std::cin >> test_index >> n >> m >> limit >> t;

	unsigned long long* start_weight = new unsigned long long[m]; // The weight to get in the station from outside
	for (unsigned long long i = 0; i < m; i++)
	{
		std::cin >> start_weight[i];
	}

	std::vector<std::pair<unsigned long long, unsigned long long>>* weights = new std::vector<std::pair<unsigned long long, unsigned long long>>[m]; // The weight to get in a subway line from the station
	for (unsigned long long i = 0; i < n; i++)
	{
		unsigned long long size;
		std::cin >> size;

		while (size--)
		{
			unsigned long long x, weight;
			std::cin >> x >> weight;
			weights[x - 1].push_back({ i, weight });
		}
	}

	unsigned long long** distance = new unsigned long long*[n];
	for (unsigned long long i = 0; i < n; i++)
	{
		distance[i] = new unsigned long long[n];
		for (unsigned long long j = 0; j < n; j++)
		{
			distance[i][j] = LLONG_MAX;
		}
		distance[i][i] = 0;
	}
	for (unsigned long long i = 0; i < m; i++)
	{
		if (weights[i].size() >= 2)
		{
			for (unsigned long long j = 0; j < weights[i].size(); j++)
			{
				for (unsigned long long k = j + 1; k < weights[i].size(); k++)
				{
					distance[weights[i][j].first][weights[i][k].first] = weights[i][j].second + weights[i][k].second;
					distance[weights[i][k].first][weights[i][j].first] = weights[i][j].second + weights[i][k].second;
				}
			}
		}
	}

	for (unsigned long long k = 0; k < n; k++)
	{
		for (unsigned long long i = 0; i < n; i++)
		{
			for (unsigned long long j = 0; j < n; j++)
			{
				distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}

	while (t--)
	{
		unsigned long long start, end;
		std::cin >> start >> end;
		start--, end--;

		unsigned long long min_count = LLONG_MAX;
		for (const std::pair<unsigned long long, unsigned long long>& x : weights[start])
		{
			for (const std::pair<unsigned long long, unsigned long long>& y : weights[end])
			{
				min_count = std::min(min_count, start_weight[start] + x.second + distance[x.first][y.first] + y.second + start_weight[end]);
			}
		}

		std::cout << min_count << std::endl;
	}

	return 0;
}
