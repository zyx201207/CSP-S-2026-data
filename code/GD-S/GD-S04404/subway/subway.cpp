#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
struct nod
{
	int to,w;
};
struct edg
{
	int x;
	long long d;
	bool operator <(const edg &B) const
	{
		return d<B.d;
	}
};
const int MR=600005;
vector<nod> g[MR];
int n,m,w[MR];
long long dis[MR];
long long dijk(int s,int t)
{
	priority_queue<edg> pq;
	pq.push({s,0});
	for(int i=1;i<=n+m;i++) dis[i]=4e18;
	dis[s]=0;
	while(!pq.empty())
	{
		int x=pq.top().x,i;
		long long d=pq.top().d;
		pq.pop();
		if(d>dis[x]) continue;
		for(i=0;i<g[x].size();i++)
			if(d+g[x][i].w<dis[g[x][i].to])
			{
				dis[g[x][i].to]=d+g[x][i].w;
				pq.push({g[x][i].to,dis[g[x][i].to]});
			}
	}
	return dis[t];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q,i;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int a,t;
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		cout<<w[s]+dijk(s,t)+w[t]<<endl;
	}
	return 0;
}
