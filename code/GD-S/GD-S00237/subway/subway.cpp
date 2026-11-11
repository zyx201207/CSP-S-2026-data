#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M],tot;
vector <pair<int,int> > v[M];
namespace sub1234
{
	LL dis[1005][1505];
	bool vis[1505];
	struct uuu{
		int u;
		LL dis;
		bool operator < (const uuu &a) const
		{
			return a.dis<dis;
		}
	};
	void dij(int s)
	{
		memset(dis[s],0x3f,sizeof(dis[s]));
		priority_queue <uuu> pq;
		dis[s][s]=0;
		pq.push((uuu){s,0});
		memset(vis,0,sizeof(vis));
		while(!pq.empty())
		{
			int u=pq.top().u;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=0;i<v[u].size();i++)
			{
				int v2=v[u][i].first,w=v[u][i].second;
				if(dis[s][v2]>=dis[s][u]+w)
				{
					dis[s][v2]=dis[s][u]+w;
					pq.push((uuu){v2,dis[s][v2]});
				}
			}
		}
	}
	void main()
	{
		tot=m;
		for(int i=1;i<=n;i++)
		{
			int kk;
			cin>>kk;
			tot++;
			for(int j=1;j<=kk;j++)
			{
				int a,t;
				cin>>a>>t;
				v[tot].push_back(make_pair(a,t));
				v[a].push_back(make_pair(tot,t));
			}
		}
		for(int i=1;i<=m;i++) dij(i);
		for(int i=1;i<=q;i++)
		{
			int xr,yr;
			cin>>xr>>yr;
			cout<<(LL)dis[xr][yr]+(LL)w[xr]+(LL)w[yr]<<"\n";
		}
	}
}
namespace sub5
{
	bool vis[20505];
	int bfs(int s,int t)
	{
		memset(vis,0,sizeof(vis));
		queue <int> q;
		q.push(s);
		int step=0;
		while(!q.empty())
		{
			int siz=q.size();
			for(int p=0;p<siz;p++)
			{
				int u=q.front();
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
//				cout<<u<<"\n";
				if(u==t) return step;
				for(int i=0;i<v[u].size();i++)
				{
					int v2=v[u][i].first;
//					cout<<v2<<"\n";
					if(vis[v2]) continue;
					q.push(v2);
				}
			}
			step++;
		}
	}
	void main()
	{
		tot=m;
		int T=0;
		for(int i=1;i<=n;i++)
		{
			int kk;
			cin>>kk;
			tot++;
			for(int j=1;j<=kk;j++)
			{
				int a,t;
				cin>>a>>t;
				T=t;
				v[tot].push_back(make_pair(a,t));
				v[a].push_back(make_pair(tot,t));
			}
		}
		for(int i=1;i<=q;i++)
		{
			int xr,yr;
			cin>>xr>>yr;
			cout<<(LL)bfs(xr,yr)*(LL)T+(LL)w[xr]+(LL)w[yr]<<"\n";
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c<=11)
	{
		sub1234::main();
		return 0;
	}
	if(c>=12 && c<=15)
	{
		sub5::main();
		return 0;
	}
	return 0;
}
/*
0 2 5 20 3
4 5 1 7 2
3 1 3 2 3 3 3
3 2 3 4 3 5 3 
2 4
1 4
1 5



提交前检查：
ll.
ce. re. /0 越界
多测清空
算空间！

*/

