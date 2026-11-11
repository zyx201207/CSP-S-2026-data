#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int c,n,m,d,Q;
int w[N];
vector<pair<int,int> >l[N]; 
int dis[N],vis[N];
priority_queue<pair<int,int> >q;
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto i:l[x])
		{
			int y=i.first,w=i.second;
			if(dis[y]>dis[x]+w) 
			{
				dis[y]=dis[x]+w;
				q.push({-dis[y],y});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int last,now,v;
		if(k>=1) 
		{
			cin>>last>>v;
			l[(i-1)*m+last].push_back({n*m+last,v});
			l[n*m+last].push_back({(i-1)*m+last,v});
		}
		for(int j=2;j<=k;j++)
		{
			cin>>now>>v;
			l[(i-1)*m+last].push_back({(i-1)*m+now,0});
			l[(i-1)*m+now].push_back({(i-1)*m+last,0});
			l[(i-1)*m+now].push_back({n*m+now,v});
			l[n*m+now].push_back({(i-1)*m+now,v});
			last=now;
		}
	}
	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		dij(n*m+x);
		cout<<dis[n*m+y]+w[x]+w[y]<<endl;
	}
	return 0;
}
