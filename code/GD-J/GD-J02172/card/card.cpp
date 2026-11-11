#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
bool vis[500050];
stack<int> st;
int ans[300010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		memset(vis, 0, sizeof(vis));
		for (int j = i;j <= n;j ++)
		{
			if (vis[a[j]] == 0)
			{
				vis[a[j]] = 1;
				st.push(a[j]);
			}
			else
			{
				while (!st.empty() && st.top() != a[j])
				{
					vis[st.top()] = 0;
					st.pop();
				}
			}
		}
		for (int j = 1;j <= m;j ++)
		{
			if (vis[j]) ans[j] ++;
		}
	}
	for (int i = 1;i <= m;i ++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
