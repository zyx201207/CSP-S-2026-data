#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
typedef pair<ll,ll> PII;
ll c,t,a[N],cnt[N],dis[N],vis[N],mark[N];
vector<ll> v[N];
void dij(ll start)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(mark,0,sizeof mark);
	priority_queue<PII,vector<PII>,greater<PII> > q;
	dis[start]=0;
	q.push({dis[start],start});
	while(!q.empty())
	{
		PII p=q.top();
		ll px=p.second;
		q.pop();
		if(vis[px])
		{
			continue;
		}
		vis[px]=1;
		for(int i=0;i<v[px].size();i++)
		{
			ll tx=v[px][i];
			if(dis[tx]>dis[px]+1)
			{
				dis[tx]=dis[px]+1;
				mark[tx]=0;
				q.push({dis[tx],tx});
			}
			else if(dis[tx]==dis[px]+1 && mark[tx]==0)
			{
				mark[tx]=1;
			}
			else if(dis[tx]==dis[px]+1)
			{
				mark[tx]=2;
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ll n,d,spc,ans=0,b=1,maxcnt=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			memset(cnt,0,sizeof cnt);
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-a[j]>=d)
				{
					v[i].push_back(j);
					v[j].push_back(i);
					cnt[i]++;
					cnt[j]++;
					maxcnt=max(maxcnt,max(cnt[i],cnt[j]));
				}
			}
			if(i==2)
			{
				spc=a[2]-a[1];
			}
			if(i>2 && a[i]-a[i-1]!=spc)
			{
				b=0;
			}
		}
		if(maxcnt==n-1)
		{
			printf("%lld\n",0);
			continue;
		}
		if(b)
		{
			if(d<spc*2)
			{
				cout<<0<<"\n";
				continue;
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=i+d+1;j<=n;j++)
					{
						if((j-i)%d!=0 && j-i>d)
						{
							ans++;
						}
					}
				}
				printf("%lld\n",ans);
				continue;
			}
		}
		for(int i=1;i<n;i++)
		{
			dij(i);
			for(int j=i+1;j<=n;j++)
			{
				if(mark[j]==1)
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
