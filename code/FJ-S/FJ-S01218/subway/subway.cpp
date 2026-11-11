#include<bits/stdc++.h>
using namespace std;
#define int long long
int testid,n,m,stamax,ques,th[500010],dis[510],e[510][510];
bool via[500010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<pair<int,int> > v[500010];
void add(int u,int v,int w)
{
	e[u][v]=min(e[u][v],w);
}
void dij(int s)
{
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(via[x]) continue;
		via[x]=1;
		for(int i=1;i<=n;i++)
		{
			if(e[x][i]==0x3f3f3f3f3f3f3f3f) continue;
			int w=e[x][i];
			if(dis[i]>dis[x]+w) dis[i]=dis[x]+w,q.push({dis[i],i});
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	memset(dis,0x3f3f,sizeof(dis));
	memset(e,0x3f3f,sizeof(e));
	cin>>testid>>n>>m>>stamax>>ques;
	for(int i=1;i<=m;i++) cin>>th[i];
	for(int i=1;i<=n;i++)
	{
		int k,q;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,b;
			cin>>a>>b;
			v[a].push_back({i,b});
		}
	}
	for(int k=1;k<=m;k++)
	{
		int siz=v[k].size();
		for(int i=0;i<siz;i++)
		{
			for(int j=i+1;j<siz;j++)
			{
				add(v[k][i].first,v[k][j].first,v[k][i].second+v[k][j].second);
				add(v[k][j].first,v[k][i].first,v[k][j].second+v[k][i].second);
			}
		}
	}
	dij(1);
	for(int k=1;k<=ques;k++)
	{
		int x,y,ans=LLONG_MAX;
		cin>>x>>y;
		for(pair<int,int> i:v[x])
		{
			for(pair<int,int> j:v[y])
			{
				ans=min(ans,abs(dis[i.first]-dis[j.first])+th[x]+th[y]+i.second+j.second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
