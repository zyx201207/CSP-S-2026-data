#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int c,n,m,d,q;
int ans;
int w[N*N];
int a[N][N];
int t[N][N];
int xr[N],yr[N];
int k[N];
vector<int> g[N];
struct node
{
	int idx,idy; // line station
	int val;
};
/// 起始和结束
void bfs(int sr,int er)
{
	ans = 0;
	queue<node> que;
	for (auto i:g[sr])
	{
		que.push({i,sr,w[sr]+t[i][sr]});
	}
	while(!que.empty())
	{
		int line = que.front().idx;
		int station = que.front().idy;
		int val = que.front().val;
		if(station==er)
		{
			ans = min(ans,val+w[er]+t[line][station]);
		}
		for (auto i:g[station])
		{
			que.push({i,station,val+t[line][station]+t[i][station]});
		}
		for (int i = 1;i<=k[line];i++)
		{
			que.push({line,a[line][i],val});
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for (int i = 1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for (int j = 1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
			g[a[i][j]].push_back(i);
		}
	}
	for (int i = 1;i<=q;i++)
	{
		scanf("%d%d",&xr[i],&yr[i]);
	}
	for (int i = 1;i<=q;i++)
	{
		bfs(xr[i],yr[i]);
		printf("%d\n",ans);
	}
	return 0;
}
