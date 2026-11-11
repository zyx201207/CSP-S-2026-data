#include<bits/stdc++.h>
using namespace std;
const long long N=505,M=5e5+5;
struct data{long long v,dis,cut,line;};
long long c,n,m,d,q,k,x,y,cnt,w[M],dis[M],line[M];
bool vis[M];
vector<long long> a[N],t[N];
vector<data> G[M];
deque<long long> que;
void spfa(long long x,long long y)
{
	que.push_back(x),vis[x]=1;
	while(que.size())
	{
		long long u=que.front();
		que.pop_front(),vis[u]=0;
		for(auto ls : G[u])
		{
			long long v=ls.v,w=ls.dis,line2=ls.line;
			long long diss=dis[u]+w-(line2==line[u])*ls.cut;
			if(diss<dis[v])
			{
				dis[v]=diss,line[v]=line2;
				if(!vis[v])
				{
					if(que.size()&&dis[v]<dis[que.front()]) que.push_front(v);
					else que.push_back(v);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k),a[i].push_back(0),t[i].push_back(0);
		for(int j=1;j<=k;j++)
		{
			scanf("%lld%lld",&x,&y),a[i].push_back(x),t[i].push_back(y);
			if(j!=1)
			{
				long long dis=y+t[i][j-1];
				G[x].push_back({a[i][j-1],dis,2*y,i});
				G[a[i][j-1]].push_back({x,dis,2*t[i][j-1],i});
			}
		}
	}
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=m;i++) dis[i]=1e18,vis[i]=0;
		dis[x]=0,line[x]=-1;
		spfa(x,y);
		printf("%lld\n",dis[y]+w[x]+w[y]);
	}
	return 0;
}
