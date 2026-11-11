#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], ans[N], q[N], las[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i; i--) if (!las[a[i]]) las[a[i]] = i;
	for (int T = 1; T <= n; T++)
	{
		int t = 0;
		for (int i = T; i <= n; i++)
		{
			q[++t] = a[i];
			if (las[a[i]] > i) i = las[a[i]];
		}
		for (int i = 1; i <= t; i++) ans[q[i]]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
	return 0;
}
