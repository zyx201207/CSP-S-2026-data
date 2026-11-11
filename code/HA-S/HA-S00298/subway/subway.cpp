#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[20001], k, a[20001], t[20001], x, y, f[20001];
vector<pair<int, int> > g[20001];
bool v[20001];
priority_queue<pair<int, int> > p;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		cin >> a[1] >> t[1];
		for (int j = 2; j <= k; j++)
		{
			cin >> a[i] >> t[i];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		cout << a[x] + t[x];
	}
	return 0;
}
