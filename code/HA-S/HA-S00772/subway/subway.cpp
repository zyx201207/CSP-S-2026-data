#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int res = 0;
	char ch = getchar();
	bool tag = 0;
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-')
	{
		tag = 1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		res = (res << 3) + (res << 1) + ch - '0';
		ch = getchar();
	}
	if (tag) return -res;
	return res;
}
void write(long long x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	if (x >= 10) write(x/10);
	putchar(x%10+'0');
}
const int N = 505;
const int M = 500005;
int op,n,m,d,q,w[M],num,u,v,siz[M];
long long dis[N][N],ans;
vector<int> h[M],t[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	op = read(), n = read(), m = read();
	d = read(), q = read();
	for (int i=1;i<=m;i++) w[i] = read();
	memset(dis,-1,sizeof(dis));
	for (int i=1;i<=n;i++)
	{
		num = read();
		dis[i][i] = 0;
		for (int j=1;j<=num;j++)
		{
			u = read(), v = read();
			for (int k=0;k<siz[u];k++)
			{
				dis[i][h[u][k]] = v + t[u][k];
				dis[h[u][k]][i] = v + t[u][k];
			}
			h[u].push_back(i);
			t[u].push_back(v);
			siz[u]++;
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			if (dis[i][k] == -1) continue;
			for (int j=1;j<=n;j++)
			{
				if (dis[k][j] == -1) continue;
				if (dis[i][j] == -1) dis[i][j] = dis[i][k]+dis[k][j];
				else dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while (q--)
	{
		u = read(), v = read();
		ans = -1;
		for (int i=0;i<siz[u];i++)
		{
			for (int j=0;j<siz[v];j++)
			{
				int x = h[u][i], y = h[v][j];
				if (dis[x][y] == -1) continue;
				if (ans == -1) ans = dis[x][y] + t[u][i] + t[v][j];
				else ans = min(ans,dis[x][y]+t[u][i]+t[v][j]);
			}
		}
		ans += w[u] + w[v];
		write(ans);
		puts("");
	}
	return 0;
}
