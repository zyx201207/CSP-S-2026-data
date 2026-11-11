#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], ans[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 5000)
	{
		for(int i = 1; i <= n; i++)
		{
			vector<int> v, vis(m + 1, 0);
			for(int j = i; j <= n; j++)
			{
				if(!vis[a[j]])
				{
					vis[a[j]] = 1;
					ans[a[j]]++;
					v.push_back(a[j]);
				}
				else
				{
					while(v.back() != a[j])
					{
						vis[v.back()] = 0;
						ans[v.back()]--;
						v.pop_back();
					}
				}
			}
		}
		for(int i = 1; i <= m; i++) 
			cout << ans[i] << " ";
	}
	else
	{
		for(int i = 1; i <= m; i++) ans[i] = n;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] != a[i - 1])
			{
				ans[a[i - 1]] -= n - i + 1;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			cout << ans[i] << " ";
		}
	}
	return 0;
}

