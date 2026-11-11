#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII=pair<int,int>;
int dis[500005];
bool st[500005];
int n,m,c,d,q;
int s,t;
vector<PII>g[500005];
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof dis);
	memset(st,-1,sizeof st);
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII>>q;
	q.push({s,0});
	while(q.size())
	{
		PII x=q.top(); q.pop();
		for(auto u:g[x.first])
		{
			int y=u.to,z=u.val;
			if(st[y]) continue;
			if(x.val>u.val+g[y].second)
			{
				x.val=u.val+g[y].second;
				q.push(u);
			}
		}
	}
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back({i,b});
		g[b].push_back({i,a});
	}
	for(int i=1;i<=n;i++)
	{
		int k;
	}
    return 0;
}
