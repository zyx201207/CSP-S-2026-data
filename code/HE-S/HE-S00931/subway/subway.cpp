#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair <int, int> pii;
const int N = 5e5 + 5;

int c, n, m, d, q;
int w[N], t;
vector <int> e[N], v[N];
int qu[N], di[N];
bool st[N];

signed main ()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int j = 1; j <= n; j++)
	{
		int k; cin >> k;
		for (int i = 1; i <= k; i++)
		{
			int a;
			cin >> a >> t;
			e[a].push_back(k);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j : e[i])
			for (int k : e[i])
			{
				if (j == k) continue;
				v[j].push_back(k);
			}
	}
	while (q--)
	{
		int S, T;
		cin >> S >> T;
		int ans = 1e18;
		for (int SS : e[S])
		for (int TT : e[T])
		{
			memset(st, 0, sizeof st);
			memset(di, 0, sizeof di);
			int hh = 1, tt = 0;
			qu[++tt] = SS;
			st[SS] = 1;
			di[SS] = 1;
			while (hh <= tt)
			{
				int u = qu[hh++];
				for (int i : v[u])
				{
					if (st[i]) continue;
					qu[++tt] = i;
					di[i] = di[u] + 1;
					st[i] = 1;
				}
			}
			ans = min(ans, di[TT] * t + w[S] + w[T]);
		}
		cout << ans << '\n';
	}
	return 0;
}
