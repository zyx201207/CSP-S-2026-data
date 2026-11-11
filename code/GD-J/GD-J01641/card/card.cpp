#include <bits/stdc++.h>
using namespace std;

int a[100005];
int s[100005];
int num[100005];
int vis[100005];

signed main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		int sum = 0;
		for(int j = i; j <= n; j++)
		{
			if(!vis[a[j]])
			{
				num[++sum] = a[j];
				vis[a[j]] = j - i + 1;
			}
			else
			{
				for(int k = vis[a[j]] + 1; k <= sum; k++)
				{
					num[k] = 0;
				}
				num[vis[a[j]]] = a[j];
				sum = vis[a[j]];
			}
		}
		for(int j = 1; j <= sum; j++)
		{
			s[num[j]]++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << s[i] << ' ';
	}
	return 0; 
}
