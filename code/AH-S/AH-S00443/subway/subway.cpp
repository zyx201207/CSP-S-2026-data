#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5;
int dis[M],w[M],c,n,m,d,q,k,a[M],t[M];
bool inq[M],vis[M];
typedef struct Node
{
	int v,w;
}Node;
vector<Node>g[N];
void spfa(int s)
{
	memset(inq,0,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	queue<int>que;
	que.push(s);
	inq[s]=1;
	dis[s]=0;
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		inq[u]=0;
		for(auto x:g[u])
		{
			int v=x.v,w=x.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!inq[v])
				{
					que.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				g[a[j]].push_back(Node{a[l],t[j]+t[l]});
				g[a[l]].push_back(Node{a[j],t[j]+t[l]});
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		spfa(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
