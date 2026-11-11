#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ull unsigned long long
#define i128 __int128
#define pii pair<int,int>
#define inf 1000000000
#define infl 1000000000000000000ll
#define ls (p<<1)
#define rd (p<<1|1)
const int N=1e6+5;
const int M=1e7+5;
int ans,n,k,vis[N],fa[N],book[N];
vector<int> e[N];
vector<int> P;
set<int> s;
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int xx=find(x),yy=find(y);
	if(xx==yy) return;
	fa[xx]=yy;
}
void add(int u,int v)
{
	e[u].push_back(v);
}
int bfs(int s)
{
	if(vis[s]) return 0;
	for(int i=1;i<=n;i++) book[i]=0;
	queue<pii> q;
	q.push({s,0});
	book[s]=1;
	while(q.size())
	{
		pii x=q.front();
		q.pop();
		int u=x.first,w=x.second;
		for(auto v:e[u])
		{
			if(!book[v])
			{
				if(vis[v]) return w+1;
				book[v]=1;
				q.push({v,w+1});
			}
		}
	}
	return n;
}
void dfs(int now)
{
	if(P.size()>k) return;
	if(now==n+1)
	{
		if(P.size()!=k) return;
		for(auto x:P) fa[x]=x;
		for(auto x:P)
		{
			for(auto v:e[x])
			{
				if(vis[v]==1) merge(x,v);
			}
		}
		s.clear();
		for(auto x:P) s.insert(find(x));
		if(s.size()>2) return;
		int tmp=0;
		for(int i=1;i<=n;i++)
		{
			tmp=max(tmp,bfs(i));
			// cout<<i<<' '<<tmp<<endl;
		}
		
		ans=min(ans,tmp);
		return;
	}
	P.push_back(now);
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
	P.pop_back();
	dfs(now+1);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		ans=infl;
		dfs(1);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/