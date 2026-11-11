#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
int c,n,m,d,q,dist[1005][3005],book[3005],k[505],a[1005],t[1005],id[1005];
vector<int> e[3005],h[1005];
void dijkstra(int st)
{
	priority_queue <P, vector<P> ,greater <P> >q;
	memset(book,0,sizeof book);
	q.push({0,st});
	dist[st][st]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(book[u]==1)
			continue;
		book[u]=1;
		for(int i=0;i<e[u].size();i+=2)
		{
			int v=e[u][i],w=e[u][i+1];
			if(dist[st][v]>dist[st][u]+w)
			{
				dist[st][v]=dist[st][u]+w;
				q.push({dist[st][v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	int x;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		e[i].push_back(i+m);
		e[i].push_back(x);
		e[i+m].push_back(i);
		e[i+m].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
			id[j]=m*2+j+k[i-1];//zhan tai bian hao
			
			e[a[j]+m].push_back(id[j]);
			e[a[j]+m].push_back(t[j]);
			e[id[j]].push_back(a[j]+m);
			e[id[j]].push_back(t[j]);//zhangting <-> zhantai
			
			for(int p=1;p<j;p++)//zhantai <-> zhantai
			{
				e[id[p]].push_back(id[j]);
				e[id[p]].push_back(0);
				e[id[j]].push_back(id[p]);
				e[id[j]].push_back(0);
			}
		}
		k[i]=k[i]+k[i-1];
	}

	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;i++)
		dijkstra(i);
	int y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<dist[x][y]<<"\n";
	}
	return 0;
}
