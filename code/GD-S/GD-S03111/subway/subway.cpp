#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
struct Edge
{
	int v,next,idx;
}e[M << 2];
int c,n,m,d,q;
int x,y;
ll ans;
int w[M];
int t[M][N];
int h[M],cnt;
bool vis[M];
void add(int,int,int);
void dfs(int,int,ll);
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		int k,a,tmp;
		int z;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> a >> tmp;
			t[a][i] = tmp;
			if(j > 1)
			{
				add(z,a,i);
				add(a,z,i); 
			}
			z = a;
		}
	}
	for(int i = 1;i <= q;i++)
	{
		memset(vis,0,sizeof vis);
		cin >> x >> y;
		if(x > y) swap(x,y);
		ans = 9223372036854775806;
		dfs(x,0,0);
		cout << ans << endl;
	}
	return 0;
}
void add(int u,int v,int idx)
{
	e[++cnt] = {v,h[u],idx};
	h[u] = cnt;
}
void dfs(int u,int from,ll sum)
{
	if(u == y)
	{
		ans = min(ans,sum + t[y][from] + w[x] + w[y]);
		return;
	}
	for(int i = h[u];~i;i = e[i].next)
	{
		int v = e[i].v,idx = e[i].idx;
		if(vis[v]) continue;
		vis[v] = true;
 		if(from == 0)
		{
			dfs(v,idx,sum + t[u][idx]);
		}
		else if(from == idx)
		{
			dfs(v,idx,sum);
		}
		else if(from != idx)
		{
			dfs(v,idx,sum + t[u][from] + t[u][idx]);
		}
	}
}
