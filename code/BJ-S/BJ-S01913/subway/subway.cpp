#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+5;
const int M=1e5+4;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
struct node{
    int v;
    long long w;
};
struct no{
    int id;
    long long val;
};
bool operator < (const no &x,const no &y)
{
    return x.val>y.val;
}
ll w[M];
int k[N];
set<int> st[N];
map<int,ll> mp[N];
vector<node> adj[N];
ll dis[N][N];
bool vis[N];
int a[N][M];
ll t[N][M];
void dijkstra(int s)
{
    for(int i=1;i<=n;i++) dis[s][i]=inf;
    memset(vis,0,sizeof vis);
    priority_queue<no> pq;
    dis[s][s]=0;
    pq.push({s,0});
    while(!pq.empty())
    {
        no t=pq.top();
        pq.pop();
        int u=t.id;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto x:adj[u])
        {
            int v=x.v;
            int w=x.w;
            if(dis[s][u]+w<dis[s][v])
            {
                dis[s][v]=dis[s][u]+w;
                if(!vis[v])
                {
                    pq.push({v,dis[s][v]});
                }
            }
        }
    }
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin >>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin >>a[i][j]>>t[i][j];
			st[i].insert(a[i][j]);
			mp[i][a[i][j]]=t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ll ans=inf;
            for(auto x:st[i])
            {
                if(st[j].count(x))
                {
                    ans=min(ans,mp[i][x]+mp[j][x]); //huancheng
                }
            }
            adj[i].push_back({j,ans});
            adj[j].push_back({i,ans});
        }
    }
    for(int i=1;i<=n;i++) //O(nmlogn)
    {
        dijkstra(i);
    }
    while(q--) //O(qn^2logn)
    {
        int x,y;
        cin >>x>>y;
        ll ans=inf;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(st[i].count(x) && st[j].count(y))
                {
                    ll res=w[x]+mp[i][x]+dis[i][j]+mp[j][y]+w[y];
                    ans=min(ans,res);
                }
            }
        }
        cout <<ans<<'\n';
    }
	return 0;
}
