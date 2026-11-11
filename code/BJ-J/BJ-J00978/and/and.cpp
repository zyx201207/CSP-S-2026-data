#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int x[N], w[100];
vector<int> g[100];
void clac(int x)
{
	int cnt = 1, cs = x;
	while (x)
	{
		if (x % 2)
		{
			w[cnt]++;
			g[cnt].push_back(cs);
			//cout << x << " " << cnt << ' ' << w[cnt] << endl;
		}
		x /= 2;
		cnt++;
	}
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> x[i];
		clac(x[i]);
		//cout << ejz[i] << endl;
	}
	int mb = 0;
	for (int i = 100;i >= 1;i--)
	{
		//cout << w[i] << ' ' << i << endl;
		if (w[i] >= k)
		{
			mb = i;
			break;
		}
	}
	sort(g[mb].begin(),g[mb].end(), greater<int>());
	int ans, cnt = 0;
	bool f = 0;
	for (auto p : g[mb])
	{
		cnt++;
		if (!f) ans = p, f = 1;
		else ans &= p;
		if (cnt == k) break;
	}
	cout << ans << "\n";
	return 0;
}

