#include<bits/stdc++.h>
using namespace std;
#define int long long // <------------------------
int TTTQQQTTT;
int n,m,d,T;
int a[500001];
struct node
{
	int v,w;
};
vector<node> p[500001*20];
int dis[500001*20];
bool vis[500001*20];
int cnt;
int s;
const int inf=1e15;
void dij()
{
	for(int i=1;i<=cnt;i++)
	{
		vis[i]=0;
		dis[i]=inf;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
	while(!q.empty()) q.pop();
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int x=q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(node xx:p[x])
		{
			int v=xx.v;
			int w=xx.w;
			if(dis[v]>dis[x]+w)
			{
				dis[v]=dis[x]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>TTTQQQTTT>>m>>n>>d>>T;
	cnt=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int l; cin>>l;
		int lst=0;
		for(int j=1;j<=l;j++)
		{
			int x,w; cin>>x>>w;
			cnt++;
			p[x].push_back({cnt,w});
			p[cnt].push_back({x,w});
			//cout<<x<<" <-"<<w<<"->"<<cnt<<endl;
			if(lst!=0)
			{
				p[cnt].push_back({lst,0});
				p[lst].push_back({cnt,0});
				//cout<<cnt<<" <-"<<0<<"->"<<lst<<endl;
			}
			lst=cnt;
		}
	}
	for(int i=1;i<=T;i++)
	{
		int u,v; cin>>u>>v;
		s=u; dij();
		cout<<dis[v]+a[u]+a[v]<<'\n';
	}
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/
