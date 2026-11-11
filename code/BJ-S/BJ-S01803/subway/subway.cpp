#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,n,m,d,q,ww[N],dis[1537][1537],k,x,val,Dis[N],y,A[N],B[N],Mn;
bool vis[N];
struct edge
{
	int v,w;
	bool operator<(const edge &o)const
	{
		return w>o.w;
	}
};
vector<edge> e[N];
priority_queue<edge> que;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	if(c==20||c==21)
	{
		if(n==1)
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>x>>val;
				A[x]=val;
			}
			while(q--)
			{
				cin>>x>>y;
				cout<<A[x]+A[y]+ww[x]+ww[y]<<'\n';
			}
		}
		else
		{
			cin>>k;
			Mn=1e9;
			for(int j=1;j<=k;j++)
			{
				cin>>x>>val;
				A[x]=val;
			}
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>x>>val;
				B[x]=val;
			}
			for(int j=1;j<=n;j++)if(A[j]&&B[j])Mn=min(Mn,A[j]+B[j]);
			int ANS=1e17;
			while(q--)
			{
				cin>>x>>y;
				ANS=1e17;
				if(A[x]&&A[y])ANS=min(ANS,A[x]+A[y]);
				if(B[x]&&B[y])ANS=min(ANS,B[x]+B[y]);
				if(A[x]&&B[y])
				{
					ANS=min(ANS,Mn+A[x]+B[y]);
				}
				if(B[x]&&A[y])
				{
					ANS=min(ANS,Mn+B[x]+A[y]);
				}
				cout<<ANS+ww[x]+ww[y]<<'\n';
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>val;
			e[x].push_back({m+i,val}),e[m+i].push_back({x,val});
		}
	}
	if(c<=8||(!c))
	{
		while(q--)
		{
			cin>>x>>y;
			for(int i=1;i<=m+n;i++)Dis[i]=1e17,vis[i]=0;
			Dis[x]=0,que.push({x,0});
			while(!que.empty())
			{
				int u=que.top().v;
				que.pop();
				if(vis[u])continue;
				vis[u]=1;
				for(edge i:e[u])
					if(Dis[u]+i.w<Dis[i.v])
					{
						Dis[i.v]=Dis[u]+i.w;
						que.push({i.v,Dis[i.v]});
					}
			}
			cout<<Dis[y]+ww[x]+ww[y]<<'\n';
		}
	}
	else if(c==9||c==10||c==11)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m+n;j++)dis[i][j]=1e17,vis[j]=0;
			dis[i][i]=0;
			que.push({i,0});
			while(!que.empty())
			{
				int u=que.top().v;
				que.pop();
				if(vis[u])continue;
				vis[u]=1;
				for(edge j:e[u])
					if(dis[i][u]+j.w<dis[i][j.v])
					{
						dis[i][j.v]=dis[i][u]+j.w;
						que.push({j.v,dis[i][j.v]});
					}
			}
		}
		while(q--)
		{
			cin>>x>>y;
			cout<<dis[x][y]+ww[x]+ww[y]<<'\n';
		}
	}
	return 0;
}
