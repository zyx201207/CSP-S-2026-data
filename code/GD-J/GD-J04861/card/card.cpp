#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], nxt[N], vis[N], pos[N], hp[N], cnt[N], ans[N];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (pos[a[i]]) nxt[pos[a[i]]] = i;
		pos[a[i]] = i;
		vis[a[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) // ´Ó i ¿ªÊ¼ 
	{
		for (int j = 1; j <= m; ++j) cnt[j] = 0;
		for (int j = i; j <= n; )
		{
			while (nxt[j]) j = nxt[j];
			++cnt[a[j]];
			++j;
		}
		for (int j = 1; j <= m; ++j) ans[j] += (cnt[j] != 0);
	}
	for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
	return 0;
}

//4 3
//1 2 1 3

//10 3
//3 1 2 1 3 2 3 1 2 1
