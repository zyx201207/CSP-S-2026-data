#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id,u;
	long long sum;
};
vector<int> stations[500005];
vector<int> subways[500005];
int w[500005],t[505][500005];
long long dis[500005];
bool vis[505][500005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
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
			int a,tt;
			cin>>a>>tt;
			t[i][a]=tt;
			subways[i].push_back(a);
			stations[a].push_back(i);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		queue<node> que;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
		{
			dis[i]=1e18;
		}
		for(int i:stations[x])
		{
			que.push((node){i,x,t[i][x]});
			vis[i][x]=1;
			dis[x]=0;
		}
		int came=0;
		while(que.size())
		{
			node tt=que.front();
			que.pop();
			int id=tt.id,u=tt.u;
			long long sum=tt.sum;
			if(u==y)
			{
				dis[y]+=t[id][u];
				continue;
			}
			for(int new_id:stations[u])
			{
				if(id==new_id)
				{
					for(int v:subways[id])
					{
						if(u==v) continue;
						if(dis[v]<=sum) continue;
						que.push((node){id,v,sum});
						vis[id][v]=1;
						dis[v]=sum;
					}
				}
				else
				{
					long long new_sum=sum+t[id][u]+t[new_id][u];
					if(vis[new_id][u]==1) continue;
					que.push((node){new_id,u,new_sum});
					vis[new_id][u]=1;
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
