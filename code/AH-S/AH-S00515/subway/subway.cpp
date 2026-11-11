#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,Q=1e5+10;
int w[N];
struct Node {
	int a,t;
};
vector<Node> bus[505];//jingzhandian,shijian
struct Path {
	int v,t;
};
vector<Path> e[N];
int ans[N];
struct Que {
	int x,y,id,ans;
}qt[Q];
bool cmp1(Que a,Que b)
{
	return a.x<b.x;
}
bool cmp2(Que a,Que b)
{
	return a.id<b.id;
}

void dfs1(int u,int to,int t)
{
	if(t>=ans[u]) return;
	ans[u]=t;
	if(u==to) return;
	for(auto v:e[u])
	{
		dfs1(v.v,to,t+v.t);
	}
}

void dfs2(int u,int to,int t)
{
	if(t>=ans[u]) return;
	ans[u]=t;
	for(auto v:e[u])
	{
		dfs2(v.v,to,t+v.t);
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d",&a,&t);
			continue;
		}
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&a,&t);
			bus[i].push_back({a,t});
			for(auto u:bus[i])
			{
				if(u.a==a) break;
				e[a].push_back({u.a,u.t+t});
				e[u.a].push_back({a,u.t+t});
			}
		}
	}
	if(c<=8)
	{
		int x,y;
		for(int i=1;i<=q;i++)
		{
			memset(ans,0x3f,sizeof ans);
			scanf("%d%d",&x,&y);
			dfs1(x,y,0);
			printf("%d\n",ans[y]+w[x]+w[y]);
		}
	}
	else
	{
		int x,y;
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			qt[i]={x,y,i};			
		}
		sort(qt+1,qt+q+1,cmp1);
		for(int i=1;i<=q;i++)
		{
			x=qt[i].x,y=qt[i].y;
			if(qt[i-1].x==x)
			{
				qt[i].ans=ans[y]+w[x]+w[y];
				continue;
			}
			memset(ans,0x3f,sizeof ans);
			dfs2(x,y,0);
			qt[i].ans=ans[y]+w[x]+w[y];
		}
		sort(qt,qt+q+1,cmp2);
		for(int i=1;i<=q;i++)
		{
			printf("%d\n",qt[i].ans);
		}
	}
	
	
	return 0;
}
