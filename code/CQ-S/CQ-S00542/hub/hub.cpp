#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3000+5;
int c,T,n,k,ans,d[N],dis[N][N];
bool vis[N];
vector<int>e[N];
void bfs(int s)
{
	for(int i=1;i<=n;i++)vis[i]=0;
	queue<int>q;q.push(s),dis[s][s]=0,vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])if(!vis[v])dis[s][v]=dis[s][u]+1,q.push(v),vis[v]=1;
	}
}
void solve()
{
	cin>>n>>k,ans=1e9;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1,x,y;i<n;i++)cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	for(int i=1;i<=n;i++)bfs(i);
	for(int S=0;S<(1<<n);S++)if(__builtin_popcount(S)==k)
	{
		int mm=0,mx=0;
		for(int i=1;i<=n;i++)if((S>>(i-1))&1)for(int j:e[i])if((S>>(j-1))&1)mm++;
		if(mm<k-2)continue;
		for(int i=1;i<=n;i++)
		{
			int mn=1e9;
			for(int j=1;j<=n;j++)if((S>>(j-1))&1)mn=min(mn,dis[i][j]);
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
	}cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;while(T--)solve();
	return 0;
}
