#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int lst[300005];
int sze[500005];
int ans[300005];
vector<int> g[500005];
void dfs(int x)
{
	sze[x] = 1;
	for(auto it:g[x])
	{
		dfs(it);
		sze[x] += sze[it];
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		lst[a[i]] = i;
	}
//	for(int i = 1;i <= n;i++)
//	{
//		int pos = i;
//		while(pos <= n)
//		{
//			ans[a[pos]]++;
//			pos = lst[a[pos]]+1;
//		}
//	}
	for(int i = 1;i <= n;i++)
	{
		g[lst[a[i]]+1].push_back(i);
	}
	dfs(n+1);
	for(int i = 1;i <= n;i++)
	{
		ans[a[i]] += sze[i];
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
/*
3 1
1
2 1
1
3 1
2 1
3 1
1
2 1
1

1 2 1 3
1 0 1 1

3 1 2 1 3 2 3 1 2 1
0 1 2 1 0 5 0 6 8 0
*/
