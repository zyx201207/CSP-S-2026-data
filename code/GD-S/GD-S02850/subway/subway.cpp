#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=2e3+10;
const int M=500+10;
int c,n,m,d,q,st,ed,x[N],w[N],psz;
vector<pii> e[N];
bool vis[N*M];
long long dis[N*M];

void dij()
{
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,st});
	for(int i=1;i<=psz;i++) dis[i]=1e18;
	memset(vis,0,sizeof vis);
	dis[st]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(pii tmp:e[u]) 
		{
			int v=tmp.first;
			int w=tmp.second;
			if(d+w<dis[v])
			{
				dis[v]=w+d;;
				q.push({dis[v],v});
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	psz=n;
	for(int k,t,i=1;i<=m;i++)
	{
		cin>>k;
		cin>>x[1]>>t;
		psz++;
		e[x[1]].push_back({psz,t});
		e[psz].push_back({x[1],t});
		x[1]=psz;
		for(int j=2;j<=k;j++)
		{
			cin>>x[j]>>t;
			++psz;
			e[x[j]].push_back({psz,t});
			e[psz].push_back({x[j],t});
			x[j]=psz;
			e[x[j]].push_back({x[j-1],0});
			e[x[j-1]].push_back({x[j],0});
		}
	}
	while(q--)
	{
		cin>>st>>ed;
		dij();
		cout<<dis[ed]+w[st]+w[ed]<<'\n';
//		for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
//		cout<<'\n';
	}
	return 0;
}
