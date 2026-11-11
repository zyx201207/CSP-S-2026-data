#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long 

const int N = 5e5 + 10;
int n,m,a[N],cnter[N];
vector <int> v[N];
bool vis[N];

inline void dfs(int x)
{
	for(int i = 0;i < v[x].size();i ++)
	{
		int g = v[x][i];
		dfs(g);
		cnter[x] += cnter[g];
	}
}

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = n;i >= 1;i --)
	{
		if (!vis[a[i]]) v[a[i + 1]].push_back(a[i]);
		cnter[a[i]] ++,vis[a[i]] = 1;
	}
	dfs(0);
	for(int i = 1;i <= m;i ++) 
		cout << cnter[i] << ' ';
	return 0;
}







