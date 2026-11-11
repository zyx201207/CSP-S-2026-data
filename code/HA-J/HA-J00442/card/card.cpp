#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001];
stack<int> s;
map<int, int> mp, ans;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		while (s.size()) s.pop();
		mp.clear();
		for (int j = i; j <= n; j++)
		{
			if (mp[a[j]])
			{
				while (s.top() != a[j])
				{
					mp[s.top()]--;
					ans[s.top()]--;
					s.pop();
				}
			}
			else
			{
				s.push(a[j]);
				mp[a[j]]++;
				ans[a[j]]++;
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
