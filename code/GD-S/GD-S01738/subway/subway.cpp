#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],t[505][505],a[505][505],x,y,ans;
struct site
{
	int w,v;
};
vector<site> r[500005];
bool f[500005];
void dfs(int u,int v,int fa,int cnt)
{
	if(u == v)
	{
		ans = min(cnt,ans);
		return;
	}
	f[u] = 1;
	if (r[u].size() == 1)
	{
		return;
	}
	for (int i = 0;i < r[u].size();i++)
	{
		if (f[r[u][i].w] == 0 && r[u][i].w != fa)
		{
			dfs(r[u][i].w,v,u,cnt + r[u][i].v);
			f[r[u][i].w] = 0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
			r[a[i][j - 1]].push_back({a[i][j],t[i][j] + t[i][j - 1]});
			r[a[i][j]].push_back({a[i][j - 1],t[i][j] + t[i][j - 1]});
		}
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> x >> y;
		ans = 100000005;
		dfs(x,y,0,0);
		f[x] = 0;
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
