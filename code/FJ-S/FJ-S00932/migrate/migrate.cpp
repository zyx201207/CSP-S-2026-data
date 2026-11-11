#include<bits/stdc++.h>
#define N 50005
typedef long long i64;
i64 x[N],pt[N],dt[N],vs[N],t,n,d;
std::vector<i64>g[N]; 
int main(void)
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%*lld%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i)
			g[i].clear();
		for(int i=1;i<=n;++i)
			scanf("%lld",x+i);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n&&x[j]-x[i]<=d;++j)
				g[i].push_back(j),g[j].push_back(i);
		int r=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				pt[j]=1;
			memset(dt,0x3f,sizeof dt);
			memset(vs,0x00,sizeof vs);
			std::queue<int>q;
			q.push(i),vs[i]=0,dt[i]=0;
			while(!q.empty())
			{
				int u=q.front();q.pop();
				if(vs[u])continue;vs[u]=1;
				for(int v:g[u])
				{
					if(dt[u]+1==dt[v])
						pt[v]+=pt[u];
					else if(dt[v]>dt[u]+1)
						dt[v]=dt[u]+1,pt[v]=pt[u],q.push(v);
				}
			}
			for(int j=i+1;j<=n;++j)
				r+=pt[j]==2;
		}
		printf("%d\n",r);
	}
	return 0;
}
/*好的，我来到了T3
显然以我的水平解决它是不可能的，
于是我选择先看部分分。 
容易观察到，一只海鸥所能到达的岛屿是一个区间
性质A:等差数列，如果海鸥能到达的只有一个，显然不存在2条 
如果能到达2个，为1的情况只能是恰好间隔2~3个岛
 写个N^2吧。，按题意模拟。 
 模拟完毕。 
 最后1min，让我来感叹一下CCF题出的还行，适合我的水平。 
*/ 
