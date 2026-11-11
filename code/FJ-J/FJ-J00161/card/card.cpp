#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], ans[N], pre[N], lst[N];
bool vis[N];

int main()
{	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);	
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for (int t = 1; t <= n; t ++)
	{
		memset(vis, 0, sizeof vis);
		for (int i = t; i <= n; i ++)
		{
			int j = pre[i];
			while (j >= t && vis[j]) j = pre[j]; 
			
			if (j >= t)
				for (; j < i; j ++)
					vis[j] = true;
		}	
				
		for (int k = t; k <= n; k ++) 
			if (!vis[k]) 
				ans[a[k]] ++;
	}
	for (int i = 1; i <= m; i ++) cout << ans[i] << " ";
	cout << "\n";
	return 0;
} 
