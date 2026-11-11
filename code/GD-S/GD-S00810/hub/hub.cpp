#include <bits/stdc++.h>
#define rep1(i,a,b) for (int i = a;i <= b;i++)
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,k,u,v;
bool sign[N],vis[N];
pair<int,int> qu[N];
vector<int> g[N];
/*
1~3 暴力 
*/
void dfs(int u)
{
	vis[u] = true;
	for (auto v : g[u])
		if (!vis[v] && sign[v])
			dfs(v);
}
int bfs(int u)
{
	int hd = 1;
	int tl = 1;
	qu[tl++] = {u,0};
	while (hd < tl)
	{
		auto u = qu[hd++];
		if (sign[u.first])
			return u.second;
		vis[u.first] = true;
		for (auto v : g[u.first])
			if (!vis[v])
				qu[tl++] = {v,u.second + 1};
	}
}
void t1_2_3()
{
	cin >> n >> k;
	rep1(i,1,n - 1)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	int ans = 1145141919ll;
	//枚举放置哪些点作为特殊点
	rep1(i,0,(1ll << n) - 1)
		if (__builtin_popcountll(i) == k)
		{
			int ns = 0;
			rep1(j,0,n - 1)
				if ((i >> j) & 1)
					sign[j + 1] = true;
			//检查是否只有<=2个连通块
			int cnt = 0;
			rep1(j,1,n)
				if (sign[j] && !vis[j])
				{
					dfs(j);
					cnt++;
				}
			memset(vis,0,sizeof vis);
			if (cnt <= 2)
			{
				rep1(j,1,n)
				{
					ns = max(ns,bfs(j));
					memset(vis,0,sizeof vis);
				}
				if (ns == 0)
				{
					rep1(j,1,10)
						cout << sign[j];
					cout << '\n';
				}
				ans = min(ans,ns);
			}
			rep1(j,1,n)
				sign[j] = false;
		}
	cout << ans << '\n';
	rep1(i,1,n)
		g[i].clear();
}
/*
k=2
只能选2个点
找出树的直径，在 1/4 3/4 的地方分别放一个 
*/
int dep[N],f[N];
void Dfs(int u,int fa)
{
	f[u] = fa;
	for (auto v : g[u])
		if (v != fa)
		{
			dep[v] = dep[u] + 1;
			Dfs(v,u);
		}
}
void DFs(int u,int fa)
{
	for (auto v : g[u])
		if (v != fa)
		{
			dep[v] = min(dep[v],dep[u] + 1);
			DFs(v,u);
		}
}
bool Check(int x,int u,int v,const vector<int>& path)
{
	u = path[x];
	v = path[path.size() - x - 1];
	memset(dep,0x3f,sizeof dep);
	DFs(u,0);
	DFs(v,0);
	rep1(i,1,n)
		if (dep[i] > x)
			return false;
	return true;
}
void t7_11_12()
{
	cin >> n >> k;
	rep1(i,1,n - 1)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	Dfs(1,0);
	int u = 1;
	rep1(i,2,n)
		if (dep[i] > dep[u])
			u = i;
	memset(dep,0,sizeof dep);
	Dfs(u,0);
	int v = 1;
	rep1(i,2,n)
		if (dep[i] > dep[v])
			v = i;
	vector<int> path;
	int tv = v;
	for (;tv != u;tv = f[tv])
		path.push_back(tv);
	path.push_back(u);
	reverse(path.begin(),path.end());
	//u~v，长度为dep[v]，1~dep[v]+1
	//设答案为x，则两个分别放在 x+1 & dep[v]-x+1，且 dep[v]-x-x <= (2*x+1)
	int l = 0;
	int r = path.size() - 1;
	int ans = 1145141919ll;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (Check(mid,u,v,path))
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans << '\n';
	memset(dep,0,sizeof dep);
	rep1(i,1,n)
		g[i].clear();
}
/*
A性质
1-2-3-4
| | |
5 6 7
其实等价于：
1-2-3
| | |
5 6 7（因为4和7等价，而且放在4一定不优）
若k=n，则为0
m<=k<n，则为1
k<m：必然将特殊点安放在1~m，设最大距离为x，二分答案 
x=3:两头从[1,m]缩小到[x,m-x+1] 
之后两头向里收缩，每次收缩 2x+1，看够不够 
1-2-*-4-*-6-7
| | | | | | |
8 9 1011121314
*/
bool check(int x,int m)
{
	//l,r维护当前的两端特殊点 
	int l = x;
	int r = m - x + 1;
	//由于必须形成连通块，还剩k-2次，l,r往里收缩
	r -= (k - 2);
	return ((r - l) <= (2 * x + 1));
}
void t13_14()
{
	cin >> n >> k;
	rep1(i,1,n - 1)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int m = n / 2;
	if (k == n)
		cout << "0\n";
	else if (k >= m)
		cout << "1\n";
	else
	{
		int l = 0;
		int r = n;
		int ans = 0;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (check(mid,m))
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		cout << ans << '\n';
	}
	//clear
	rep1(i,1,n)
		g[i].clear();
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		if (1 <= c && c <= 3)
			t1_2_3();
		if (c == 7 || c == 11 || c == 12)
			t7_11_12();
		if (c == 13 || c == 14)
			t13_14();
	}
}

