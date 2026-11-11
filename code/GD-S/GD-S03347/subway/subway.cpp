#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505];
bool flag[505]={0};
int map_subway[505][505]={-1};
bool visited[505];
struct Queue
{
	int data,sum;
}que[505];
int front=0,rear=0;
long long bfs (int s,int t)
{
	long long p_sum=que[rear].sum;
	if (front==rear)
	{
		return p_sum;
	}
	int pos=que[rear++].data;
	visited[pos]=1;
	if (pos==t)
	{
		printf ("%lld ",p_sum);
		return p_sum;
	}
	p_sum+=w[pos];
	for (int i=1;i<=d;i++)
	{
		if (!visited[i] && map_subway[pos][i]!=-1)
		{
			que[front].sum=p_sum+map_subway[pos][i],que[front++].data=i;
		}
	}
	bfs (s,t);
}
int main ()
{
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		scanf ("%d",&w[i]);
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		scanf ("%d",&k);
		for (int j=1;j<=k;j++)
		{
			int a,t;
			scanf ("%d%d",&a,&t);
			if (flag[a])
			{
				map_subway[i][a]=t,map_subway[a][i]=t;
				map_subway[i][a]+=w[a],map_subway[a][i]+=w[a];
			}else{
				map_subway[i][a]=0,map_subway[a][i]=0;
				flag[a];
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		scanf ("%d%d",&x,&y);
		que[front++].data=x;
		long long ans=bfs (x,y);
		printf ("%lld\n",ans);
	}
	return 0;
} 
