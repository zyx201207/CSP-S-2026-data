#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e6 + 5;

int cid, t, n, k;
array<vector<int>, N> G;

array<int, N> mlen, outs;
int ki, kj;

inline void dfs1(int u, int fa)
{
	mlen[u] = 0;
	for (auto &j : G[u])
	{
		if (min(u, j) == ki && max(u, j) == kj) continue;
		if (j != fa)
		{
			dfs1(j, u);
			mlen[u] = max(mlen[u], mlen[j] + 1);
		}
	}
}

inline void dfs2(int u, int fa)
{
	if (fa == -1) outs[u] = (int)-1e9;
	int maxn = -1, secmax = -1;
	for (auto &j : G[u])
	{
		if (min(u, j) == ki && max(u, j) == kj) continue;
		if (j == fa) continue;
		if (mlen[j] >= maxn) secmax = maxn, maxn = mlen[j];
		else if (mlen[j] > secmax) secmax = mlen[j];
	}
	for (auto &j : G[u])
	{
		if (min(u, j) == ki && max(u, j) == kj) continue;
		if (j == fa) continue;
		outs[j] = max(outs[u] + 1, (maxn == mlen[j] ? secmax : maxn) + 1);
		outs[j] = max(outs[j], 0);
		dfs2(j, u);
	}
}

int tw;

inline int dfs3(int u, int fa)
{
	//cerr << "WOW: " << u << " " << mlen[u] << "\n";
	int cnt = 0, sum = 0, jj = -1;
	for (auto &j : G[u])
	{
		if (min(u, j) == ki && max(u, j) == kj) continue;
		if (j == fa) continue;
		int x = dfs3(j, u);
		cnt += (x > 0);
		if (x > 0) jj = j;
		sum += x;
	}
	if (cnt > 1)
	{
		return (++sum);
	}
	if (cnt == 0)
	{
		if (mlen[u] + 1 > tw) return sum + 1;
	}
	else
	{
		if (outs[jj] + 1 > tw) return sum + 1;
	}
	return sum;
}

inline bool chk(int w)
{
	tw = w;
	for (int i = 1; i <= n; i++)
	{
		for (auto &j : G[i])
		{
			if (j > i)
			{
				ki = min(i, j), kj = max(i, j);
				dfs1(i, -1);
				dfs2(i, -1); 
				dfs1(j, -1);
				dfs2(j, -1);
				//cerr << "??: " << i << " " << j << " " << dfs3(i, -1) << " " << dfs3(j, -1) << " " << outs[7] << "\n";
				if (max(1, dfs3(i, -1)) + max(1, dfs3(j, -1)) <= k) return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> cid >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u].emplace_back(v), G[v].emplace_back(u);
		}
		int l = 1, r = n, ans = (int)1e9;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (chk(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
