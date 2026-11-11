#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2000010;
vector<int> son[N];
int d[N], f[N], dmax[N], cnt[N], maxd = 0;

void build(int r)
{
	d[r] = d[f[r]] + 1, cnt[r] = 1;
	maxd = max(maxd, d[r]);
	for (int i = 0; i < son[r].size(); i++)
	{
		if (son[r][i] == f[r]) continue;
		f[son[r][i]] = r;
		build(son[r][i]);
		cnt[r] += cnt[son[r][i]];
	}
}

int DFS1(int r, int k)
{
	dmax[r] = 1;
	int ans = 0;
	for (int i = 0; i < son[r].size(); i++)
	{
		if (son[r][i] == f[r]) continue;
		ans += DFS1(son[r][i], k);
		dmax[r] = max(dmax[son[r][i]] + 1, dmax[r]);
	}
	if (dmax[r] > k) ans++;
	return ans;
}

int DFS2(int r, int k)
{
	dmax[r] = 1;
	int ans = 0;
	for (int i = 0; i < son[r].size(); i++)
	{
		if (son[r][i] == f[r]) continue;
		ans += DFS2(son[r][i], k);
		dmax[r] = max(dmax[son[r][i]] + 1, dmax[r]);
	}
	if (dmax[r] > k) ans++, dmax[r] = 0;
	return ans;
}

int efans(int n, int k)
{
	int l = 0, r = maxd, mid, S;
	while (l < r)
	{
		mid = (l + r) >> 1;
		S = (DFS1(1, mid) + DFS2(1, mid) * 2) / 3;
		if (S > k) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, u, v, n, k;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) son[i].clear();
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			son[u].push_back(v);
			son[v].push_back(u);
		}
		d[0] = 0, f[1] = 0;
		build(1);
		if (maxd == n)
		{
			cout << (n - k + 3) / 4 << endl;
			continue;
		}
		cout << efans(n, k) << endl;
	}
	return 0;
}