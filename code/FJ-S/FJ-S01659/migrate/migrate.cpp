#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
int c, t, n, cnt, ed;
long long ans, d, a[2000010], dis[5000][5000];
vector<int> g[100010];
queue<int> q;
bitset<100010> vis;

void dfs(int u, int cost)
{
	if (u == ed)
	{
		cnt++;
		return;
	}
	if (cost == 0)
		return;
	for (int i = u + 1; i <= n; i++)
	{
		if (a[u] + d < a[i])
			break;
		dfs(i, cost - 1);
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 11 || c == 12) // µÈ²îÊýÁÐ 
	{
		while (t--){
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> a[i];
			long long dif = a[2] - a[1];
			int k = d / dif;
			if (k < 2)
			{
				cout << "0\n";
				continue;
			}
			k += k - 1;
			n -= k;
			cout << max(n, 0) << '\n';
		}
	}
	else
	{
		while (t--)
		{
			ans = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> a[i]; 
			memset(dis, 0x3f, sizeof dis);
			for (int i = n; i > 0; i--)
			{
				dis[i][i] = 0;
				for (int j = i - 1; j > 0; j--)
				{
					if (a[j] + d >= a[i])
						for (int k = i; k <= n; k++)
							dis[j][k] = min(dis[j][k], dis[i][k] + 1);
					if (a[j] + d < a[i])
						break;
				}
			}
			for (int l = 1; l <= n; l++)
				for (int r = l + 1; r <= n; r++)
				{
					cnt = 0;
					ed = r;
					dfs(l, dis[l][r]);
					if (cnt == 2)
						ans++;
				}
			cout << ans << '\n';
		}
	}
}

