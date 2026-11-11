#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 2e6 + 5;

int cid, t;
int n;
ll d, ans;
array<ll, N> x;
array<int, N> nxt, val, son;
array<ll, N> sum, sum2, nv;
array<vector<int>, N> G;

inline void dfs(int u, int fa, int pos)
{
	// calc ans
	ll rans = ans;
	if (pos != -1)
	{
		if (val[pos] == 1)
		{
			// (pos,nxt[pos])
			bool ok = 1;
			if (pos - 1 > son[pos])
			{
				if (son[pos] != u && son[pos] - 1 > son[son[pos]])
				{
					if (x[pos - 1] - x[son[pos] - 1] <= d) ok = 0;
				}
			}
			if (ok)
			{
				ans += sum[nxt[pos]];
				int l = pos + 1, r = nxt[pos], gg = -1;
				while (l <= r)
				{
					int mid = l + r >> 1;
					if (pos - 2 > son[pos] && x[mid] - x[pos - 2] <= d) l = mid + 1;
					else gg = mid, r = mid - 1;
				}
				if (gg != -1) ans += nxt[pos] - gg + 1;
			}
		}
		//cerr << "???: " << u << " " << pos << " " << ans << "\n";
		//if (u == 1) cerr << "!!!!: " << sum2[fa] << " " << sum2[pos] << "\n";
		ans += sum2[fa] - sum2[pos];
	}
	else if (fa != -1) ans += sum2[fa];
	for (auto &j : G[u])
	{
		// trans to j
		son[u] = j;
		val[u] = 0;
		sum[u] = sum2[u] = nv[u] = 0;
		ll rfa = (fa == -1 ? 0 : sum2[fa]);
		if (fa != -1)
		{
			for (int d : { 1, 2 })
			{
				if (u - d > j && x[fa] - x[u - d] <= ::d) val[u]++;
			}
			sum[u] = sum[fa];
			int l = u + 1, r = fa, gg = -1;
			while (l <= r)
			{
				int mid = l + r >> 1;
				if (u - 1 >= j && x[mid] - x[u - 1] <= ::d) l = mid + 1;
				else gg = mid, r = mid - 1;
			}
			if (gg != -1) sum[u] += (fa - gg + 1);
			sum2[u] = sum2[fa];
			int lim = (gg == -1 ? fa : gg - 1);
			l = u + 1, r = lim, gg = -1;
			while (l <= r)
			{
				int mid = l + r >> 1;
				if (u - 2 >= j && x[mid] - x[u - 2] <= ::d) l = mid + 1;
				else gg = mid, r = mid - 1;
			}
			if (gg != -1)
			{
				nv[u] = lim - gg + 1;
				sum2[u] += (lim - gg + 1);
			}
			if (fa - 1 > u && u - 1 > j && x[fa - 1] - x[u - 1] <= ::d)
			{
				sum2[u] -= nv[fa];
				sum2[fa] -= nv[fa];
			}
			if (val[u] >= 1) sum[u] -= sum[fa];
		}
		dfs(j, u, (val[u] >= 1 ? u : pos));
		if (fa != -1) sum2[fa] = rfa;
	}
}

inline void solve(int l, int r)
{
	for (int i = l; i <= r; i++) G[i].clear(), sum[i] = sum2[i] = son[i] = val[i] = 0;
	int j = l;
	for (int i = l; i <= r; i++)
	{
		while (j <= r && x[j] - x[i] <= d) j++;
		nxt[i] = j - 1;
		if (i < r) G[nxt[i]].emplace_back(i);
		//cerr << i << " " << nxt[i] << "\n";
	}
	dfs(r, -1, -1);
	//cerr << "????: " << l << " " << r << " " << ans << "\n";
	/*for (int i = l; i <= r; i++)
	{
		for (int j = i + 1; j <= r; j++)
		{
			vector<int> pos;
			int xx = i;
			while (true)
			{
				pos.emplace_back(xx);
				if (xx == j) break;
				xx = min(j, nxt[xx]);
			}
			int ok = 0;
			if (pos.size() == 2)
			{
				continue;
			}
			int pss = -1;
			for (int c = 1; c + 1 < pos.size(); c++)
			{
				int pl = pos[c - 1], pr = pos[c + 1], now = pos[c];
				if (now - 1 > pl && x[pr] - x[now - 1] <= d) ok++, pss = c;
				if (now - 2 > pl && x[pr] - x[now - 2] <= d) ok++, pss = c;
			}
			if (ok == 0 || ok >= 2) continue;
			if (pss > 1 && pos[pss - 1] - 1 > pos[pss - 2] && x[pos[pss] - 1] - x[pos[pss - 1] - 1] <= d) continue;
			ans++;
		}
	}*/
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> cid >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		int lst = 1;
		for (int i = 1; i <= n; i++)
		{
			if (i == n || x[i + 1] - x[i] > d)
			{
				solve(lst, i);
				lst = i + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
