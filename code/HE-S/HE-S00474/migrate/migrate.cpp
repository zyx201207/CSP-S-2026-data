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
int vis[N];
int n,dd,x[N],d[N];
map< pair<int,int>,int > mp;
int dij(int s)
{
	int sum=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 
	for(int i=1;i<=n;i++)d[i]=INF,vis[i]=0;
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
			else if(d[e[i].to]==d[x]+e[i].val)
			{
				mp[{e[i].to,s}]++;
			}
			
		}	
	}
	return sum;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>dd;
		for(int i=1;i<=n;i++)
		{
			head[i]=0;
		}
		memset(e,0,sizeof(e));
		edge=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(i==j)continue;
				if(abs(x[i]-x[j])<=dd)
				{
			
					add(i,j,1);
					add(j,i,1);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=dij(i);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(mp[{i,j}]==1&&mp[{j,i}]==1)ans++;
				
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mp[{i,j}]=0;
				mp[{j,i}]=0;
				
			}
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}
