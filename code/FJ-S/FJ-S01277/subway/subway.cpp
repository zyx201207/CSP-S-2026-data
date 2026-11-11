#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int _=5e5+5;
struct hp{
	ll zu[21][2];
	int cnt=0;
}qwq[_];
ll c,n,m,d,r,w[_],dis[505],mapp[505][505],awa[505][505];
void solve(int x,int y)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++) awa[i][j]=mapp[i][j];
	}
	//起点判定加改边
	for(int i=1;i<=qwq[x].cnt;i++)
	{
		int k=qwq[x].zu[i][0];
		awa[0][k]=qwq[x].zu[i][1];
	}
	//dj
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({dis[0],0});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(int i=0;i<=n;i++)
		{
			if(dis[i]>dis[u]+awa[u][i])
			{
				dis[i]=dis[u]+awa[u][i];
				q.push({dis[i],i});
			}
		}
	}
	ll minn=0x3f3f3f3f;
	for(int i=1;i<=qwq[y].cnt;i++)
	{
		minn=min(dis[qwq[y].zu[i][0]]+qwq[y].zu[i][1],minn);
	}
	cout<<minn+w[x]+w[y]<<endl;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mapp,0x3f,sizeof(mapp));
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			qwq[a].zu[++qwq[a].cnt][0]=i;
			qwq[a].zu[qwq[a].cnt][1]=t;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=qwq[i].cnt;j++)
		{
			for(int k=1;k<j;k++)
			{
				ll u=qwq[i].zu[j][0],v=qwq[i].zu[k][0],su=qwq[i].zu[j][1],sv=qwq[i].zu[k][1];
				mapp[u][v]=min(mapp[u][v],su+sv);
				mapp[v][u]=min(mapp[v][u],su+sv);
			}
		}
	}//建图 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(mapp[i][j]>=0x3f3f3f3f)
//			{
//				cout<<"-1 ";
//			}
//			else cout<<mapp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=r;i++)
	{
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}
