#include<bits/stdc++.h>
#define u first
#define w second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pli=pair<ll,int>;
const int N=1005,M=505;
const ll inf=1e18;
int t,n,m,k,qry,x,a[N],u[N],w[N];
ll dis,d[N][N];
vector<pii>g[N];
priority_queue<pli,vector<pli>,greater<pli>>q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t>>m>>n>>k>>qry;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(m--)
	{
		cin>>x;
		for(int i=0;i<x;i++)
		{
			cin>>u[i]>>w[i];
			for(int j=0;j<i;j++)
			{
				g[u[i]].push_back({u[j],w[i]+w[j]});
				g[u[j]].push_back({u[i],w[i]+w[j]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		fill(d[i]+1,d[i]+n+1,inf);
		q.push({d[i][i]=0,i});
		while(q.size())
		{
			dis=q.top().first;
			int u=q.top().second;
			q.pop();
			if(dis>d[i][u])continue;
			for(pii e:g[u])
			{
				int v=e.first,w=e.second;
				if(d[i][v]>dis+w)
					q.push({d[i][v]=dis+w,v});
			}
		}
	}
	while(qry--)
	{
		int u,v;
		cin>>u>>v;
		cout<<a[u]+d[u][v]+a[v]<<'\n';
	}
	return 0;
}