#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5010+10;
int c,T,n;
ll dis[N],cnt[N],X[N];
bool f[N];
unsigned long long d;
vector<pair<int,ll> > a[N];
void dij(int s)
{
	vector<bool> vis(N,0);
	priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	q.push({0,s}); dis[s]=0;
	while(!q.empty())
	{
		int x=q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto Y:a[x])
		{
			int y=Y.first,w=Y.second;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				cnt[y]=cnt[x];
				f[y]=f[x];
				q.push({dis[y],y});
			}
			else if(dis[y]==dis[x]+w) 
			{
				cnt[y]++;
				if(cnt[y]==1) f[y]=1;
				else f[y]=0;
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++) cin>>X[i],a[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((unsigned long long)(X[j]-X[i])>d) continue; 
				a[i].push_back({j,1});
				a[j].push_back({i,1});
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) dis[j]=1e16,cnt[j]=f[j]=0;
			dij(i);
			for(int j=i+1;j<=n;j++) 
				if(X[j]-X[i]>d) ans+=f[j];
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
