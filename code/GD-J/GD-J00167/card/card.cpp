#include <iostream>
#include <set>
using namespace std;
int n, m;
int a[500005], b[500005], cnt[500005];
set<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// freopen("card.in", "r", stdin);
	// freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (s.find(a[j]) != s.end())
			{
				for (auto it = s.find(a[j]); it != s.end(); it++)
				{
					s.erase(it);
				}
			}
			s.insert(a[j]);
		}
		for (auto it = s.begin(); it != s.end(); it++)
		{
			cnt[*it]++;
		}
		s.clear();
	}
	for (int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
