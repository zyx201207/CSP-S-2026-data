#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
bool vis[200005];
bool bit[200005][35];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		
		int tmp = a[i], cur = 0;
		while (tmp)
		{
			cur++;
			if (tmp & 1) bit[i][cur] = true;
			tmp >>= 1; 
		}
	}
	
	memset(vis, true, sizeof(vis));
	int ans = 0, mul = (1 << 30);
	for (int b = 31; b >= 1; b--)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += (vis[i] && bit[i][b]);
		
		if (cnt >= m)
		{
			ans += mul;
			for (int i = 1; i <= n; i++) 
				if (vis[i] && !bit[i][b]) vis[i] = false;
		}
		
		mul >>= 1;
	}
	
	cout << ans << endl;
	return 0;
}
