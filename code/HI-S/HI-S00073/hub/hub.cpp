#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

static int c, t;

int main(void)
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		vector<pair<int, int>> a;
		cin >> n >> k;
		for (int j = 0; j < n - 1; j++)
		{
			int u, v;
			cin >> u >> v;
			a.push_back({u, v});
		}
		cout << i + 1 << endl;
	}
	return 0;
}
