#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define int long long
#define endl '\n'

const int N = 5e3 + 10,INF = 1e17;
int cid,n,t,d,a[N],f[N][N],nxt[N],pre[N],sum[N],ender,cnter,resp;

inline int get(int x)
{
	if (x > ender) return INF;
	if (x == ender) return 0;
	int res = INF;
	for(int j = x + 1;j <= n;j ++)
	{
		if (a[j] - a[x] > d) break;
		res = min(res,get(j));
	}
	return res + 1;
}

inline void dfs(int x,int dp)
{
	if (x > ender) return ;
	if (x == ender)
	{
		cnter += (d == resp);
		return ;
	}
	for(int j = x + 1;j <= n;j ++)
	{
		if (a[j] - a[x] > d) break;
		dfs(j,dp + 1);
	}
}

inline void subtask1()
{
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = i + 1;j <= n;j ++)
		{
			ender = j;
			if (i == 1 && j == 4)
				i ++,i --;
			resp = get(i);
			cnter = 0;
//			cout << i << ' ' << j << ' ' << resp << endl;
			dfs(i,0);
			if (cnter == 2) ans ++;
		}
	cout << ans << endl;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> cid >> t;
	while (t --)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i ++) cin >> a[i],sum[i] = sum[i - 1] + a[i];
//		if (cid >= 1 && cid <= 2)
//		{
//			subtask1();
//			continue;
//		}
		for(int i = 1;i <= n + 1;i ++)
			for(int j = 1;j <= n + 1;j ++)
				f[i][j] = INF;
		for(int i = 1;i <= n;i ++)
		{
			int l = 1,r = i;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if ((a[i] - a[mid] <= d)) pre[i] = mid,r = mid - 1;
				else l = mid + 1;
			}
			l = i,r = n;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if ((a[mid] - a[i] <= d)) nxt[i] = mid,l = mid + 1;
				else r = mid - 1;
			}
		}
		int ans = 0;
		for(int len = 1;len <= n;len ++)
			for(int u = 1;u + len - 1 <= n;u ++)
			{
				int v = u + len - 1;
				if (u == v)
				{
					f[u][v] = f[v][u] = 0;
					continue;
				}
				if (v == u + 1)
				{
					if (nxt[u] >= v) f[u][v] = f[v][u] = 1;
					else f[u][v] = f[v][u] = INF;
					continue;
				}
				if (u == 1 && v == 4)
					u ++,u --;
				int u2 = nxt[u],v2 = pre[v];
				int f1 = f[u2][v],f2 = f[u][v2];
				f[u][v] = f[v][u] = min(f1,f2) + 1;
//				cout << u << ' ' << v << ' ' << f[u][v] << endl;
				if (f1 != f2) continue;
				int x = f1 + 1;
				if (u2 >= v || f[u2][v2] == x - 2 || f[u2 - 1][v] == x - 1 && f[u2 - 1][v2] != x - 2 || f[u][v2 + 1] == x - 1 && f[u2][v2 + 1] != x - 2) continue;
				ans ++;
			}
		cout << ans << endl;
	}
	return 0;
 } 
/*
1 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

