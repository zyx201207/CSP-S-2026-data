#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
ll k,t,a[50005],dis[50005],cnt[50005],n,d,vis[50005];
queue<ll> que;
vector<ll> c[50005];
void bfs(ll now)
{
	while(!que.empty())que.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,125,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[now]=0;
	que.push(now);
	vis[now]=1;
	cnt[now]=1;
	while(!que.empty())
	{
		ll u=que.front();
		que.pop();
		//cout<<u<<" ";
		//vis[u]=1;
		if(u==0)
		{
			return ;
		}
		for(auto i : c[u])
		{
			//cout<<n<<" "<<abs(a[u]-a[i])<<'\n';
			if(dis[i]>=dis[u]+1)
			{
				dis[i]=dis[u]+1;
				cnt[i]+=cnt[u];
			}
			if(vis[i]==1)continue;
			vis[i]=1;
			que.push(i);
		}
		//vis[u]=0; 
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>k>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		ll sum=0;
		for(int i=1;i<=n;i++)c[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[j]-a[i])<=d)c[i].push_back(j),c[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			c[n].push_back(0),c[0].push_back(n);
			bfs(i);
			c[n].pop_back(),c[0].pop_back();
			for(int j=i+1;j<=n;j++)
			{
				if(cnt[j]==2)sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
