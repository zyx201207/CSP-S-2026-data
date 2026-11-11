#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=2005,K=1e5+5;
int c,n,m,d,Q;
int W[M];
int l[N];
vector<int>a[N],t[N];
ll T[N][M];
vector<int>b[N];
struct node{
	int to,p;
	ll w;
};
vector<node>g[M*2];
struct Ask{
	int x,y,id;
}R[K];
bool cmp(Ask x,Ask y)
{
	return x.x<y.x;
}
ll Ans[K];
int now;
bool vis[M*2][N];ll dis[M*2][N];
struct Node{
	ll dis;int i,p;
	bool operator<(const Node tmp)const{
		return dis>tmp.dis;
	}
};
priority_queue<Node>q;
void dij(int s)
{
	while(!q.empty())q.pop();
	for(int i=1;i<=m*2;++i)
	{
		for(int j=0;j<int(b[i].size());++j)
		{
			int k=b[i][j];
			vis[i][k]=0,dis[i][k]=1e18;
		}
	}
	dis[s][0]=0;q.push({0,s,0});
	while(!q.empty())
	{
		int u=q.top().i,p=q.top().p;q.pop();
		if(vis[u][p])continue;
		vis[u][p]=1;
		for(node x:g[u])
		{
			int v=x.to;ll w=x.w;
			int y=x.p;
			if(v==u+m&&u<=m)
			{
				if(y==p)
				{
					if(dis[v][0]>dis[u][p]+w)
					{
						dis[v][0]=dis[u][p]+w;
						q.push({dis[v][0],v,0});
					}
				}
				continue;
			}
			if(p!=y&&u<=m&&v<=m)w+=(ll)T[p][u]+T[y][u];
			if(dis[v][y]>dis[u][p]+w)
			{
				dis[v][y]=dis[u][p]+w;
				q.push({dis[v][y],v,y});
			}
		}
	}
	for(int i=now;i<=Q;++i)
	{
		if(R[i].x!=s-m){now=i;return;}
		Ans[R[i].id]=dis[R[i].y+m][0]+W[s-m]+W[R[i].y];
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;++i)
	{
		cin>>W[i];b[i+m].push_back(0);
	}
	for(int i=1;i<=n;++i)
	{
		cin>>l[i];
		for(int j=1;j<=l[i];++j)
		{
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			b[x].push_back(i);
			T[i][x]=y;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<l[i];++j)
		{
			int x=a[i][j],y=t[i][j];
			if(j!=0)g[a[i][j-1]].push_back({x,i,0});
			if(j!=l[i]-1)g[a[i][j+1]].push_back({x,i,0});
			g[x].push_back({x+m,i,y});g[x+m].push_back({x,i,y});
		}
	}
	for(int i=1;i<=Q;++i)
	{
		int x,y;
		cin>>x>>y;
		R[i]={x,y,i};
	}
	sort(R+1,R+1+Q,cmp);
	now=1;
	for(int i=1;i<=m;++i)
	{
		if(R[now].x!=i)continue;
		dij(i+m);
		if(now>Q)break;
	}
	for(int i=1;i<=Q;++i)cout<<Ans[i]<<"\n";
}
