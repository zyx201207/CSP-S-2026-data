#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int w_opt,t,n,m,k,w_cnt,x,y,w_temp,w_ans,w_head[1000005],f[1000005];
struct node{
	int w_next,w_to;
}w_edge[2000005];
struct Node{
	int a,b;
};
queue<Node> q;
void w_add(int u,int v)
{
	w_edge[++w_cnt]={w_head[u],v};
	w_head[u]=w_cnt;
}
void w_dfs(int u)
{
	f[u]=k;
	for(int i=w_head[u];i;i=w_edge[i].w_next)
	{
		if(!f[w_edge[i].w_to])
			w_dfs(w_edge[i].w_to);
	}
}
int main()
{
//	freopen("hub1.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&w_opt,&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		w_ans=n+1;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			w_add(x,y);
			w_add(y,x);
		}
		if(n==m)
		{
			printf("0\n");
			continue;
		}
		for(int i=0;i<(1<<n);i++)
		{
			x=0;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1)))
				{
					x++;
					f[j]=0;
				}
				else
					f[j]=-1;
			}
			if(x!=m)
				continue;
			k=0;
			for(int j=1;j<=n;j++)
			{
				if(!f[j])
				{
					++k;
					if(k>2)
						break;
					w_dfs(j);
				}
			}
			if(k>2)
				continue;
			for(int j=1;j<=n;j++)
			{
				if(f[j]==-1)
					f[j]=n+1;
				else
				{
					f[j]=0;
					q.push({j,0});
				}
			}
			while(!q.empty())
			{
				Node w_now=q.front();
				q.pop();
				if(f[w_now.a]!=w_now.b)
					continue;
				for(int j=w_head[w_now.a];j;j=w_edge[j].w_next)
				{
					if(f[w_now.a]+1<f[w_edge[j].w_to])
					{
						f[w_edge[j].w_to]=f[w_now.a]+1;
						q.push({w_edge[j].w_to,f[w_edge[j].w_to]});
					}
				}
			}
			w_temp=0;
			for(int j=1;j<=n;j++)
				w_temp=max(w_temp,f[j]);
			w_ans=min(w_ans,w_temp);
		}
		printf("%d\n",w_ans);
		for(int i=0;i<=n+1;i++)
			w_head[i]=0;
		w_cnt=0;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
