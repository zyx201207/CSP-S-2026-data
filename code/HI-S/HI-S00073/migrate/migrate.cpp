#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

static int c, t;

static long long getVectorArrayElementCount(const vector<pair<long long, long long>> &arr, const pair<long long, long long> &element)
{
	long long cnt = 0;
	for (size_t i = 0; i < arr.size(); i++)
		if (arr[i] == element)
			++cnt;
	return cnt;			
}

static long long getDoublePathIslandCount(const vector<long long> &arr, int maxSingleLength)
{
	vector<pair<long long, long long>> arr1;
	long long ret = 0;
	for (size_t i = 0; i < arr.size() - 2; i++)
	{
		for (size_t j = arr.size() - 2; j >= i + 1; j--)
		{
			if (arr[j] - arr[i] > maxSingleLength)
				continue;
			for (size_t k = arr.size() - 1; k >= j + 1; k--)
			{
				if (arr[k] - arr[j] > maxSingleLength)
					continue;
				arr1.push_back({i, k});
				if (getVectorArrayElementCount(arr1, {i, k}) == 2)
					++ret;
				else if (getVectorArrayElementCount(arr1, {i, k}) == 3)
					--ret;
			}
		}
	}
	return ret;
}

int main(void)
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int testData = 0; testData < t; testData++)
	{
		long long n, d;
		vector<long long> x;
		cin >> n >> d;
		for (long long i = 0; i < n; i++)
		{
			long long xi;
			cin >> xi;
			x.push_back(xi);
		}
		cout << getDoublePathIslandCount(x, d) << endl;
	}
	return 0;
}
