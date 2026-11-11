#include<bits/stdc++.h>
#define ll long long
#define PII pair<long long,int>
using namespace std;
int c;
const int N=6e4+7;
const int M=2e5+7;
int n,m,d,Q;
int h[N],e[M],ne[M],idx;
ll w[M],val[500007];
int cnt;
ll dis[N];
int bz[N];
const ll INF=2e18+7;
void add(int u,int v,ll l)
{
	w[idx]=l;
	e[idx]=v;
	ne[idx]=h[u];
	h[u]=idx++;
}
void dijkstra(int s)
{
	for(int i=1;i<=cnt;i++)
	{
		bz[i]=0;
		dis[i]=INF;
	}
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push({0ll,s});
	while(q.size())
	{
		PII now=q.top();
		q.pop();
		int x=now.second;
		if(bz[x])
		continue;
		bz[x]=1;
		for(int i=h[x];i!=-1;i=ne[i])
		{
			int j=e[i];
			
			if(dis[j]>w[i]+now.first)
			{
				dis[j]=w[i]+now.first;
				q.push({dis[j],j});
			}
		}
	}
}
ll f[1007][3007];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	memset(h,-1,sizeof(h));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)
	scanf("%lld",&val[i]);
	for(int i=1;i<=m;i++)
	{
		add(i,i+m,val[i]);
		add(i+m,i,val[i]);
	}
	cnt=2*m;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		int lst;
		for(int j=1;j<=k;j++)
		{						
			int a;
			ll t;
			scanf("%d%lld",&a,&t);
			cnt++;
			if(j>1)
			{
				add(lst,cnt,0ll);
				add(cnt,lst,0ll);
			}
			add(cnt,a+m,t);
			add(a+m,cnt,t);
			lst=cnt;
		}
	}	
	if(c>=9&&c<=11)
	{
		for(int i=1;i<=m;i++)
		{
			dijkstra(i);
			for(int j=1;j<=cnt;j++)
			f[i][j]=dis[j];
		}
		while(Q--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%lld\n",f[u][v]);
		}
		return 0;
	}
	while(Q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		dijkstra(u);
		printf("%lld\n",dis[v]);
	}
	return 0;
} 



