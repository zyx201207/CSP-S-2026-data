#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=500000+10;
int dis[N];bool vis[N];
struct node
{
	int v,w;
};
vector<node>dt[N];


void dijkstra(int x,int y)
{
   	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push({0,x});
	while(!pq.empty())
	{
		int a=pq.top().second;
		int b=pq.top().first;
		if(vis[a]||b>dis[a])continue;
		vis[a]=1;
		for(auto e:dt[a])
		{
			if(dis[e]>dis[a]+e.w)
			{
				dis[e]=dis[a]+e.w;
				pq.push({dis[e],e});
			}
		}		
	}	
	cout<<dis[y]<<'\n';
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     cin>>c>>n>>m>>d>>q;	
	 for(int i=1;i<=m;i++)
       {
     	  int w;
     	  cin>>w;
     	  dt[i].push_back({m+i,w});
     	  dt[m+i].push_back({i,w});
       }
       for(int i=1;i<=n;i++)
       {
       	   int k;
       	   cin>>k;
       	   for(int j=1;j<=k;j++)
       	   {
       	   	  int t;
       	   	  cin>>t;
       	   	  dt[n+m+j].push_back({j,t});
       	   	  dt[j].push_back({n+m+j,t});
       	   }
       	
       }
     whiel(q--)
     {
     int x,t;
       cin>>x>>y;
       dijkstra(x,y);
      
     } 
}
