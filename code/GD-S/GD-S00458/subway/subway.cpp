#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=1e5+5,inf=1e13;
int c,n,m,D,Q,l,r,w[N],k[M],a[N][M],t[N][M];
int vis[N][M],mi,s,tl[N][M],d[M];
struct edge
{
	int nxl,nxt,we;
};
vector<edge> e[N];
vector<int> g[N];
struct node
{
	int nxl,nxt,we;
	bool operator < (const node &W) const
	{
		return we>W.we;
	}
};
priority_queue<node> q;
void dfs(int now,int s,int xl)
{
	if(now==r)
	{
		mi=min(mi,s+tl[xl][r]+w[r]);
		return;
	}
	for(edge x:e[now])
	{
		int nxl=x.nxl,nxt=x.nxt,we=x.we;
		if(xl==nxl)  dfs(nxt,s,xl);
		else  
		{
			dfs(nxt,s+we+tl[xl][now],nxl);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>D>>Q;
	for(int i=1;i<=n;i++)  cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			tl[i][a[i][j]]=t[i][j];
			g[a[i][j]].push_back(i);
		}
		for(int j=1;j<k[i];j++)  e[a[i][j]].push_back({i,a[i][j+1],t[i][j]});
	}
	if(n<=10)
	{
		while(Q--)
		{
			cin>>l>>r;
			mi=inf;
			for(int v:g[l])  dfs(l,w[l]+tl[v][l],v);
			cout<<mi<<'\n';
		}
		return 0;
	}
	while(Q--)
	{
		cin>>l>>r;
		for(int i=1;i<=n;i++)  
		{
			for(int j=1;j<=m;j++)  vis[i][j]=0;  
			d[i]=inf;
		}
		while(!q.empty())  q.pop();
		for(int v:g[l])  
		{
			q.push({v,l,w[l]+tl[v][l]});
			d[l]=min(d[l],w[l]+tl[v][l]);
		}
		mi=inf;
		while(!q.empty())
		{
			int xl=q.top().nxl,now=q.top().nxt,wn=q.top().we;
			q.pop();
			if(now==r)
			{
				mi=min(mi,d[r]+tl[xl][r]+w[r]);
			}
			if(vis[now][xl])  continue;
			vis[now][xl]=1;
			for(edge x:e[now])
			{
				int nxl=x.nxl,nxt=x.nxt,we=x.we;
				if(xl==nxl)  
				{
					if(d[nxt]>=wn)
					{
						d[nxt]=wn;
						q.push({xl,nxt,wn});
					}
				}
				else  
				{
					if(d[nxt]>=wn+we+tl[xl][now])
					{
						d[nxt]=wn+we+tl[xl][now];
						q.push({nxl,nxt,d[nxt]});
					}
				}
			}
		}
		cout<<mi<<'\n';
	}
	return 0;
} 
