#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int M=5e3+5;
int t,n,d,x[N],dist[M],ans;
struct node
{
	int v,w;
	bool operator<(const node &other)const
	{
		return w<other.w;
	}
};
vector<node> edge[N];
void dijkstra(int s,int t)
{
	priority_queue<node> q;
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int now=q.top().v;
		q.pop();
		for(auto i:edge[now])
		{
			if(dist[now]+i.w<dist[i.v])
			{
				dist[i.v]=dist[now]+i.w;
				q.push({i.v,dist[i.v]});
			}
		}
	}
	int cnt=0;
	for(auto i:edge[t])
	{
		if(dist[i.v]+i.w==dist[t])
			cnt++;
	}
	if(cnt==2)
		ans++;
}
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i],edge[i].clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(x[i]-x[j])<=d)
				edge[i].push_back({j,1}),edge[j].push_back({i,1});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			dijkstra(i,j);
	}
	cout<<ans<<"\n";
}
int c;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    	solve();
    return 0;
}
