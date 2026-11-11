#include<bits/stdc++.h>
using namespace std;
#define PII pair<long long,int>
const int N=500000;
int c,m,n,d,Q,k,a,w[N+10],t,uu,vv,lst,tol;
long long dis[N*2+10],ans[100010];
bool vis[N*2+10];
struct node{
	int v,w;
};
vector<node> ve[N*2+10];
priority_queue<PII,vector<PII>,greater<PII>> q;
struct edge{
	int sx,sy,id;
}s[100010];
void dijstra(int xr,int yr)
{
	for(int i=1;i<=tol;i++)
	{
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[xr]=0;
	q.push({0,xr});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]==1)	continue;
		vis[u]=1;
		for(int i=0;i<(int)ve[u].size();i++)
		{
			int v=ve[u][i].v,w=ve[u][i].w;
			long long nv=dis[u]+w;
			if(nv<dis[v])
			{
				dis[v]=nv;
				q.push({dis[v],v});
			}
		}
	}
	return ;
}
bool cmp(edge x,edge y)
{
	return x.sx<y.sx;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	tol=m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			tol++;
			uu=a;
			vv=tol;
			ve[uu].push_back({vv,t});
			ve[vv].push_back({uu,t});
			if(j>=2)
			{
				ve[lst].push_back({vv,0});
				ve[vv].push_back({lst,0});
			}
			lst=vv;
		}
	}
	for(int i=1;i<=Q;i++)
	{
		cin>>s[i].sx>>s[i].sy;
		s[i].id=i;
	}
	sort(s+1,s+1+Q,cmp);
	for(int i=1;i<=Q;i++)
	{
		if(s[i].sx!=s[i-1].sx)
			dijstra(s[i].sx,s[i].sy);
		ans[s[i].id]=dis[s[i].sy]+w[s[i].sx]+w[s[i].sy];
	}
	for(int i=1;i<=Q;i++)
		cout<<ans[i]<<'\n'; 
	return 0; 
}
