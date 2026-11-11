#include<bits/stdc++.h>

#define pii pair<long long,int>
using namespace std;

const int M = 5e5+5;
typedef long long ll;
int w[1005];

int c,n,m,d,T;

vector<pii> g[M];

int tot;



namespace baoli
{
	priority_queue<pii,vector<pii>,greater<pii> > q;
	ll dis[5005][5005];
	bool book[5005][5005];
	void dij(int s)
	{
		while(!q.empty()) q.pop();
	
		q.push({0,s});
		dis[s][s]=0;
	
		while(!q.empty())
		{
			int now=q.top().second;
			q.pop();
		
			if(book[s][now]) continue;
			book[s][now]=true;
		
			for(auto y : g[now])
			{
				int to=y.first;
				ll val=y.second;
			
				if(dis[s][to]>dis[s][now]+val)
				{
					dis[s][to]=dis[s][now]+val;
					q.push({dis[s][to],to});
				}
			}
		}
	}
	
	void main()
	{
		for(int i=1;i<=tot;i++)
			for(int j=1;j<=tot;j++)
				dis[i][j]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=m;i++)
			dij(i);
		
		
//		for(int i=1;i<=m;i++)
//		{
//			cout<<"\n";
//			for(int j=1;j<=m;j++)
//				cout<<dis[i][j]<<" ";
//		}
		while(T--)
		{
			int x,y;
			cin>>x>>y;
			
			cout<<1ll*(min(dis[x][y],dis[y][x])+w[x]+w[y])<<"\n";
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>c>>n>>m>>d>>T;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	tot=m+1;
	for(int t=1;t<=n;t++)
	{
		int k;
		cin>>k;
		
		int tmp=tot+1;
		for(int i=1;i<=k;i++)
		{
			int x,val;
			cin>>x>>val;
			
			++tot;
			g[x].push_back({tot,val});
			g[tot].push_back({x,val});
		}
		
		for(int i=tmp;i<tot;i++) 
		{
			g[i].push_back({i+1,0});
			g[i+1].push_back({i,0});
		}
	}
	
	baoli::main();
	return 0;
}
