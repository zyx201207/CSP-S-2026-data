#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 10;
const int M = N << 1;
const int K = 21;

int c, T;
int n, k;
int h[N], e[M], ne[M], idx;
int deep[N], p[N][K];
int P[N], answer = 1e18;
int s[N], d[N];
bool st[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int x)
{
	if(P[x] != x) P[x] = find(P[x]);
	return P[x];
}

void dfs(int u, int fa)
{
	if(fa == -1) p[u][0] = u, deep[u] = 1;
	else p[u][0] = fa, deep[u] = deep[fa] + 1;
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(j == fa) continue;
		dfs(j, u);
	} 
}

int lca(int u, int v)
{
	if(deep[u] < deep[v]) swap(u, v);
	for(int i = 20 ; i >= 0 ; i -- )
		if(deep[p[u][i]] >= deep[v])
			u = p[u][i];
	if(u == v) return u;
	for(int i = 20 ; i >= 0 ; i -- )
		if(p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];
	return p[u][0];
}

void dfs1(int u)
{
	if(u == k + 1)
	{
		for(int i = 1 ; i <= n ; i ++ ) P[i] = i;
		for(int i = 1 ; i <= n ; i ++ ) st[i] = 0;
		for(int i = 1 ; i <= k ; i ++ ) st[s[i]] = true;
		for(int i = 1 ; i <= k ; i ++ )
			for(int j = h[s[i]] ; j != -1 ; j = ne[j])
			{
				int u = s[i], v = e[j];
				if(st[e[j]] == false) continue;
				int fu = find(u), fv = find(v);
				if(fu == fv) continue;
				P[fu] = fv;
			}
		set<int> S;
		S.clear();
		for(int i = 1 ; i <= k ; i ++ ) S.insert(find(s[i]));
		if(S.size() > 2) return;
		for(int i = 1 ; i <= n ; i ++ ) d[i] = 1e18;
		for(int i = 1 ; i <= n ; i ++ )
			for(int j = 1 ; j <= k ; j ++ )
			{
				int u = i, v = s[j];
				int lca_ = lca(u, v);
				d[i] = min(d[i], deep[u] + deep[v] - 2 * deep[lca_]);
			}
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++ ) ans = max(ans, d[i]);
//		for(int i = 1 ; i <= k ; i ++ ) cout << s[i] << " ";
//		cout << "\n";
//		cout << ans << "\n";
		answer = min(answer, ans); 
		return;
	}
//	if(n - s[u - 1] < (k - u)) return;
	for(int i = s[u - 1] + 1 ; i <= n ; i ++ )
	{
		s[u] = i;
		dfs1(u + 1);
	}
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	memset(h, -1, sizeof h);
	cin >> c >> T;
	while(T -- )
	{
		for(int i = 0 ; i <= 2 * idx ; i ++ ) e[i] = ne[i] = 0, h[i] = -1;
		idx = 0; 
		cin >> n >> k;
		for(int i = 1 ; i < n ; i ++ )
		{
			int a, b;
			cin >> a >> b;
			add(a, b);
			add(b, a);
		}
		dfs(1, -1);
		for(int i = 1 ; i <= 20 ; i ++ )
			for(int j = 1 ; j <= n ; j ++ )
				p[j][i] = p[p[j][i - 1]][i - 1];
		answer = 1e18;
		dfs1(1);
		cout << answer << "\n";
	} 
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
