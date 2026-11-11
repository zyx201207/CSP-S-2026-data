#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, m, a[N], b[N];
map<int, int> ans, mp;
vector<int> v[N];

int main ()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--)
	{
		if (mp[a[i]] != 0)
		{
			int cnt = v[a[i]].back();
			for (int j = i + 1; j <= cnt; j++)
			{
				if (!b[j])
				{
					mp[a[j]]--; 
					b[j] = 1;
					v[a[j]].pop_back();
				}
			}
		}
		mp[a[i]]++;
		v[a[i]].push_back(i);
		for (auto j : mp)
		{
			if (j.second)
			{
				ans[j.first]++;
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << "\n";
	return 0;
}
