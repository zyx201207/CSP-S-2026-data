#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
int c,n,m,d,q,ki,w[500001],a[500001],t[5001][501],vis[500001],dis[500001],id=0,ui,vi,oecnt,vcnt=0,trt;
struct graph{
	int head[500021],nxt[1000041],to[1000041],wt[1000041],ecnt=0;
	void add(int u,int v,int w)
	{
		nxt[++ecnt]=head[u];head[u]=ecnt;
		to[ecnt]=v,wt[ecnt]=w;
	}
}g;
struct node{
	int u,d,rt,rch;
	bool operator<(const node &ot)const{
		return d>ot.d;
	}
};
priority_queue<node> pq;
int dij(int s,int f,int id)
{
	while(!pq.empty())pq.pop();
	int now,nowr,*wt=g.wt,*to=g.to,rch;
	memset(dis,0x3f,(vcnt+1)*sizeof(int));
	dis[s]=0,pq.push(node{s,0,0,0});
	while(!pq.empty())
	{
		now=pq.top().u,nowr=pq.top().rt,rch=pq.top().rch;
		pq.pop();
		if(now==f){
			if(rch==0){
				pq.push(node{f,dis[f]+t[f][nowr],nowr,1});
				continue;
			}
			else return nowr;
		}
		if(vis[now]==id)continue;
		vis[now]=id;
		for(int i=g.head[now];i!=0;i=g.nxt[i])
		{
			if(vis[to[i]]!=id){
				if(wt[i]==nowr)dis[to[i]]=dis[now],pq.push(node{to[i],dis[to[i]],nowr,0});
				else dis[to[i]]=dis[now]+t[now][nowr]+t[now][wt[i]],pq.push(node{to[i],dis[to[i]],wt[i],0});
			}
			if(wt[i]==nowr&&dis[now]<dis[to[i]])dis[to[i]]=dis[now],pq.push(node{to[i],dis[to[i]],nowr,0});
			else if(wt[i]!=nowr&&dis[now]+t[now][nowr]+t[now][wt[i]]<dis[to[i]])
				dis[to[i]]=dis[now]+t[now][nowr]+t[now][wt[i]],pq.push(node{to[i],dis[to[i]],wt[i],0});
		}
	}
	return -1;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",w+i);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&ki);
		for(int j=1;j<=ki;j++)scanf("%lld",a+j),scanf("%lld",&t[a[j]][i]);
		for(int j=2;j<=ki;j++)g.add(a[j-1],a[j],i),g.add(a[j],a[j-1],i);
	}
	oecnt=g.ecnt;
	while(q--)
	{
		scanf("%lld%lld",&ui,&vi);
		g.head[0]=0,g.ecnt=oecnt,vcnt=m;
		for(int i=g.head[ui];i!=0;i=g.nxt[i])g.add(0,++vcnt,g.wt[i]),g.head[vcnt]=g.head[ui],t[0][g.wt[i]]=t[ui][g.wt[i]];
		for(int i=m+1;i<=vcnt;i++)
			for(int j=g.head[i];j!=0;j=g.nxt[j])t[i][g.wt[j]]=t[ui][g.wt[j]];
		vis[ui]=id+1;
		trt=dij(0,vi,++id);
		printf("%lld\n",dis[vi]+w[ui]+w[vi]+t[vi][trt]);
	}
	return 0;
}
