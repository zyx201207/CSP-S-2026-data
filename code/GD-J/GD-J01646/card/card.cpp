#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005], dict[300005];
bool vis[3005], vis2[100005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	if (n >= 500)
	{
		for (int t = 1; t <= n; t++)
		{
			memset(vis, false, sizeof(vis));
			for (int i = t; i <= n; i++)
			{
				int lst = 0;
				for (int j = t; j < i; j++)
				{
					if (a[i] == a[j] && !vis[j])
					{
						lst = j;
						break;
					}
				}
				
				if (!lst) continue;
				
				for (int j = lst + 1; j <= i; j++) vis[j] = true;
			} 
			
			for (int i = t; i <= n; i++) 
				if (!vis[i]) dict[ a[i] ]++;
		}
	}
	else
	{
		for (int i = n; i >= 1; i--)
		{
			if (!vis2[ a[i] ])
			{
				dict[ a[i] ] += i;
				vis2[ a[i] ] = true;
			}
		}
	}
	
	for (int i = 1; i <= m; i++) cout << dict[i] << " ";
	cout << endl; 
	return 0;
}

