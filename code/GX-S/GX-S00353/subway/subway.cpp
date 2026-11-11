#include<algorithm>
#include<iostream>
#include<cstring>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<list>
using namespace std;
struct lp
{
	int s;
	int way[21][2];
}xx[500001];
long long a[501][501];
long long stat[500001];
inline int read ()
{
	int x = 0, f = 1;
	char c = getchar ();
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			f = -1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar ();
	}
	return x * f;
}
int main ()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	int n = read ();
	n = read ();
	int m = read ();
	int k = read ();
	k = read ();
	for (int i = 1; i <= m; i++)
	{
		stat[i] = read ();
	}
	for (int i = 1; i <= n; i++)
	{
		int x = read ();
		for (int j = 1; j <= x; j++)
		{
			int ax = read (), tx = read ();
			xx[ax].way[++xx[ax].s][0] = i;
			xx[ax].way[xx[ax].s][1] = tx;
		}
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = 514514514;
			a[i][j] *= 5140;
		}
		a[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < xx[i].s; j++)
		{
			for (int kk = j + 1; kk <= xx[i].s; kk++)
			{
				long long x = xx[i].way[j][1], yy = xx[i].way[kk][1];
				a[xx[i].way[j][0]][xx[i].way[kk][0]] = min (x + yy, a[xx[i].way[j][0]][xx[i].way[kk][0]]);
				a[xx[i].way[kk][0]][xx[i].way[j][0]] = a[xx[i].way[j][0]][xx[i].way[kk][0]];
			}
		}
	}
	for (int kk = 1; kk <= n; kk++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (kk != i)
			{
				for (int j = 1; j <= n; j++)
				{
					if (kk != j && i != j)
					{
						if (a[i][kk] + a[kk][j] < a[i][j])
						{
							a[i][j] = a[i][kk] + a[kk][j];
							a[j][i] = a[i][j];
						}
					}
				}
			}
		}
	}
	for (int kk = 1; kk <= k; kk++)
	{
		int x = read (), y = read ();
		long long minn = 514514514;
		minn *= 5140;
		for (int i = 1; i <= xx[x].s; i++)
		{
			for (int j = 1; j <= xx[y].s; j++)
			{
				minn = min (minn, a[xx[x].way[i][0]][xx[y].way[j][0]] + xx[x].way[i][1] + xx[y].way[j][1]);
			}
		}
		cout << minn + stat[x] + stat[y] << endl;
	}
	
	return 0;
}

