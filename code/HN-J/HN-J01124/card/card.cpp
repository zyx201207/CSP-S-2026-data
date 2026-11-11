#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int cnt[N] , mp[N] , mp2[N];
int a[N]; 
bool vis[N];
signed main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 500)
	{
		for (int i = 1; i <= n; i++)
		{
			int tot = 0;
			for (int j = i; j <= n; j++)
			{
				if (vis[a[j]] != 0)
				{
					for (int k = mp2[a[j]]; k <= tot; k++) vis[mp[k]] = 0;
					tot -= (tot - mp2[a[j]] + 1);
				}
				mp[++tot] = a[j];
				mp2[a[j]] = tot;
				vis[a[j]] = 1;
			}
			for (int j = 1; j <= tot; j++) cnt[mp[j]]++;
			memset(vis , 0 , sizeof vis);
		}
		for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int tot = 0;
		for (int j = i; j <= n; j++)
		{
			if (vis[a[j]] != 0)
			{
				tot--;
				vis[a[j - 1]] = 0;
			}
			mp[++tot] = a[j];
			mp2[a[j]] = tot;
			vis[a[j]] = 1;
		}
		for (int j = 1; j <= tot; j++) cnt[mp[j]]++;
		memset(vis , 0 , sizeof vis);
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
}
