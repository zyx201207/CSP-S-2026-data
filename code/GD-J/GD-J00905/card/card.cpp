#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans[300005], vis[300005];
int lst[500005], ll[300005], ll1[300005];
struct nd
{
	int num, cnt;
}l[50005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int ccnt = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i > 1 && a[i] != a[i - 1])
		{
			ccnt++;
		}
	}
	if(n > 5000 && ccnt < 5000)
	{
		int cc = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] != a[i - 1])
			{
				cc++;
				l[cc].num = a[i];
			}
			l[cc].cnt++;
		}
		n = cc;
		for(int i = n; i >= 1; i--)
		{
			lst[i] = ll[l[i].num];
			ll[l[i].num] = i;
		}
		for(int i = 1; i <= n; i++)
		{
			int id = i;
			while(id <= n)
			{
				if(lst[id] != 0)
				{
					id = lst[id];
				}
				else
				{
					if(vis[l[id].num] != i)
					{
						ans[l[id].num] += l[i].cnt;
						vis[l[id].num] = i;
					}
					id++;
				}
			}
		}
		for(int i = 1; i <= m; i++)
		{
			cout << ans[i] << ' ';
		}
		return 0;
	}
	for(int i = n; i >= 1; i--)
	{
		lst[i] = ll[a[i]];
		ll[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		int id = i;
		while(id <= n)
		{
			if(lst[id] != 0)
			{
				id = lst[id] - 1;
			}
			else
			{
				if(vis[a[id]] != i)
				{
					ans[a[id]]++;
					vis[a[id]] = i;
				}
			}
			id++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
