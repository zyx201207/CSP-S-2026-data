#include <bits/stdc++.h>
using namespace std;
int c,t,u,v;
int n;
long long d,a[2000005],minn,ansnum,bigans;
bool vis[305];
void dfs(int x,int y)
{
	if (x <= y)
	{
		vis[x] = 1;
		dfs(x + 1,y);
		vis[x] = 0;
		dfs(x + 1,y);
	}
	if (x == y + 1)
	{
		if (vis[u] == 0 || vis[v] == 0)
			return;
		long long last = a[u],cnt = 1;
		for (int i = u + 1;i <= v;i++)
		{
			if (vis[i] && a[i] - last <= d)
			{
				cnt++;
				last = a[i];
			}
			else if (vis[i] && a[i] - last > d)
			{
				return;
			}
		}
		if (cnt < minn)
		{
			minn = cnt,ansnum = 1;
		}
		else if (cnt == minn)
		{
			ansnum++;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		bigans = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if (n <= 9)
		{
			for (int i = 1;i <= n;i++)
			{
				for (int j = i + 1;j <= n;j++)
				{
					u = i,v = j;
					minn = 9999999,ansnum = 0;
					memset(vis,0,sizeof(vis));
					dfs(i,j);
					if (ansnum == 2)
					{
						bigans++;
						//cout << i << " " << j << endl;
					}
				}
			}
			cout << bigans << endl;
		}
		else
		{
			long long p = a[2] - a[1];
			long long ge = d / p;
			if (ge == 0 || ge == 1)
			{
				cout << 0 << endl;
				continue;
			}
			long long res = 0;
			//cout << p << " " << ge << endl;
			for (int i = 1;i + ge + (ge - 1) <= n;i++)
			{
				res += 1;
			}
			cout << res << endl; 
		}
	}
}
