#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
const int inf=1e18+10;

int c, T, n, k;
int h[N], e[N], ne[N], idx;
void add(int a, int b)
{
	e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

bool vis[N];
int ans, a[N];
int st[N], p[N], top, dis[N];
queue<int>q;
int fa[N], dep[N];
int f[N];
int find(int u)
{
	if(f[u]==u) return u;
	else return f[u]=find(f[u]);
}

void dfs(int u, int fa)
{
	::fa[u]=fa, dep[u]=dep[fa]+1;
//	cout<<u<<" "<<fa<<endl;
	for(int i=h[u]; i!=-1; i=ne[i])
	{
		int v=e[i];
		if(v==fa) continue;
		dfs(v, u);
	}
	
}

bool cmp(int u, int v){return dep[u]>dep[v];}
set<int>stt;


void solve_1()
{
	dfs(1, 0);
	for(int i=1; i<=n; i++) st[i]=a[i]=i;
	sort(a+1, a+n+1, cmp);
	
	int res=0, ans=inf;
	do{
		stt.clear();
		for(int i=1; i<=n; i++) vis[i]=false, dis[i]=0;
		for(int i=1; i<=n; i++) f[i]=i;
		for(int i=1; i<=k; i++) p[i]=st[i], dis[p[i]]=0, vis[p[i]]=true, q.push(p[i]);
		for(int i=1; i<=n; i++)
		{
			int u=a[i];
			if(vis[u] && vis[fa[u]]) f[u]=find(fa[u]);
		}
		for(int i=1; i<=n; i++) if(vis[i]) stt.insert(find(i));
		if(stt.size()>2) continue;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=h[u]; i!=-1; i=ne[i])
			{
				int v=e[i];
				if(vis[v]) continue;
				dis[v]=dis[u]+1;
				res=max(res, dis[v]);
			}
		}
		ans=min(ans, res);
	}while(next_permutation(st+1, st+n+1));
	cout<<ans<<endl;
}

void o()
{
	for(int u=1; u<=n; u++)
		for(int v=u+1; v<=n; v++)
		{
			memset(vis, 0, sizeof vis);
			q.push(u);
			q.push(v);
			int res=0, ans=inf;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(int i=h[u]; i!=-1; i=ne[i])
				{
					int v=e[i];
					if(vis[v]) continue;
					dis[v]=dis[u]+1;
					res=max(res, dis[v]);
				}
			}
			
			ans=min(ans, res);	
		}
}


signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%lld %lld", &c, &T);
	while(T--)
	{
		scanf("%lld %lld", &n, &k);
		memset(h, -1, sizeof h);
		memset(ne, 0, sizeof ne);
		memset(e, 0, sizeof e);
		idx=0;

		for(int i=1; i<=n-1; i++)
		{
			int u, v;
			scanf("%lld %lld", &u, &v);
			add(u, v);
			add(v, u);
		}
		if(k==2) o();
		else if(c<=3) solve_1();
	}
	
	
	return 0;
}
