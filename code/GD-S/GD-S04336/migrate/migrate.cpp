#include<bits/stdc++.h>
using namespace std;
long long a[1000]={0},vis[1000]={0},cnt[1000]={0},dist[1000]={0};
vector<long long>G[1000];
void bfs(long long s)
{
	memset(vis,0,sizeof(vis));memset(cnt,0,sizeof(cnt));memset(dist,0x3f,sizeof(dist));
	queue<long long> q;
	q.push(s);
	dist[s]=0;
	while(!q.empty())
	{
		long long u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(long long v:G[u])
		{
			if(dist[u]+1<dist[v])
			{
				cnt[v]=0;
				dist[v]=dist[u]+1;
				q.push(v);
			}
			if(dist[u]+1==dist[v])
			{
				cnt[v]++;
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		for(long long i=0;i<1000;i++) G[i].clear();
		long long n,d,ans=0;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					G[i].push_back(j);
				} 
			}
		}
		for(long long i=1;i<=n;i++)
		{
			bfs(i);
			for(long long j=1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
