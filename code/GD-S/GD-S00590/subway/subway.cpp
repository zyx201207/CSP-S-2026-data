#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

const int N = 1e3 + 5;

struct str
{
	int v, t;
};

int c, n, m, d, q, w[N], f[N][N];

void floyd()
{
	for(int k = 1; k <= m; k++)
	{
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	return;
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		vector<str> vec;
		for(int j = 1; j <= k; j++)
		{
			int v, t; 
			cin >> v >> t;
			vec.push_back({v, t});
		}
		for(int i = 0; i < k; i++)
		{
			for(int j = i + 1; j < k; j++)
			{
				int x = vec[i].v, y = vec[j].v;
				int t1 = vec[i].t, t2 = vec[j].t;
				f[x][y] = min(f[x][y], t1 + t2);
			}
		}
	}
	floyd();
	
	while(q--)
	{
		int x, y; cin >> x >> y;
		int ans = f[x][y] + w[x] + w[y];
		cout << ans << endl;
	}
	return 0;
}
