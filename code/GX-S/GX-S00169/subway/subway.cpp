#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500001],k,vis[2001][2001],l,r,a,t,dis[701];
long long dijkstra(long long ll,long long rr)
{
	priority_queue<pair<long long,long long>>q;
	q.push({0,ll});dis[ll]=0;
	while(!q.empty())
	{
		long long topp=q.top().second;long long val=-q.top().first;
		q.pop();
		for(long long i=1;i<=n+m;i++)
		{
		if(vis[topp][i]!=0)
		if(vis[topp][i]+val<dis[i])
		{dis[i]=val+vis[topp][i];q.push({-vis[topp][i]-val,i});}
		}
	}
	return dis[rr];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;vis[m+i][a]=t;vis[a][m+i]=t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		for(int j=1;j<=n+m;j++)
		dis[j]=1000000000000;
		cout<<dijkstra(l,r)+w[l]+w[r]<<endl;
	}
	return 0;
}
