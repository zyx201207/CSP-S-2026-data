#include<bits/stdc++.h>
using namespace std;
int e[33001][3],head[33001],tot=0;
int dis[1000001],dl[1000001];
int c,n,m,d,q;
void jian(int u,int w,int v)
{
	tot++;
	e[tot][1]=w;
	e[tot][2]=v;
	e[tot][0]=head[u];
	head[u]=tot;
}
int dij(int x,int y)
{
	memset(dis,0x3f,sizeof(dis));
	int head1=0,tail=1;
	dl[1]=x;
	dis[x]=0;
	while(head1<tail)
	{
		head1++;
		int xx=dl[head1];
		for(int i=head[xx];i;i=e[i][0])
		{
			int yy=e[i][1];
			if(dis[xx]+e[i][2]<dis[yy])
			{
				dis[yy]=dis[xx]+e[i][2];
			//	cout<<yy<<" "<<xx<<" "<<dis[yy]<<" "<<dis[xx]<<" "<<e[i][2]<<endl;
				tail++;
				dl[tail]=yy;
			}
		}
	}
	return dis[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		int w;
		scanf("%d",&w);
		jian(i,i+m,w);
		jian(i+m,i,w);
	}
	for(int i=1;i<=n;i++)
	{
		int k,last=-1,kk,kkk;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&kk,&kkk);
			jian(kk+m,i+kk*10+100*m,kkk);
			//cout<<kk+m<<"  "<<kk+5*m+i<<" "<<kkk<<endl;
			jian(kk*10+i+100*m,kk+m,kkk);
			if(last!=-1)
			{
				jian(last*10+m*100+i,kk*10+m*100+i,0);
				jian(kk*10+m*100+i,last*10+m*100+i,0);
			}
			last=kk;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int to,from;
		scanf("%d%d",&from,&to);
		printf("%d\n",dij(from,to));
	}
	return 0;
}
