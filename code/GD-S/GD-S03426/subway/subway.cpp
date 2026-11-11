#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
int c,n,m,d,qe;
const int N=5e6+5,M=9e6+5,INF=0x3f3f3f3f3f3f3f3f;
int head[N],to[2*M],nxt[2*M],val[2*M],cnt=1;
void add(int x,int y,int v)
{
	to[cnt]=y;
	nxt[cnt]=head[x];
	val[cnt]=v;
	head[x]=cnt++; 
}
map<pair<int,int>,int>ask;
map<int,int>dis,vis,use;
vector<int>a[N];
int w[N];
int bh[M];
int out[N];
pair<int,int>zhan[N],ques[N];
int ans[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qe;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=3*n;i++)bh[i]=i;
	for(int i=1;i<=n;i++)
	{
		add(bh[i],bh[i+n],w[i]);
		add(bh[i+n],bh[i],w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		sacnf("%lld",&k);
		int lst=0;
		for(int j=1;j<=k;j++)
		{
			int x,t;
			sacnf("%lld%lld",&x,&t);
			add(bh[x+n],bh[x+2*n],t);
			add(bh[x+2*n],bh[x+n],t);
			if(lst!=0)
			{
				add(bh[x+n],bh[lst+2*n],0);
				add(bh[lst+n],bh[x+2*n],0);
			}
			lst=x;
		}
	}
	for(int i=1;i<=qe;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		ques[i]={x,y};
		ask[{x,y}]=i;
		ask[{y,x}]=i;
	}
	for(int i=1;i<=n;i++)
	{
		priority_queue<PII,vector<PII>,greater<PII> >q;
		dis.clear();
		vis.clear();
		dis[bh[i]]=0;
		q.push({0,bh[i]});
		vis[bh[i]]=1;
		while(!q.empty())
		{
			int x=q.top().first;
			vis[x]=1;
			q.pop();
			for(int i=head[x];i;i=nxt[i]) 
			{
				int y=to[i];
				if(vis[y])continue;
				if(use[y]==0)dis[y]=INF;
				use[y]=1;
				if(dis[y]>dis[x]+val[i])
				{
					dis[y]=dis[x]+val[i];
					q.push({dis[y],0});
					if((1<=ask[{x%n,y%n}]<=qe)||(1<=ask[{y%n,x%n}]<=qe))
					{
						ans[ask[{x%n,y%n}]]=ans[ask[{y%n,x%n}]]=dis[y];
					}
				}
			}
		}
	}
	for(int i=1;i<=qe;i++)cout<<ans[ask[ques[i]]]<<endl;
}
