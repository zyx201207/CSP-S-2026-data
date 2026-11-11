#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int w_opt,n,m,w_cnt,d,t,x,y,w_head[500005];
long long z,w_ans,a[500005],f[505][505];
struct node{
	int w_next,w_to;
	long long w_w;
}w_edge[1000005];
void w_add(int u,int v,long long w)
{
	w_edge[++w_cnt]={w_head[u],v,w};
	w_head[u]=w_cnt;
}
int main()
{
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	scanf("%d %d %d %d %d",&w_opt,&n,&m,&d,&t);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		while(x--)
		{
			scanf("%d %lld",&y,&z);
			w_add(y,i,z);
		}
	}
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(x=w_head[i];x;x=w_edge[x].w_next)
		{
			for(y=w_head[i];y;y=w_edge[y].w_next)
			{
				f[w_edge[x].w_to][w_edge[y].w_to]=min(f[w_edge[x].w_to][w_edge[y].w_to],w_edge[x].w_w+w_edge[y].w_w);
				f[w_edge[y].w_to][w_edge[x].w_to]=min(f[w_edge[y].w_to][w_edge[x].w_to],w_edge[x].w_w+w_edge[y].w_w);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(t--)
	{
		scanf("%d %d",&x,&y);
		w_ans=0x3f3f3f3f3f3f3f3f;
		for(int i=w_head[x];i;i=w_edge[i].w_next)
		{
			for(int j=w_head[y];j;j=w_edge[j].w_next)
				w_ans=min(w_ans,w_edge[i].w_w+w_edge[j].w_w+f[w_edge[i].w_to][w_edge[j].w_to]);
		}
		printf("%lld\n",w_ans+a[x]+a[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
