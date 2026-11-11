#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=20004,N=505;
int n,m,c,d,q;
int dis[M];
bool vis[M];
int kk[N];
int arr[N][M];
int t[N][M];
int dijige[M][N];
vector<int> tong[M];
int w[M];
vector<pair<int,int> >Link[M];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>kk[i];
		for(int j=1;j<=kk[i];j++)
		{
			cin>>arr[i][j]>>t[i][j];
			dijige[arr[i][j]][i]=j;
			tong[arr[i][j]].push_back(i);//lai zi i
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(tong[i].size()>1)
		{
			for(int j=0;j<tong[i].size();j++)
			{
				for(int k=j+1;k<tong[i].size();k++)
				{
					int x=tong[i][j],y=tong[i][k];
					int val=t[x][dijige[i][x]]+t[y][dijige[i][y]];
					for(int a=1;a<=kk[x];a++)
					{
						for(int b=a+1;b<=kk[y];b++)
						{
							int u=arr[x][a],v=arr[y][b];
							Link[u].push_back({v,val});
							Link[v].push_back({u,val});
						}
					}
				}
			}
		}
	}
	while(q--)
	{
		int ta,tb;
		cin>>ta>>tb;
		for(int i=1;i<=m;i++) dis[i]=1e18;
		for(int i=1;i<=m;i++) vis[i]=0;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
		pq.push({0,ta});
		dis[ta]=0;
		while(!pq.empty())
		{
			int now=pq.top().second;
			pq.pop();
			if(vis[now]) continue;
			vis[now]=1;
			for(int i=0;i<Link[now].size();i++)
			{
				int nxt=Link[now][i].first,val=Link[now][i].second;
				if(dis[nxt]>dis[now]+val)
				{
					dis[nxt]=dis[now]+val;
					pq.push({dis[nxt],nxt});
				}
			}
		}
		int ans=dis[tb]+w[ta]+w[tb]+t[1][1]+t[1][1];
		cout<<ans<<endl;
	}
	
	return 0;
}
