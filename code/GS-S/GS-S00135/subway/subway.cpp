#include <iostream>
#include <vector>
typedef long long ll;
const int N = 5e5 + 5,L = 505;
const ll INF = 1e16;
int w[N];
struct node
{
	int v,w;
}l1[N][22];
int top[N];
ll dis[L][L];
int main(void)
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c = 0,m = 0,n = 0,d = 0,q = 0;
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
	for(int i = 1;i <= n;i++)
		scanf("%d",&w[i]);
	for(int i = 1;i <= m;i++)
	{
		int k = 0;
		scanf("%d",&k);
		for(int j = 1,a = 0,t = 0;j <= k;j++)
		{
			scanf("%d%d",&a,&t);
			l1[a][++top[a]].v = i;
			l1[a][top[a]].w = t;
		}
	}
	for(int i = 1;i < m;i++)
		for(int j = i + 1;j <= m;j++)
			dis[i][j] = dis[j][i] = INF;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= top[i];j++)
			for(int k = 1;k <= top[i];k++)
				if(j != k && l1[i][j].w + l1[i][k].w < dis[l1[i][j].v][l1[i][k].v])
					dis[l1[i][j].v][l1[i][k].v] = l1[i][j].w + l1[i][k].w;
	for(int k = 1;k <= m;k++)
		for(int i = 1;i <= m;i++)
			for(int j = 1;j <= m;j++)
				if(dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	while(q--)
	{
		int x = 0,y = 0;
		scanf("%d%d",&x,&y);
		ll ans = INF;
		for(int i = 1;i <= top[x];i++)
			for(int j = 1;j <= top[y];j++)
				if(ans > l1[x][i].w + l1[y][j].w + dis[l1[x][i].v][l1[y][j].v])
					ans = l1[x][i].w + l1[y][j].w + dis[l1[x][i].v][l1[y][j].v];
		printf("%lld\n",ans + w[x] + w[y]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
