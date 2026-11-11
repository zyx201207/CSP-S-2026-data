#include<bits/stdc++.h>
using namespace std;

signed main()
{
	ifstream cin("migrate.in");
	ofstream cout("migrate.out");
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n, d;
		cin >> n >> d;
		vector<int>a(n + 5);
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		vector<vector<int>>s(n + 1, vector<int>(n + 1, numeric_limits<int>::max() / 2));
		//vector<vector<int>>cnt(n + 1, vector<int>(n + 1));
		//vector<vector<int>>picked(n + 1, vector<int>(n + 1));
		vector<vector<vector<int>>>kind(n + 5, vector<vector<int>>(n + 5, vector<int>(n + 5)));
		
		for (int i = 1; i <= n; ++i)
		{
			int u = i;
			int l = i;
			kind[i][i][0] = 1;
			s[i][i] = 0;
			for (int j = i; j <= n; ++j)
			{
				while (l <= n && a[l] - a[j] <= d)
				{
					++l;
				}
				if (l <= n) l--;
				for (int k = j + 1; k <= l; ++k) s[i][k] = min(s[i][k], s[i][j] + 1);
				for (int k = j + 1; k <= l; ++k)
				{
					kind[i][k][s[i][j] + 1] += kind[i][j][s[i][j]];
				}

			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				//cerr << kind[i][j][s[i][j]] << ' ';
				//cerr << s[i][j] << ' ';
				if (kind[i][j][s[i][j]] == 2) ans++;
			}
			//cerr << '\n';
		}
		cout << ans << '\n';
	}
}