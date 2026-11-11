#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
int t;
int n;
ll d;
ll a[N];
int cnt[N];
int dis[N];
bool vis[N];
ll ans;
void dij(int s)
{
	priority_queue<ll,vector<pair<ll,int>>,greater<pair<ll,int> > >q;
	for(int i=1;i<=n;i++)dis[i]=1e9,cnt[i]=0,vis[i]=0;
	dis[s]=0,cnt[s]=1;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=x+1;i<=n&&a[i]-a[x]<=d;i++)
		{
			if(dis[i]>dis[x]+1)
			{
				dis[i]=dis[x]+1,cnt[i]=cnt[x];
				q.push(make_pair(dis[i],i));
			}
			else if(dis[i]==dis[x]+1)cnt[i]+=cnt[x];
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	scanf("%d%d",&c,&t);
	if(c>=11&&c<=12)
	{
		while(t--)
		{
			ans=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
			int k=a[2]-a[1];
			ll p=d/k;
			if(p*2-1<=n&&p>=2&&d<n)ans=n-p*2+1;
			else ans=0;
			printf("%lld\n",ans);
		}
	}
	else
	{
		while(t--)
		{
			ans=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
			for(int i=1;i<n;i++)
			{
				dij(i);
				for(int j=i+1;j<=n;j++)ans+=(cnt[j]==2);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
