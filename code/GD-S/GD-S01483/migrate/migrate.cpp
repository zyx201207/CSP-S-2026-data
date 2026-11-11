#include <bits/stdc++.h>
using namespace std;

long long a[2000010],n,p;
long long d[2000010],c[2000010],vis[2000010];
struct node
{
	int id,w;
	bool operator < (const node&cmp) const
	{
		return w>cmp.w;
	}
};
priority_queue<node> q;
void dij(int id)
{
	q.push({id,0});
	c[id]=1;d[id]=0;
	while(!q.empty())
	{
		node f=q.top();
		q.pop();
		for(int j=f.id+1;j<=n;j++)
		{
			if(a[f.id]+p<a[j]) break;
			if(d[f.id]+1==d[j]) c[j]+=c[f.id];
			else if(d[f.id]+1<d[j])
			{
				d[j]=d[f.id]+1,c[j]=c[f.id];
				if(!vis[j])
				{
					vis[j]=1;
					q.push({j,d[j]});
				}
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ca,abc;
	scanf("%d%d",&ca,&abc);
	while(abc--)
	{
		scanf("%lld%lld",&n,&p);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),d[i]=(long long)1e18;
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			dij(i);
			for(int j=i+1;j<=n;j++)
			{
				if(c[j]==2) cnt++;
				d[j]=c[j]=0;d[j]=(long long)1e18;vis[j]=0;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
