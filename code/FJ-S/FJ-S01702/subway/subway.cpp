#include<bits/stdc++.h>
using namespace std;
struct ss{
	int y,n,z;
}g[51000000];
int w[250000],h[50000000],l,f[250000],v[250000];
void add(int x,int y,int z)
{
	g[++l].y=y;
	g[l].z=z;
	g[l].n=h[x];
	h[x]=l;
}
priority_queue<pair<int,int> > q;
void spfa(int t,int w)
{
	memset(f,63,sizeof(f));
	f[t]=0;
	while(!q.empty())
		q.pop();
	q.push(make_pair(0,t));
	int x,y;
	while(!q.empty())
	{
		x=q.top().second;q.pop();
		if(x==w)
			break;
		if(v[x])
			continue;
		v[x]=0;
		for(int i=h[x];i;i=g[i].n)
		{
			y=g[i].y;
			if(f[y]>f[x]+g[i].z)
			{
				f[y]=f[x]+g[i].z;
				q.push(make_pair(-f[y],y));
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q,x,y,k;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&x,&y);
			add(x,m+i,y);
			add(m+i,x,y);
		}
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		spfa(x,y);
		printf("%d\n",f[y]+w[x]+w[y]);
	}
	return 0;
}
