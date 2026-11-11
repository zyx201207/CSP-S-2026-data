#include <iostream>
#include <algorithm>
using namespace std;

struct station
{
	int w, t[505];
};
struct station stations[500005];
int lines[505][505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> stations[i].w;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
			lines[i][j] = 1e9;
	}
	for (int i = 1; i <= m; i++)
	{
		int lcnt;
		cin >> lcnt;
		for (int j = 1; j <= lcnt; j++)
		{
			cin >> stations[j].t[i];
			for (int k = 1; k <= m; k++)
			{
				if (stations[i].t[k])
				{
					lines[i][k] = min(stations[i].t[k] + stations[i].t[j], lines[i][k]);
					lines[k][i] = min(stations[i].t[k] + stations[i].t[j], lines[k][i]);
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (j == k)
				{
					lines[j][k] = 0;
					lines[k][j] = 0;
				}
				else
				{
					int m = lines[i][j] + lines[j][k];
					lines[j][k] = min(lines[j][k], m);
					lines[k][j] = min(lines[k][j], m);
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << lines[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= q; i++)
	{
		int a, b, kk = 1e9, si, sj;
		cin >> a >> b;
		for (int ii = 1; ii <= m; ii++)
		{
			if (stations[a].t[ii] && stations[b].t[ii])
			{
				kk = 0;
				break;
			}
		}
		for (int ii = 1; ii <= m; ii++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (stations[a].t[ii] && stations[b].t[j])
				{
					kk = min(kk, min(lines[ii][j], lines[j][ii]));
					if (kk == min(lines[ii][j], lines[j][ii]))
					{
						si = ii;
						sj = j;
					}
					cout << kk << endl;
				}
			}
		}
		cout << stations[a].w + stations[b].w + stations[a].t[si] + stations[b].t[sj] + kk << endl;
	}
	return 0;
}
