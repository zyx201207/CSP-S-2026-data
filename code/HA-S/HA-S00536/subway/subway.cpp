#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=510,M=5e5+10,INF=1e18+10;
int n,m,q,w[M],dis[N][N],s[N];
vector<int>a[N],t[N];
struct node
{
	int to,val;
};
vector<node>g[M],e[N];
void dist(int st)
{
	memset(s,0,sizeof s);
	dis[st][st]=0;
	priority_queue<PII,vector<PII>,greater<PII> >qe;
	qe.push({0,st});
	while(!qe.empty())
	{
		int x=qe.top().second,z=qe.top().first;
		qe.pop();
		if(s[x])
		{
			continue;
		}
		s[x]=1;
		for(int i=0;i<e[x].size();i++)
		{
			int y=e[x][i].to,cst=e[x][i].val;
			if(dis[st][y]>z+cst)
			{
				dis[st][y]=z+cst;
				qe.push({z+cst,y});
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
	int c,d;
	cin>>c>>n>>m>>d>>q;
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
			int tmp1,tmp2;
			cin>>tmp1>>tmp2;
			a[i].push_back(tmp1);
			t[i].push_back(tmp2);
			for(int p=0;p<g[tmp1].size();p++)
			{
				int y=g[tmp1][p].to,z=g[tmp1][p].val;
				e[i].push_back({y,tmp2+z});
				e[y].push_back({i,tmp2+z});
			}
			g[tmp1].push_back({i,tmp2});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
	{
		dist(i);
	}
	while(q--)
	{
		int x,y,ans=INF;
		cin>>x>>y;
		if(x==y){cout<<0<<"\n";continue;}
		for(int i=0;i<g[x].size();i++)
		{
			int xto=g[x][i].to,xval=g[x][i].val;
			for(int j=0;j<g[y].size();j++)
			{
				int yto=g[y][j].to,yval=g[y][j].val;
				int res=dis[xto][yto]+xval+yval+w[x]+w[y];
				ans=min(ans,res);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
