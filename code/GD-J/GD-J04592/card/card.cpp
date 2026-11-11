#include<bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int n, m, a[maxn], vis[maxn], ans[maxn], lst[maxn], fst[maxn], ed[maxn];
bool isp[maxn];
deque<int> tmp;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
	}
	if (n <= 500 && m <= 200)
	{
		for (int i = 1; i <= n; ++ i)
		{
			//cout << i << '\n';
			for (int j = 0; j <= m; ++ j)
			{
				vis[j] = false;
				isp[j] = false;
			}
			for (int j = i; j <= n; ++ j)
			{
				//cout << j << '\n';
				if (vis[a[j]] != 0)
				{
					//cout << a[j] << '\n';
					while (!tmp.empty() && tmp.back() != a[j])
					{
						-- vis[tmp.back()];
						//cout << tmp.empty() << " " << "a" << tmp.back() << '\n';
						tmp.pop_back();
						//cout << tmp.empty() << " " << "a" << tmp.back() << '\n';
					}
					-- vis[tmp.back()];
					tmp.pop_back();
					tmp.push_back(a[j]);
					++ vis[a[j]];
				}
				else
				{
					++ vis[a[j]];
					tmp.push_back(a[j]);
				}
			}
			while (!tmp.empty())
			{
				if (isp[tmp.front()] == false)
				{
					++ ans[tmp.front()];
					isp[tmp.front()] = true;
				}
				tmp.pop_front();
			}
		}
		for (int i = 1; i <= m; ++ i)
		{
			cout << ans[i] << " ";
		}
		return 0;
	}
	for (int i = 1; i <= n; ++ i)
	{
		lst[a[i]] = i;
	}
	for (int i = 1; i <= m; ++ i)
	{
		cout << lst[i] << " ";
	}
	return 0;
}
