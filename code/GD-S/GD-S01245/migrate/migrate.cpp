#include<bits/stdc++.h>
#define PII pair<long long,long>
using namespace std;
int c,T,n,d;
const long long N=307;
long long h[N],w[N*N],ne[N*N],idx,e[N*N];
long long cnt[N];
void add(long long u,long long v)
{
	e[idx]=v;
	ne[idx]=h[u];
	h[u]=idx++;
}
long long a[2000007],bz[N],dis[N];
const long long INF=1e18+7;
void dijkstra(long long s)
{
	cnt[s]=1;
	for(long long i=1;i<=n;i++)
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
		long long x=now.second;
		if(bz[x])
		continue;
		bz[x]=1;
		for(long long i=h[x];i!=-1;i=ne[i])
		{
			long long j=e[i];
			if(dis[j]>1+dis[x])
			{
				cnt[j]=cnt[x];
				dis[j]=dis[x]+1;
				q.push({dis[j],j});
			}
			else if(dis[j]==dis[x]+1)
			cnt[j]=cnt[j]+cnt[x];
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	memset(h,-1,sizeof(h));
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		memset(h,-1,sizeof(h));
		idx=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				if(i!=j)
				{
					if(abs(a[i]-a[j])<=d)
					add(i,j);
				}
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			memset(cnt,0,sizeof(cnt));
			dijkstra(i);
			for(long long j=1;j<=n;j++)
			{
				if(cnt[j]==2)
				{
					ans++;
				}
				
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
} 



