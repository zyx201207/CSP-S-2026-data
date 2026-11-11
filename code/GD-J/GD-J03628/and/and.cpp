#include <bits/stdc++.h>
using namespace std;
int n, m, ans, maxl, a[200005];
string q[200005];
vector<int> g;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		int p = a[i];
		string s;
		while (p > 0)
		{
			s += ((p % 2) + '0');
			p /= 2;
		}
		if (i == 1)
		{
			maxl = s.size();
		}
		else
		{
			if (s.size() < maxl)
			{
				for (int j = 1; j <= maxl - s.size(); j++)
				{
					q[i] += "0";
				}
			}
		}
		for (int j = s.size() - 1; j >= 0; j--)
		{
			q[i] += s[j];
		}
	}
	for (int i = 0; i <= q[1].size() - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (q[j][i] == '1')
			{
				g.push_back(a[j]);
			}
		}
		sort(g.begin(), g.end());
		reverse(g.begin(), g.end());
		if (g.size() >= m)
		{
			ans = g[0];
			for (int i = 0; i < m; i++)
			{
				ans &= g[i];
			}
			break;
		}
		g.clear();
	}
	cout << ans;
    return 0;
}
