#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,n,m,d,q,w[500005],dis[505][500505];
vector<pair<int,int> >e[500505];
void dij(int s)
{
	for(int i=1;i<=m+n;i++)
	{
		dis[s][i]=INT_MAX;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,m+s});
	dis[s][m+s]=0;
	while(!q.empty())
	{
		int u=q.top().second,dd=q.top().first;
		q.pop();
		if(dd>dis[s][u])continue;
		for(int i=0;i<(int)(e[u].size());i++)
		{
			int v=e[u][i].first,ww=e[u][i].second;
			if(dis[s][v]>dis[s][u]+ww)
			{
				dis[s][v]=dis[s][u]+ww;
				q.push({dis[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%d%d",&a,&t);
			e[m+i].push_back({a,t});
			e[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r)
		{
			printf("0\n");
		}
		else
		{
			int minn=INT_MAX;
			for(int i=0;i<(int)(e[l].size());i++)
			{
				int v=e[l][i].first-m;
				minn=min(minn,dis[v][l]+dis[v][r]);
			}
			printf("%d\n",minn+w[l]+w[r]);
		}
	}
	
	return 0;
}
