#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N=5e5+10;
int c,n,m,d,t;
int w[N],k[N];
int dis[N];
bool vis[N];
struct node{
	int u;
	int v;
};
vector<node> e[N];
priority_queue<pair<int ,int > >q;
void dij(int s){
	memset(dis,INF,sizeof dis);
	memset(vis,0,sizeof vis);
	vis[s]=1;
	dis[s]=0;
	q.push({0,s});
	while(q.size())
	{
		auto tp=q.top();
		q.pop();
		int x=tp.second;
		for(auto it:e[x])
		{
			if(vis[it.u]) continue;
			int next=it.u,val=it.v;
			if(dis[next]>dis[x]+val)
			{
				vis[next]=1;
				dis[next]=dis[x]+val;
				q.push({-dis[next],next});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int a[k[i]+1];
		for(int j=1;j<=k[i];j++)
		{
			int t;
			cin>>a[j]>>t;
			e[a[j]].push_back({a[j]+i*m,t});
			e[a[j]+i*m].push_back({a[j],t});
		}
		for(int j=1;j<k[i];j++)
		{
			e[a[j]+i*m].push_back({a[j+1]+i*m,0});
			e[a[j+1]+i*m].push_back({a[j]+i*m,0});
		}
	}
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
