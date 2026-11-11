#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,testid,n,d,p[2000010],tot,h[2000010],dis[2000010],cnt[2000010];
bool via[2000010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
struct edge
{
	int to,ne;
}e[50000010];
void add(int u,int v)
{
	e[++tot]={v,h[u]};
	h[u]=tot;
}
void dij(int s)
{
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second,w=q.top().first;
		q.pop();
		if(via[u])
		{
			if(w==dis[u]) cnt[u]++;
			continue;
		}
		via[u]=1;
		for(int i=h[u];i;i=e[i].ne)
		{
			int t=e[i].to;
			if(dis[t]>=dis[u]+1) dis[t]=dis[u]+1,q.push({dis[t],t});
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>testid>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>p[i];
		memset(h,0,sizeof(h));
		tot=0;
		if(n<=5000)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(p[j]-p[i]<=d) add(i,j),add(j,i);
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				memset(dis,0x3f,sizeof(dis));
				memset(cnt,0,sizeof(cnt));
				memset(via,0,sizeof(via));
				dij(i);
				for(int j=i+1;j<=n;j++)
				{
					if(cnt[j]==1) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
