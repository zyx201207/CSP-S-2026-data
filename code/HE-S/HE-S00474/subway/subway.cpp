#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+10,INF=INT_MAX;
struct node{
	int from,to,next,val;
}e[N<<1];int head[N],edge;
void add(int x,int y,int z){edge++;
e[edge].from=x;e[edge].to=y;e[edge].next=head[x];e[edge].val=z;
head[x]=edge;
}
int n,m;int c,dd,q;int cnt=0;
int d[N],vis[N],w[N],k[N];
void bfs(int s,int t)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 
	for(int i=1;i<=cnt+n;i++)d[i]=INF,vis[i]=0;
	q.push({0,s});
	d[s]=0;
	while(!q.empty())
	{
	
		while(!q.empty()&&vis[q.top().second]==1)q.pop();
		if(q.empty())break;
		int x=q.top().second;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next)
		{
			
			if(d[e[i].to]>d[x]+e[i].val)
			{
				d[e[i].to]=d[x]+e[i].val;
				q.push({d[e[i].to],e[i].to});	
			}	
		}	
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>dd>>q;
	 cnt=m;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		add(i,++cnt,w[i]);
		add(cnt,i,w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			
			int x,y;
			cin>>x>>y;
			add(cnt+i,x+m,y);
			add(x+m,cnt+i,y);
		
		}
	}
	while(q--)
	{

		int xx,yy;
		cin>>xx>>yy;
		bfs(xx,yy);
		cout<<d[yy]<<"\n";
	}
	return 0;
}
