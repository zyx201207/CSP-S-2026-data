#include <bits/stdc++.h>

using namespace std;

int n, m;
int pa[500055];
int to[300055], nexto[300055], sum[300055];

void paiju(int x)
{
	for (int j = x; j <= n; j++)
	{
		if (nexto[pa[j]] == 0)
		{
			nexto[pa[j]] = nexto[pa[j - 1]] + 1;
		}
		if (!to[pa[j]])
		{
			to[pa[j]] = 1;
		}
		else
		{
			//cout << nexto[pa[j]] << '\n';
			int huisu = nexto[pa[j]];
			for (int k = nexto[pa[j]]; k <= n; k++)
			{
				to[nexto[pa[k]]] = 0;
				nexto[pa[k]] = 0;
			}
			to[pa[j]] = 1;
			nexto[pa[j]] = huisu;
		}
	}
	for (int j = x; j <= n; j++)
	{
		if (to[pa[j]])
		{
			sum[pa[j]]++;
			to[pa[j]] = 0;
		}
	}
}

int main()
{
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> pa[i];
	}	
	
	for (int i = 1; i <= n; i++)
	{
		memset(to, 0, sizeof(to));
		memset(nexto, 0, sizeof(nexto));
		paiju(i);
	}
	for(int k = 1; k <= m; k++)
	{
		cout << sum[k] << ' ';
	}
	return 0;
}
