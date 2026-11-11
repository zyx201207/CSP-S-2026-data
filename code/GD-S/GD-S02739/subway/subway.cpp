#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e4+10;
int c,n,m,d,qe,ans;
int w[N],k,v,t[N][N];
int idx,pre[N];
int dist[N];
bool vis[N];
struct node
{
	int from,to,last,k;
}a[N*2];
void add(int u,int v,int ce)
{
	a[++idx]={u,v,pre[u],ce};
	pre[u]=idx;
}
void dij(int s)
{
	priority_queue<PII> q;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		PII p=q.top();
		q.pop();
		if(vis[p.second]) continue;
		vis[p.second]=true;
		for(int i=pre[p.second];i;i=a[i].last)
		{
			int to=a[i].to,sum=dist[p.second];
			if(a[i].k!=a[to].k)
			{
				sum+=t[a[i].k][i]+t[a[to].k][to];
			}
			if(sum<dist[to])
			{
				dist[to]=sum;
				q.push({dist[to],to});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>qe;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		int p=0;
		for(int j=1;j<=k;j++)
		{
			cin>>v>>t[i][j];
			add(p,v,i);
			add(v,p,i);
			p=v;
		}
	}
	for(int i=1;i<=qe;i++)
	{
		int s,to;
		cin>>s>>to;
		dij(s);
		cout<<w[s]+t[a[s].k][s]+dist[to]+t[a[to].k][to]+w[to]<<" ";
	}
	return 0;
}
