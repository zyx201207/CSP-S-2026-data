#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,dis[10010][10010],w[510],vis[10010],t,k[500010];
vector <pair<int,int> > a[10010];
struct question
{
	int l,r;
}r[100010];
void dijs(int s)
{
	priority_queue <pair<int,int> > que;
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	que.push({0,s});
	while(!que.empty())
	{
		int u=que.top().second;
//		cout<<"**"<<u<<endl;
		que.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(int i=0;i<a[u].size();i++)
		{
			int v=a[u][i].first;
			if(dis[s][v]>dis[s][u]+a[u][i].second)
			{
//				cout<<v<<"!!"<<dis[v]<<" "<<a[u][i].second+dis[u]<<endl;
				dis[v][s]=dis[s][v]=dis[s][u]+a[u][i].second;
				que.push({-dis[s][v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)	cin>>w[i];
//	for(int i=1;i<=n;i++)
//		for(int j=i+1;j<=n;j++)
//			dis[i][j]=dis[j][i]=inf;
	t=n;
	for(int i=1;i<=m;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			a[++t].push_back({x,y});
			a[x].push_back({t,y});
			if(j!=1)
			{
				a[t].push_back({t-1,0});
				a[t-1].push_back({t,0});
			}
		}
	}
	for(int i=1;i<=q;i++)
		cin>>r[i].l>>r[i].r;
	for(int i=1;i<=q;i++)
	{
//		cout<<"###"<<i<<endl;
//		if(dis[r[i].l][r[i].r]<inf)
//			cout<<dis[r[i].l][r[i].r]+w[r[i].l]+w[r[i].r]<<endl;
//		else
//		{
			dijs(r[i].l);
			cout<<dis[r[i].l][r[i].r]+w[r[i].l]+w[r[i].r]<<endl;
//		}
	}
//	for(int i=1;i<=t;i++)
//		cout<<i<<" "<<dis[i]<<endl;
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
0 3 5 20 1
5 2 4 1 3
3 1 2 3 6 5 1
3 5 3 2 1 4 6
3 1 2 5 4 4 6
1 2*/
