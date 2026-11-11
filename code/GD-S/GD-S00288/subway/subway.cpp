#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+114;
const int inf=0x3f3f3f3f;
int c,n,m,d,q,A,vis[N],T;
ll dis[N];
ll w[N];
struct node
{
	int x,y;
};
vector<node> a[N];
ll spfa(int x,int y)
{
	memset(dis,0x3f,sizeof dis);
	dis[x]=0;
	queue<int> q;
	q.push(x);
	while(q.size())
	{
		int now=q.front();
		q.pop();
		for(node u:a[now])
		{
			if(dis[u.x]>dis[now]+u.y)
			{
				dis[u.x]=dis[now]+u.y;
				q.push(u.x);
			}
		}
	}
	return dis[y];
}
ll bfs(int x,int y)
{
	memset(vis,0,sizeof vis);
	queue<node> q;
	q.push(node{x,0});
	vis[x]=1;
	while(q.size())
	{
		node now=q.front();
		for(node u:a[now.x])
		{
			if(vis[u.x]==0)
			{
				vis[u.x]=1;
				q.push(node{u.x,now.y+1});
			}
			if(u.x==y)
			{
				return (ll)(now.y+1)*T;
			}
		}
	}
}
int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if(k>2)A=1;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			T=y;
			a[i+m].push_back(node{x,y});
			a[x].push_back(node{i+m,y});
		}
	}
	if(q<=2000)
	{
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",spfa(x,y)+w[x]+w[y]);
		}
	}
	else if(!A)
	{
		
	}
	else if(d<=2)//Ê÷ 
	{
		
	}
	else//B 
	{
		
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

