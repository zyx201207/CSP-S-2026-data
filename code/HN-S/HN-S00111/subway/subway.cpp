#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,maxl=1e3+10;
int c,n,m,d,q;
int w[N],a[N],t[N];
vector<pii> g[N];
void dijkstra()
{
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({1,1});
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1,u,w;j<=k;j++)
		{
			cin>>u>>w;
			g[u].push_back({i,w});
			g[i].push_back({u,w});
		}
	}
	dijkstra();
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<x+y<<"\n";
	}
	return 0;
}
//猜一猜我会不会上湖南CSP迷惑行为大赏 
