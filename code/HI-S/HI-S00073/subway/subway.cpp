#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

static int c, n, m, d, q;
static vector<int> w;
static vector<vector<pair<int, int>>> a;

int main(void)
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++)
	{
		int wi;
		cin >> wi;
		w.push_back(wi); 
	}
	for (int i = 0; i < n; i++)
	{
		vector<pair<int, int>> ai;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int a, t;
			cin >> a >> t;
			ai.push_back({a, t});
		}
		a.push_back(ai); 
	}
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		int ans = INT_MAX;
		for (int j = 0; j < n; j++)
			for (int l = 0; l < (int)a[j].size() - 1; l++)
				for (int o = l + 1; o < (int)a[j].size(); o++)
					if (a[j][l].first == x && a[j][o].first == y)
						ans = min(ans, w[a[j][l].first - 1] + a[j][l].second + a[j][o].second + w[a[j][o].first - 1]);
		cout << ans << endl;
	}
	return 0;
}
