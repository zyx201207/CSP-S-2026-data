#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], vis[N], ans[N];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) vis[a[i]] = i;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			j = vis[a[j]];
			ans[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
