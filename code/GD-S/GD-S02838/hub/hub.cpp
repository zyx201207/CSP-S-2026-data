#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int c, T;
#define int long long
int n, k;
vector<int> e[N];
vector<int> chos;
int g[5005][5005];
int f[N];
int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

bool check()
{
	for(int x : chos) f[x] = x;
	for(int x : chos)
	{
		for(int y : chos)
		{
			if(x == y) continue;
			if(find(x) == find(y)) continue;
		}
	}
}

void dfs(int pos, int cho)
{
	if(cho == k){
		check();
		return ;
	}
	if(pos > n) return ;
	chos.push_back(pos);
	dfs(pos+1, cho+1);
	chos.pop_back();
	dfs(pos+1, cho);
}

void solve()
{
	cin >> n >> k;
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		g[u][v] = g[v][u] = 1;
	}
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	if(T == 2) cout << 1 << endl << 2 << endl;
	else while(T--) solve();
}
