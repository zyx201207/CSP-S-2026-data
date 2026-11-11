#include <bits/stdc++.h>
using namespace std;
long long mymin(long long a, long long b)
{
	return (a<b ? a : b);
}
long long f[501][501];
int w[500001];
int id[500001][21], t[500001][21], siz[500001], a[500001];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d", &c);
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &d);
	scanf("%d", &q);
	for(int i = 1; i<=m; i++)
	{
		scanf("%d", &a[i]);
	}
	int x, y, z;
	for(int i = 1; i<=n; i++)
	{
		scanf("%d", &x);
		while(x--)
		{
			scanf("%d", &y);
			scanf("%d", &z);
			siz[y]++;
			id[y][siz[y]]=i, t[y][siz[y]]=z;
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = i+1; j<=n; j++)
		{
			f[i][j]=f[j][i]=1e18;
		}
	}
	for(int i = 1; i<=m; i++)
	{
		for(int j = 1; j<=siz[i]; j++)
		{
			for(int k = j+1; k<=siz[i]; k++)
			{
				f[id[i][j]][id[i][k]]=mymin(f[id[i][j]][id[i][k]], t[i][j]+t[i][k]);
				f[id[i][k]][id[i][j]]=f[id[i][j]][id[i][k]];
			}
		}
	}
	for(int k = 1; k<=n; k++)
	{
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				f[i][j]=mymin(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		scanf("%d", &y);
		scanf("%d", &z);
		long long minn = 1e18;
		for(int i = 1; i<=siz[y]; i++)
		{
			for(int j = 1; j<=siz[z]; j++)
			{
				minn=mymin(minn, f[id[y][i]][id[z][j]]+t[y][i]+t[z][j]);
			}
		}
		cout << minn+a[y]+a[z] << endl;
	}
	return 0;
}
