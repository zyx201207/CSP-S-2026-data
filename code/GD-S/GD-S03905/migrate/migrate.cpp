#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+6;
int c,t; 
int n,k;
int w[N];
struct edge{
	int v,w;
};
vector <edge> e[N];
int cnt[N];
int d[N];
int vis[N];
void dij(int s)
{
	priority_queue<pair<int,int> > q;
	for (int i=1;i<=n;i++)d[i]=INT_MAX,vis[i]=0;
	q.push({0,s});
	d[s]=0;
	while(q.size())
	{
		int u=q.top().second;
		q.pop();
		if (vis[u])continue;
		vis[u]=1;
		for (auto ed:e[u])
		{
			int v=ed.v,w=ed.w;
			if (d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				cnt[v]=1;
				q.push({-d[v],v});
			}
			else if (d[v]==d[u]+w)
			{
				cnt[v]++;
				
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		
		cin>>n>>k;
		for (int i=1;i<=n;i++)
		{
			cnt[i]=0;
			e[i].clear();
			w[i]=0;
		}
		for (int i=1;i<=n;i++)cin>>w[i];
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (w[j]-w[i]>k)break;
				e[i].push_back({j,1});
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)cnt[j]=0;
			dij(i);
			for (int j=i+1;j<=n;j++)
			{
				if (cnt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

