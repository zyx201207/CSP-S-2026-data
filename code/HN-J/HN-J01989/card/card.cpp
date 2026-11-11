#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int n, m;
int a[N];
int id[N];

vector<int> cnt[N];
signed main () 
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		cnt[i].push_back(0);
		for (int j = 1; j <= m; j++) cnt[i].push_back(0);
	}
	cnt[n + 1].push_back(0);
	for (int i = 1; i <= m; i++) cnt[n + 1].push_back(0);
	for (int i = n; i >= 1; i--) 
	{
		if (!id[a[i]]) 
		{
			for (int j = 1; j <= m; j++) cnt[i][j] = cnt[i + 1][j];
			cnt[i][a[i]] ++;
			id[a[i]] = i;
		}
		else 
		{
			for (int j = 1; j <= m; j++) cnt[i][j] = cnt[id[a[i]] + 1][j];
			cnt[i][a[i]] ++;
		}
	}
	
	for (int i = 1; i <= m; i++) 
	{
		int ans = 0;
		for (int j = 1; j <= n; j++) ans += cnt[j][i];
		if (i < m)printf("%d ", ans);
		else printf("%d", ans);
	}
	
	return 0;
}
