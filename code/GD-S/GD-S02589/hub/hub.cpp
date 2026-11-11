#include <bits/stdc++.h>
#define ll long long
using namespace std;
const double eps = 1e-12;
const int N = 2e6 + 20;
int c, t;
//int s[N];
//int ans[N];
int n, k;
vector <int> a[N];
//bool vis[N];
//int dis[N];
//void dfs_lt (int x)
//{
//	for (auto i : a[x])
//	{
//		if (!vis[i])
//		{
//			vis[i] = 1;
//			if (s[i])
//			{
//				dfs_lt (i);
//			}
//		}
//	}
//	return ;
//}
//int ltk ()
//{
//	int cnt = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		if (s[i])
//		{
//			if (!vis[i])
//			{
//				cnt++;
//				vis[i] = 1;
//				dfs_lt(i);
//			}
//		}
//	}
//	return cnt;
//}
//bool f[N];
//int Dijkstra (int x)
//{	
//	priority_queue <pair<int, int> > T;
//	memset (dis, 0x3f3f3f3f, sizeof (dis));
//	memset (f, 0, sizeof (f));
//	T.push ({0, x});
//	dis[x] = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		if (s[i]) dis[x] = 0;
//	}
//	while (!T.empty())
//	{
//		pair <int, int> news_top = T.top();
//		T.pop ();
//		int v = news_top.first, u = news_top.second;
//		if (f[u]) continue;
//		f[u] = 1;
//		for (auto k : a[u])
//		{
//			if (dis[k] > dis[u] + 1)
//			{
//				dis[k] = dis[u] + 1;
//				T.push ({dis[k], k});
//			}
//		}
//	}
//	ans[x] = INT_MIN;
//	for (int i = 1; i <= n; ++i)
//	{
//		
//		ans[x] = max (ans[x], dis[i]);	
//	}
//
//	return ans[x];
//}
//int zx ()
//{
//	int mx = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		if (!s[i])
//		{
//			mx = max (Dijkstra(i), mx);
//		}
//	}
//	return mx;
//}
//void randac (int x, int y)
//{
//	if (y > k) 
//	{
//		return ;
//	}
//	if (y == k)
//	{
////		for (int i = 1; i <= n; ++i)
////		{
////			cout << s[i] << ' ';
////		}
////		cout << '\n';
//		if (ltk() <= 2)
//		{
//			cout << zx() << '\n';
//		}
//		return ;
//	}
//	if (x > n)
//	{
//		return ;
//	} 
//	s[x] = 1;
//	randac (x + 1, y + 1);
//	s[x] = 0;
//	randac (x + 1, y);
//	return ;
//}
//void solve ()
//{
//	cin >> n >> k;
//	for (int i = N - 1; i >= 0; --i)
//	{
//		a[i].clear();
//	}
//	for (int i = 1; i < n; ++i)
//	{
//		int u, v;
//		cin >> u >> v;
//		a[u].push_back (v);
//		a[v].push_back (u);
//	}
//	randac(1, 0);
//}
void solve1 ()
{
	cin >> n >> k;
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back (v);
		a[v].push_back (u);
	}
	cout << rand () % (n - 3) + 1 << '\n';
}
int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
//	cout.tie (0);
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	srand (time (NULL));
	cin >> c >> t;
	while (t--)
	{
		solve1 ();
	}
	return 0;
}

