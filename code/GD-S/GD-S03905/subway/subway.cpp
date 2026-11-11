#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int c,n,m,f,q;
int w[N];
int t[N][25];
int d[N];
int vis[N];
int v[N],tt[N];
struct edge{
	int v,w;
};
vector <edge> e[N];
void dij(int s)
{
	priority_queue<pair<int,int> > q;
	q.push({0,s});
	d[s]=0;
	while(q.size()){
		
		int u=q.top().second;
		q.pop();
		if (vis[u])continue;
		vis[u]=1;
		for (auto ed:e[u])
		{
			
			int v=ed.v;
			int w=ed.w;
			if (d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>f>>q;
	for (int i=1;i<=n;i++)cin>>w[i];
	for (int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>v[j]>>tt[j];
		}
		for (int j=1;j<=k;j++)
		{
			for (int s=j+1;s<=k;s++)
			{
				e[v[j]].push_back({v[s],tt[j]+tt[s]});
				e[v[s]].push_back({v[j],tt[j]+tt[s]});
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		for(int i=1;i<=n;i++)d[i]=INT_MAX,vis[i]=0;
		int st,en;
		cin>>st>>en;
		dij(st);
		cout<<d[en]+w[st]+w[en]<<"\n";
	}
	return 0;
}
