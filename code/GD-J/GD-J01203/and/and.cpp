#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
bool vis[N];

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	for(int i = 30; i >= 0; i--)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			if(vis[j]) continue;
			cnt += ((a[j] >> i) & 1);
		}
		if(cnt < m) continue;
		for(int j = 1; j <= n; j++)
		{
			if(vis[j]) continue;
			if(((a[j] >> i) & 1) == 0) vis[j] = 1;
		}
		ans += (1 << i);
	}
	printf("%d", ans);
	return 0;
}
