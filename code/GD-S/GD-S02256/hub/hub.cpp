#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , k , ans;
int fa[30] , dep[30];
bool flag[30] , flag1[30];
vector<int> g[30];
void dfs(int u , int f)
{
	dep[u] = dep[f] + 1;
	fa[u] = f;
	for(int i = 0 ; i < g[u].size() ; i++)
	{
		if(g[u][i] == f)continue;
		dfs(g[u][i] , u);
	}
}
int find(int u  , int v)
{
	int ans = 0;
	if(dep[u] < dep[v])swap(u , v);
	while(dep[u] > dep[v])
	{
		ans ++;
		u = fa[u];
	}
	while(u != v)
	{
		u = fa[u];
		v = fa[v];
		ans += 2;
	}
	return ans;
}
void solve(int u)
{
	flag1[u] = true;
	for(int v : g[u])
	{
		if(flag[v] && !flag1[v])solve(v);
	}
}
void chose(int step)
{
	if(step > k)
	{
		memset(flag1 , 0 , sizeof flag1);
		int res = 0;
//		for(int i = 1 ; i <= n ; i++)if(flag[i])cout << i << " ";
//		cout << endl;
		for(int i = 1 ; i <= n ; i++)
		{
			if(flag[i])continue;
			int minn = 1e18;
			for(int j = 1 ; j <= n ; j++)
			{
				if(!flag[j])continue;
//				cout << i << " " << j << endl;
				minn = min(minn , find(i , j));
			}
			res = max(res , minn);
		}
//		if(res == 2)
//		{
//			for(int i = 1 ; i <= n ; i++)if(flag[i])cout << i << " ";
//			cout << endl;
//		}
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			if(flag[i] && !flag1[i])
			{
				cnt++;
				solve(i);
			}
		}
		if(cnt > 2)return;dd
		ans = min(ans , res);
		return;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(flag[i])continue;
		flag[i] = true;
		chose(step + 1);
		flag[i] = false;
	}
}
inline void work()
{
	ans = 1e18;
	cin >> n >> k;
	for(int i = 1 ; i < n ; i++)
	{
		int u , v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1 , 0);
//	for(int i = 1 ; i <= n ; i++)cout << dep[i] << " " << fa[i] << endl;
//	cout << find(1 , 5) << endl;
	chose(1);
	cout << ans << endl;
	for(int i = 1 ; i <= n ; i++)g[i].clear();
}
signed main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout); 
	int c , t;
	cin >> c >> t;
	while(t--)
	{
		if(c <= 3)work();
	}
	return 0;
}
