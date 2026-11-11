#include<bits/stdc++.h>
using namespace std;
const int N=510,M=2e4+10;
int w[M],a[N][N],t[N][N],k[M],dist[M];
vector<int> subway[M];
bool vis[M];
struct node{int u,v,ls,sum;};
bool operator<(node x,node y){return x.v>y.v;}
priority_queue<node> Q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,m,n,d,q,s,e,u,v,W,i,j,sum,x;
	cin>>c>>m>>n>>d>>q;
	for(i=1;i<=n;i++) cin>>w[i];
	for(i=1;i<=m;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			subway[a[i][j]].push_back(i);
		}
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		memset(dist,0x3f,sizeof(dist));
		while(!Q.empty()) Q.pop();
		cin>>s>>e;
		Q.push({s,w[s],0,0});
		dist[s]=w[s];
		while(!Q.empty())
		{
			u=Q.top().u;
			x=Q.top().ls;
			sum=Q.top().sum;
			if(u==e)
			{
				cout<<dist[u]+w[e]<<'\n';
				break;
			}
			Q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int S:subway[u])
				if(S!=x)
					for(i=1;i<=k[S];i++)
					{
						v=a[S][i];
						W=t[S][u]+t[S][v];
						if(dist[u]+W<dist[v])
						{
							dist[v]=dist[u]+W;
							Q.push({v,dist[v],S,sum+1});
						}
					}
		}
	}
	return 0;
}
