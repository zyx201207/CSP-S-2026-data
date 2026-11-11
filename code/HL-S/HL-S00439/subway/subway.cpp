#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+10;
vector<pair<int,int> >g[N];
int c,n,m,d,q,md[N],a[N],sta[N],b[N];
void dijkstra(int s)
{
	fill(md,md+N,INT_MAX);
	md[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		pair<int,int> cur=pq.top();
		pq.pop();
		int w=cur.first,v=cur.second;
		if(md[v]!=w)
		{
			continue;
		}
		for(auto it:g[v])
		{
			int w1=it.first,v1=it.second;
			if(md[v1]>w+w1)
			{
				md[v1]=w+w1;
				pq.push({w+w1,v1});
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
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		memset(sta,0,sizeof sta);
		memset(b,0,sizeof b);
		for(int j=1;j<=k;j++)
		{
			int sum,t;
			cin>>sum>>t;
			sta[sum]=t;
			b[j]=sum;
		}
		for(int j=1;j<=k;j++)
		{
			for(int j1=1;j1<=k;j1++)
			{
				g[b[j]].push_back({sta[b[j]]+sta[b[j1]],b[j1]});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<md[y]+a[x]+a[y]<<"\n";
	}
	return 0;
}