// 猜一手：和 x 组成合法二元组 (x, y), x<y 的 y 在一个区间里

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 5;

int c, t, n, d, a[N], dis[N], g[N], val1[N], val2[N], tval1[N], tval2[N];
int nr[N], nl[N];
bool vis[N];
queue<int> q;
void bfs(int s)
{
	for(int i = 1; i <= n; i++) dis[i] = 1e18, g[i] = 0;
	dis[s] = 0, g[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
//		cout << u << ' ' << dis[u] << ' ' << g[u] << '\n';
		for(int i = 1; i <= n; i++)
		{
			if(abs(a[u] - a[i]) <= d)
			{
				if(dis[i] == 1e18)
				{
//					cout << u << " -> " << i << ' ' << g[u] << ' ' << g[i] << '\n';
					dis[i] = dis[u] + 1;
					g[i] = g[u];
					q.push(i);
				}
				else if(dis[i] == dis[u] + 1)
				{
//					cout << u << " -> " << i << ' ' << g[u] << ' ' << g[i] << '\n';
					g[i] += g[u], g[i] = min(g[i], 3ll);
				}
			}
		}
	}
	return;
}

int f1[N], f2[N];
//bool perfect
vector<int> gl[N], gr[N];

bool check(int x, int y)
{
	if(x < y) swap(x, y);
	return (nl[x] == y && nr[y] == x);
}

bool visl[N], visr[N];

void dfsl(int u)
{
	if(visl[u]) return;
	visl[u] = 1;
	for(auto v : gl[u])
	{
		dfsl(v);
		if(check(u, v)) f1[u] += f1[v] + 1, val1[u] += val1[v];
//		tval1[u] += val1[v];
	}
	return;
}

void dfsr(int u)
{
	if(visr[u]) return;
	visr[u] = 1;
	for(auto v : gr[u])
	{
		dfsr(v);
		if(check(u, v)) f2[u] += f2[v] + 1, val2[u] += val2[v];
//		tval2[u] += val2[v];
	}
//	cout << u << ' ' << tval[i] << ' '
	
	return;
}

void solve()
{
	cin >> n >> d;
	int ans = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], gl[i].clear(), gr[i].clear(), visl[i] = visr[i] = 0, val1[i] = val2[i] = tval1[i] = tval2[i] = 0;
	for(int i = 1; i <= n; i++) f1[i] = f2[i] = 0;
	nl[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		nl[i] = nl[i - 1];
		while(a[i] - a[nl[i]] > d) nl[i]++;
	}
	nr[n] = n;
	for(int i = n - 1; i >= 1; i--)
	{
		nr[i] = nr[i + 1];
		while(a[nr[i]] - a[i] > d) nr[i]--;
	}
	for(int i = 1; i <= n; i++) val1[nl[i]]++;
	for(int i = 1; i <= n; i++) val2[nr[i]]++;
	for(int i = 1; i <= n; i++) tval1[i] = val1[i], tval2[i] = val2[i];
	
//	for(int i = 1; i <= n; i++) cout << nl[i] << ' '; cout << '\n';
//	for(int i = 1; i <= n; i++) cout << nr[i] << ' '; cout << '\n';
	for(int i = 1; i <= n; i++)
		if(nl[i] != i) gl[nl[i]].push_back(i);
	for(int i = n; i >= 1; i--)
		if(!visl[i]) dfsl(i);
	for(int i = 1; i <= n; i++)
		if(nr[i] != i) gr[nr[i]].push_back(i);
	for(int i = 1; i <= n; i++)
		if(!visr[i]) dfsr(i);
	if(n <= 300)
	{
		for(int x = 1; x <= n; x++)
		{
			for(int y = x + 1; y <= n; y++)
			{
				int u = x, v = y;
				int c1 = 0, c2 = 0;
				bool flag = 1;
				while(nr[u] < y)
				{
					if(nr[u] == u) {flag = 0; break;}
					u = nr[u], c1 += u;
				}
				while(nl[v] > x)
				{
					if(nl[v] == v) {flag = 0; break;}
					v = nl[v], c2 += v;
				}			
				if(!flag) continue;
				if(c1 - c2 == 1) ans++;
			}
		}
		cout << ans << '\n';
		return;
	}

	// 称一个区间 [l, r] 是完美的，当且仅当从左往右、从右往左贪心跳的路径完全相同
	// 对一个 (i, i+1)，它产生影响的 (x, y) 需要让 [x, nl[i]] 和 [nr[i+1], y] 都是完美区间
	// 考虑通过 DP 求出以一个点结尾/开头的完美区间数量？ 
	
//	for(int i = 1; i <= n; i++)
//	{
//		cout << f1[i] << ' ';
//	}
//	cout << '\n';
//	for(int i = 1; i <= n; i++)
//	{
//		cout << f2[i] << ' ';
//	}
//	cout<< '\n';
	
	int ans2 = 0;
	
	for(int i = 1; i < n; i++)
	{
//		if(a[nr[i + 1]] - a[i] > d) continue;
//		if(a[i + 1] - a[nl[i]] > d) continue;
	
		if(nr[i] == i) continue;
		if(check(i, i + 1)) continue;
		
//		if(nl[nr[i]] != i + 1) continue;
		
		int SL = val2[i + 1];
		int SR = val1[i];
		
		
		ans2 += SL * SR;
//		if(SL || SR) cout << i << ',' << i+1 << ' ' << SL << ' ' << SR << "\n";
	}
	
	cout << ans2 << "\n";
	
//	int ans1 = ans; ans = 0;
//	
//	
	return;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) solve(); 
	return 0;
}

/*
0 1
6 4
-3 0 1 2 3 4

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000

0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/

