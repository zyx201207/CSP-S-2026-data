#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;
const int maxn=1600;
vector<pll> v[maxn];
int c,n,m,d,q;
int dist[maxn][maxn],w1[maxn];
bool vis[maxn][maxn];
void dijkstra(int s)
{
	dist[s][s]=0;
	priority_queue<pll,vector<pll>,greater<pll>> q;
	q.push({0,s});
	while(!q.empty())
	{
		auto it1=q.top();
		q.pop();
		int t=it1.second;
		if(vis[s][t]) continue;
		vis[s][t]=true;
		for(auto it:v[t])
		{
			int j=it.first,w=it.second;
			if(dist[s][j]>dist[s][t]+w)
			{
				dist[s][j]=dist[s][t]+w;
				q.push({dist[s][j],j});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w1[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			v[m+i].push_back({a,t});
			v[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=m;i++) dijkstra(i);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<dist[l][r]+w1[l]+w1[r]<<'\n';
	}
	return 0;
} 
