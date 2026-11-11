//GZ-S00066 刘明远 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > cnt[500001],edge[505*505];
int dis[505*505],aid[500001];
bool vis[505*505];
int c,n,m,d,q;
int w[500005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			cnt[a].push_back({i,t});
		}
	}
	int tmp=1;
	for(int i=1;i<=m;i++)
	{
		if(cnt[i].size()>1)
		{
			for(int j=0;j<cnt[i].size();j++)
			{
				edge[n+tmp].push_back({cnt[i][j].first,cnt[i][j].second});
				edge[cnt[i][j].first].push_back({tmp+n,cnt[i][j].second});
				aid[i]=n+tmp;
			}
			tmp++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y,ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		if(cnt[x].size()==1) ans+=cnt[x][0].second,x=cnt[x][0].first;
		else x=aid[x];
		if(cnt[y].size()==1) ans+=cnt[y][0].second,y=cnt[y][0].first;
		else y=aid[y];
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		priority_queue<int,vector<pair<int,int> >,greater<pair<int,int> > > que;
		que.push({0,x});
		dis[x]=0;
		while(!que.empty())
		{
			int u=que.top().second; que.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=0;i<edge[u].size();i++)
			{
				int v=edge[u][i].first;
				if(dis[v]>dis[u]+edge[u][i].second)
				{
					dis[v]=dis[u]+edge[u][i].second;
					que.push({dis[v],v});
				}
			}
		}
		cout<<ans+dis[y]<<endl;
	}
	return 0;
}
