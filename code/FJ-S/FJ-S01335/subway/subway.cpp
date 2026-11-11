#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
struct node{int v;long long p;};
int c,n,m,d,q;
int w[M],k[N],cnt[M];
vector<int>a[N];
vector<long long>t[N];
long long dis[1005][1005],s[M][2];
vector<int>mp[M];
long long bfs(int x,int y)
{
	queue<pair<int,int> >q;
	int vis[M]={0},ans;
	vis[x]=1;
	q.push(make_pair(x,0));
	while(!q.empty())
	{
		int u=q.front().first;
		int s=q.front().second;
		q.pop();
		if(u==y){ans=s;break;}
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			if(vis[v])continue;
			vis[v]=1;
			q.push(make_pair(v,s+1));
		}
	}
	return ans*2*t[1][1]+w[x]+w[y];
}
void solve1()
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==j)dis[i][j]=0;
			else dis[i][j]=1e15;
		}
	for(int i=1;i<=n;i++)
	{
		for(int x=1;x<=k[i];x++)
			for(int y=x+1;y<=k[i];y++)
			{
				int u=a[i][x],v=a[i][y];
				dis[u][v]=min(dis[u][v],t[i][x]+t[i][y]);
				dis[v][u]=min(dis[v][u],t[i][x]+t[i][y]);
			}
	}
	for(int l=1;l<=m;l++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	while(q--)
	{
		int x,y;cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		for(int x=1;x<=k[i];x++)
			for(int y=1;y<=k[i];y++)
			{
				if(x==y)continue;
				int u=a[i][x],v=a[i][y];
				mp[u].push_back(v);
				mp[v].push_back(u); 
			}
	}
	while(q--)
	{
		int x,y;cin>>x>>y;
		cout<<bfs(x,y)<<"\n";
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1,A,V;j<=k[i];j++)
		{
			cin>>A>>V;
			a[i].push_back(A);
			t[i].push_back(V);
		}
	}
	if(c<=11||c>=20)solve1();
	else solve2();
	return 0;
}

