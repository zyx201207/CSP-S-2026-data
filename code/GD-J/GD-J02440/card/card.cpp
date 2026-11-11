#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], tb[500005], ans[200005], ptr;
map<int, int> mp;
unordered_set<int> ust;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for (int i=1; i<=n; i++)
	{
		ptr=0;
		for (int j=i; j<=n; j++)
		{
			if (mp.find(a[j])==mp.end())
			{
				tb[++ptr]=a[j];
				mp[a[j]]=ptr;
			}
			else
			{
				ptr=mp[a[j]];
				tb[ptr]=a[j];
				mp[a[j]]=ptr;
				ust.clear();
				for (auto a : mp)
				{
					if (a.second>ptr)
					{
						ust.insert(a.first);
					}
				}
				for (auto a : ust)
				{
					mp.erase(a);
				}
			}
		}
		for (int j=1; j<=m; j++)
		{
			if (mp.find(j)!=mp.end())
			{
				ans[j]++;
			}
		}
		mp.clear();
	}
	for (int i=1; i<=m; i++)
	{
		cout << ans[i] << ' ';
	}
	//cout << '\n' << system("fc card.out card.ans") << '\n';
	return 0;
}
