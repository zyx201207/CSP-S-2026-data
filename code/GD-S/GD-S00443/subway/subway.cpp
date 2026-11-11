#include <bits/stdc++.h>
#define int long long
using namespace std;
int c , n , m , d , q , w[500005] , a[505][50005] , t[505][50005] , k , ans[500005];
struct node 
{
	int v , l;
};
vector <node> g[500005];
void bfs (int x , int y)
{
	queue <node> q;
	q.push ({x , y});
	ans[x] = w[x] + t[y][x];
	while (!q.empty ())
	{
		node u = q.front ();
		q.pop ();
		for (auto i : g[u.v])
		{
			ans[i.v] = min (ans[i.v] , ans[u.v] + t[i.l][i.v]);
			q.push (i);
		}
	}
}
signed main ()
{

	freopen ("subway.in" , "r" , stdin);
	freopen ("subway.out" , "w" , stdout);
	ios::sync_with_stdio (NULL);
	cin.tie (0);
	cout.tie (0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		cin >> k;
		for (int j = 1;j <= k;j ++)
		{
			cin >> a[i][j] >> t[i][a[i][j]];
			g[a[i][j - 1]].push_back ({a[i][j] , i});
		}
	}
	for (int i = 1;i <= q;i ++)
	{
		int x , y;
		cin >> x >> y;
		memset (ans , 127 , sizeof ans);
		for (int j = 0;j < g[x].size ();j ++)
		{
			bfs (x , g[x][j].l);
		}
		cout << ans[y] + w[y] << endl;
	}
	return 0;
}

