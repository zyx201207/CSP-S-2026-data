//GZ-J00103 张万嘉 贵阳市第十九中学
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
int ans[500010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		queue<int> q;
		map<int, int> k;
		for(int j = i; j <= n; j++)
		{
			if(k[a[j]] == k.size() + 1 || k[a[j]] == -1)
			{
				q.push(a[i]);
				k[a[j]] = j;
			}
			else
			{
				for(int z = k[a[j]] + 1; z < j; z++)
				{
					q.pop();
					k[a[z]] = -1;
				}
			}
		}
		while(!q.front())
		{
			ans[q.back()]++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
