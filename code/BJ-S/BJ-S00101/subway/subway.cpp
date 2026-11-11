#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
int w[500005],num[505];
int e[500005][23];
int ct[500005],reg[25],v[500005][23];
LL dis[505][505];
void floyd(int n)
{
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
				if (i!=j && j!=k && k!=i && dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j] = dis[j][i] = dis[i][k]+dis[j][k];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    LL c,n,m,d,q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for (int i = 1;i <= m;i++)
        scanf("%d",&w[i]);
    for (int i = 0;i <= 500;i++)
    	for (int j = 0;j <= 500;j++)
    		dis[i][j] = 1e18;
    for (int i = 1;i <= n;i++)
    {
    	dis[i][i] = 0;
    	scanf("%d",&num[i]);
    	for (int j = 1;j <= num[i];j++)
        {
        	int x,t;
        	scanf("%d%d",&x,&t);
            ct[x]++;
            v[x][ct[x]] = i;
            e[x][ct[x]] = t;
        }
    }
    for (int i = 1;i <= m;i++)
    {
    	for (int j = 1;j <= ct[i];j++)
    		reg[j] = v[i][j];
        for (int j = 1;j <= ct[i];j++)
        	for (int k = j+1;k <= ct[i];k++)
        	{
        		dis[reg[j]][reg[k]] = min(dis[reg[j]][reg[k]],1ll*e[i][j]+e[i][k]);
        		dis[reg[k]][reg[j]] = dis[reg[j]][reg[k]];
        	}
    }
    floyd(n);
    while (q--)
    {
    	LL ans = 1e18;
    	int x,y;
    	scanf("%d%d",&x,&y);
        for (int i = 1;i <= ct[x];i++)
        	for (int j = 1;j <= ct[y];j++)
        	{
        		LL sum = 1ll*w[x]+w[y];
        		sum += dis[v[x][i]][v[y][j]];
        		sum += 1ll*e[x][i] + e[y][j];
                ans = min(ans,sum);
        	}
        printf("%lld\n",ans);
    }
	return 0;
}