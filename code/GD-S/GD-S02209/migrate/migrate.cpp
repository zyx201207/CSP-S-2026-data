#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;
const int maxn=5010;
int c,t;
int n,d;
vector<pll> v[maxn];
int dist[maxn],a[maxn],w1[maxn],ans;
bool vis[maxn];
void dijkstra(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	memset(w1,0,sizeof(w1));
	dist[s]=0;
	priority_queue<pll,vector<pll>,greater<pll>> q;
	q.push({0,s});
	while(!q.empty())
	{
		auto it1=q.top();
		q.pop();
		int t=it1.second;
		if(vis[t]) continue;
		vis[t]=true;
		for(auto it:v[t])
		{
			int j=it.first,w=it.second;
			if(dist[j]>dist[t]+w)
			{
				dist[j]=dist[t]+w;
				q.push({dist[j],j});
				w1[j]=1;
			}
			else if(dist[j]=dist[t]+w)
			{
				w1[j]++;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			v[i].clear();
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d) v[i].push_back({j,1});
		for(int i=1;i<n;i++)
		{
			dijkstra(i);
			for(int j=i+3;j<=n;j++)
				if(w1[j]==2)
				{
					ans++;
				}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
