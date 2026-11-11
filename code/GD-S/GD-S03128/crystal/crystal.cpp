#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> v;

signed main()
{
#ifndef DEBUG
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
 	int ans = 0;
 	for (int i = 0; i < n; i++)
	{
		int cur = 0;
		for (int j = i + 1; j < n; j++)
		{
			cur += (v[j] - v[j - 1]) * (j - i);
			//~ cerr << j << cur << endl;
			if (cur > m || j == n - 1)
			{
				ans = max(ans, j - i);
				//~ cerr << i << " " << j << " " << cur << endl;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
