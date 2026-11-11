#include <bits/stdc++.h>
using namespace std;
const int M=500005;
const int N=505;
int dis[M];
int c,n,m,d,r;
int w[M];
int x,y,aa,tt;
vector<vector<pair<int,int> > > e;
void bfs(int f)
{
	queue<int> q;
	q.push(f);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].first;
			if(v!=y)
			{
				if(dis[u]+2*e[u][v].second<dis[v])
				{
					dis[v]=dis[u]+2*e[u][v].second;
					q.push(e[u][i].first);
				}
			}
			else if(dis[u]+e[u][v].second<dis[v])
			{
				dis[v]=dis[u]+e[u][v].second;
				q.push(e[u][i].first);
			}
		}
	}
}
int main()
{
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin>>c>>n>>m>>d>>r;
	e.resize(m+5);
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
//	cout<<endl<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
//			cout<<i<<" "<<j<<endl;
			cin>>aa>>tt;
			e[i].push_back({aa,tt});
			e[aa].push_back({i,tt});
		}
	}
//	cout<<"fdsdfa";
	for(int k=1;k<=r;k++)
	{
		cin>>x>>y;
		for(int j=1;j<=m;j++)
		{
			dis[j]=0x3f3f3f3f;
		}
		dis[x]=0;
		bfs(x);
		cout<<dis[y]+w[x]+w[y]<<endl; // 
	}
	return 0;
}
