#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5+5;
const long long eof=0x3f3f3f3f3f3f3f3f;
long long c,n,m,d,q;
long long w[M];
struct node{
	long long s,t;
};
vector <node> sub[M];
long long a[505][505];
long long dis[505][505];
bool book[505];
void dikjstra(int k)
{
	priority_queue < pair<long long,int>,vector< pair<long long,int> >,greater< pair<long long,int> > > pq;
	dis[k][k]=0;
	pq.push(make_pair(dis[k][k],k));
	while(!pq.empty())
	{
		pair <int,int> now=pq.top();
		pq.pop();book[now.second]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[now.second][i]==eof) continue;
			if(dis[k][i]>dis[k][now.second]+a[now.second][i])
			{
				dis[k][i]=dis[k][now.second]+a[now.second][i];
				if(book[i]==0){
					pq.push(make_pair(dis[k][i],i));
					book[i]=1;
				}
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=n;i++)
	{	
		long long k,s,t;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%lld%lld",&s,&t);
			int len=sub[s].size();
			for(int l=0;l<len;l++)
				if(a[i][sub[s][l].s-n]>sub[s][l].t+t)
					a[i][sub[s][l].s-n]=a[sub[s][l].s-n][i]=sub[s][l].t+t;
			sub[s].push_back({n+i,t});//jian tu
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof book);
		dikjstra(i);
	}
	while(q--)//qiu ans
	{
		long long ans=eof;
		long long s,e;
		scanf("%lld%lld",&s,&e);
		for(int i=0;i<(int)sub[s].size();i++)
			for(int j=0;j<(int)sub[e].size();j++)
				ans=min(ans,w[s]+w[e]+sub[s][i].t+sub[e][j].t+dis[sub[s][i].s-n][sub[e][j].s-n]);
		printf("%lld\n",ans);
	}
	return 0;
}
