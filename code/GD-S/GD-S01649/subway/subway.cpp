#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long to,x;
};
struct node2
{
	long long now,d;
};
long long jichu[500010];
long long c,n,m,dd,qq;
long long l[510];
long long vis[500010];
long long mn[500010];
vector<long long> b[510];
vector<long long> t[510];
vector<node> e[500010];
queue<node2> q;
//priority_queue<long long> d;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++)
	{
		cin>>jichu[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		long long cinb,cint;
		for(int j=1;j<=l[i];j++)
		{
			cin>>cinb>>cint;
			b[i].push_back(cinb);
			t[i].push_back(cint);
		}
	}
	if(1<=11)
	{
		for(int i=1;i<=n;i++)
		{
			for(int u=0;u<l[i];u++)
			{
				for(int v=u+1;v<l[i];v++)
				{
					e[ b[i][u] ].push_back({ b[i][v] , t[i][u]+t[i][v] });
					e[ b[i][v] ].push_back({ b[i][u] , t[i][u]+t[i][v] });
				}
			}
		}
		long long xb=0;
		while(qq--)
		{
			while(!q.empty())
			{
				q.pop();
			}
			xb++;
			long long u,v;
			cin>>u>>v;
			q.push({u,0});
			while(q.size()!=0)
			{
				node2 now=q.front();
				q.pop();
				for(auto to:e[now.now])
				{
					long long xh=now.d+to.x;
					if(vis[to.to]==xb && xh>=mn[to.to])
						continue;
					vis[to.to]=xb;
					mn[to.to]=xh;
					q.push({to.to,xh});
				}
			}
			cout<<mn[v]+jichu[u]+jichu[v]<<endl;
		}
	}
	return 0;
}
