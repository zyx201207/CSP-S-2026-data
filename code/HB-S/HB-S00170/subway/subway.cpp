#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rof(i,l,r) for(int i=(l);i>=(r);i--)
const int MAXN=5e5+505,INF=0x3f3f3f3f;
int n,m,ans,c,d,q;
vector<int> w,dis,vis;
vector<pii> e[MAXN];
void dij(int s)
{
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	For(i,0,n+m) dis[i]=INF,vis[i]=0;
	dis[s]=0,pq.push({0,s});
	while(pq.size())
	{
		int x=pq.top().second;pq.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto it:e[x])
		{
			int y=it.first,z=it.second;
			if(dis[x]+z<dis[y]) dis[y]=dis[x]+z,pq.push({dis[y],y});
		}
	}
}
void spfa(int s)
{
	queue<int> q;
	For(i,0,n+m) dis[i]=INF,vis[i]=0;
	dis[s]=0,q.push(s);
	while(q.size())
	{
		int x=q.front();q.pop();
		for(auto it:e[x])
		{
			int y=it.first,z=it.second;
			if(y==x) continue;
			if(dis[x]+z<dis[y]) dis[y]=dis[x]+z,q.push(y);
		}
	}
}
void zdl(int x)
{
	if(q<10) dij(x);
	else spfa(x);
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q,w.resize(m+1);
	For(i,1,m) cin>>w[i];
	For(i,1,n)
	{
		int k,a,t;cin>>k;
		For(j,1,k)
		{
			cin>>a>>t;
			e[m+i].push_back({a,t}),e[a].push_back({m+i,t});
		}
	}
	dis.resize(n+m+1),vis.resize(n+m+1);
	For(i,1,q)
	{
		int x,y;cin>>x>>y;
		if(x==y)
		{
			cout<<"0\n";
			continue;
		}
		zdl(x);
		cout<<w[x]+w[y]+dis[y]<<'\n';
	}
	return 0;
}
/*
 * zhan ting:1-m
 * xian lu n :m+1-m+n
 * 
 * zhan ting -> zhan tai
 * */
