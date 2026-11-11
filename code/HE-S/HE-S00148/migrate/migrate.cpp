#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+50,inf=0x3f3f3f3f3f3f;
int T,c;
int n,d;
int x[N],ans;
struct node{
	int id,dis;
	bool operator < (const node x) const{
		return x.dis<dis;
	}
};
struct edge{
	int to,w;
};
priority_queue<node> q;
vector<edge> e[N];
int f[N],g[N];
bool vis[N];
inline void dijkstra(int str)
{
	for(int i=1;i<=n;i++) g[i]=1,f[i]=0x3f,vis[i]=0;
	while(!q.empty()) q.pop();
	f[str]=0;
 	q.push({str,0});
 	while(!q.empty())
 	{
 		int x=q.top().id;
 		if(f[x]!=q.top().dis)
 		{
 			q.pop();
 			continue;
		}
		q.pop();
		for(int i=0;i<e[x].size();i++)
		{
			if(f[e[x][i].to]>f[x]+e[x][i].w)
			{
				f[e[x][i].to]=f[x]+e[x][i].w;
				g[e[x][i].to]=g[x];
				q.push({e[x][i].to,f[e[x][i].to]});
			}else if(f[e[x][i].to]==f[x]+e[x][i].w)
			{
				g[e[x][i].to]+=g[x];
			}
		}
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(x[j]-x[i])<=d) 
				{
					e[i].push_back({j,1});
				}else
				{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			dijkstra(i);
			for(int j=i+3;j<=n;j++) if(g[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
