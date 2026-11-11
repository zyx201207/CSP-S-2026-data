#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5 , inf = 1e12;
int ci , T , n , k;
vector <int> g[N];
bool vis[N];
void dfs (int u , int S)
{
	vis[u] = 1;
	for (int v : g[u]) if (!vis[v] && (S >> (v - 1) & 1))
	{
		dfs (v , S);
	}
}
int mn;
void Dfs (int u , int S , int fa , int c)
{
	if (S >> (u - 1) & 1)
	{
		mn = min (mn , c);
		return ;
	} 
	for (int v : g[u]) if (v != fa) Dfs (v , S , u , c + 1);
}
signed main ()
{
	freopen ("hub.in" , "r" , stdin);
	freopen ("hub.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	cin >> ci >> T;
	while (T --)
	{
		cin >> n >> k;
		for (int i = 1;i <= n;i ++) g[i].clear (); 
		for (int i = 1;i < n;i ++)
		{ 
			int u , v;
			cin >> u >> v;
			g[u].push_back (v);
			g[v].push_back (u);
		}
		int A = 1 << n;
		int ans = inf;
		for (int i = 0;i < A;i ++) if (__builtin_popcount (i) == k)
		{
			int cnt = 0;
			for (int u = 1;u <= n;u ++) vis[u] = 0;
			for (int u = 0;u < n;u ++) if (i >> u & 1)
			{
				if (!vis[u + 1])
				{
					cnt ++;
					dfs (u + 1 , i);
				}
			}
			if (cnt <= 2)
			{
				int s = 0;
				for (int u = 1;u <= n;u ++)
				{
					mn = inf;
					Dfs (u , i , 0 , 0);
					s = max (s , mn);
				}
				ans = min (ans , s);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
