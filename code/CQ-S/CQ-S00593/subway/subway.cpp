#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;

int c,n,m,mx,Q;

struct AA{
	int x,y;
};
struct BB{
	int x;
	ll y;
};

vector<AA> a[N];//a点经过的地铁线 和 路线中序号 
vector<BB> t[1005];//t号地铁线经过的点 

ll w[N];//出入站时间 

bool vis[N];
ll dis[N];
priority_queue<pair<ll,int> > q;
 

void djs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({0,s}); 
	dis[s]=0;
		
	while(!q.empty())
	{
		int u=q.top().second;
		ll d=-q.top().first;
		q.pop();
		
		if(vis[u]) continue;
		vis[u]=1;

		for(int f=0;f<a[u].size();f++)//u经过的边 
		{
			int l=a[u][f].x;//边的编号 l
			ll t1=t[l][a[u][f].y].y;
			
			for(int e=0;e<t[l].size();e++)//l中的其它点 
			{
				int v=t[l][e].x;
				ll t2=t[l][e].y;
				
				if(v==u) continue; 
				
				if(dis[v]>d+t1+t2)
				{
					dis[v]=d+t1+t2;
					q.push({-dis[v],v});
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>c>>n>>m>>mx>>Q;
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
			int A;
			ll T;
			
			cin>>A>>T;
			a[A].push_back({i,j-1});//第i个地铁线  A编号为j  
			t[i].push_back({A,T});
		}
	}
	for(int i=1;i<=Q;i++)
	{
		int s,t;
		cin>>s>>t;
		djs(s);
		cout<<dis[t]+w[s]+w[t]<<'\n';
	}
	return 0;
}

