#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int u;
	int dis;
	friend bool operator <(edge a,edge b)
	{
		return a.dis>b.dis;
	}
};
struct node
{
	int a;
	int t;
};
struct st
{
	int line;
	int id;
	int val;
};
int c,n,m,d,q;
int w[40005];
st s[40005];
vector<int> ed[40005],val[40005];
vector<node> sub[505];

int dis[40005];
bool p[40005];
void dij(int s)
{
	priority_queue<edge> q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<=40002;i++)
	{
		p[i]=0;
	}
	q.push((edge){s,0});
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(p[u])
		{
			continue;
		}
		p[u]=1;
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i];
			if(dis[v]>dis[u]+val[u][i])
			{
				dis[v]=dis[u]+val[u][i];
				q.push((edge){v,dis[v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int tot=m+1;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		for(int j=1;j<=op;j++)
		{
			int aa,tt;
			cin>>aa>>tt;
			sub[i].push_back((node){aa,tt});
		}
		for(int j=0;j<op-1;j++)
		{
			int tot_=tot+1;
			ed[tot].push_back(tot_);
			ed[tot_].push_back(tot);
			val[tot].push_back(0);
			val[tot_].push_back(0);
			s[tot]=((st){i,sub[i][j].a,sub[i][j].t});
			s[tot_]=((st){i,sub[i][j+1].a,sub[i][j+1].t});
			tot++; 
		}
		tot++;
	} 
	for(int i=m+1;i<=tot-1;i++)
	{
		ed[s[i].id].push_back(i);
		ed[i].push_back(s[i].id);
		val[s[i].id].push_back(s[i].val);
		val[i].push_back(s[i].val);
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		dij(u);
		cout<<dis[v]+w[u]+w[v]<<"\n";
	}
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
