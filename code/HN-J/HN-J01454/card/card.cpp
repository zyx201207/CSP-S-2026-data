#include<bits/stdc++.h>
#define pre(i, l, r)	for(int i = (l); i <= (r); ++i)
#define fpre(i, r, l)	for(int i = (r); i >= (l); --i)
#define ll long long

using namespace std;

const int maxn = 5e5 + 5;
const int inf = 1e9;
const ll lnf = 2e18;

int n, m;
int a[maxn];
int nxt[maxn];
int ans[maxn];

vector<int> edges[maxn];
int v[maxn], sz[maxn];

void dfs(int x)
{
	sz[x] = 1;
	for(auto y : edges[x])
		dfs(y), sz[x] += sz[y];
	if(v[x])
		ans[v[x]] += sz[x];
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	pre(i, 1, n)
		scanf("%d", &a[i]);
	fpre(i, n, 1)
	{
		if(!nxt[a[i]])
		{
			edges[i + 1].emplace_back(i);
			v[i] = a[i];
		}
		else
			edges[nxt[a[i]]].emplace_back(i);
		nxt[a[i]] = i;
	}
	dfs(n + 1);
	pre(i, 1, m)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
