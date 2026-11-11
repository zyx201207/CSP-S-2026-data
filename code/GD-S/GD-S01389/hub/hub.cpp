#include<bits/stdc++.h>
#define int int
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
#define Tie cin.tie(0)->sync_with_stdio(0)
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int INF=1e9;
const int N=1e6+5;
int T,n,m,ans,Taskid,cnt,x,y;
int a[N];
int dis[N];
int head[N];
bool bz[N];
bool vis[N];
struct Edge
{
	int to,nxt;
}e[N<<1];
double st,ed;
queue<pair<int,int>> q;
void add(int from,int to)
{
	e[++cnt]={to,head[from]},head[from]=cnt;
}
void bfs1(int st)
{
	q.emplace(st,0),vis[st]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		q.pop();
		for(int i=head[x];i;i=e[i].nxt)
		{
			int y=e[i].to;
			if(bz[y]&&!vis[y]) vis[y]=1,q.emplace(y,0);
		}
	}
}
int bfs2()
{
	int res=0;
	rep(i,1,n) if(bz[i]) vis[i]=1,q.emplace(i,0);
	while(!q.empty())
	{
		int x=q.front().first,d=q.front().second;
		q.pop();
		for(int i=head[x];i;i=e[i].nxt)
		{
			int y=e[i].to;
			if(!vis[y]) vis[y]=1,q.emplace(y,d+1),res=max(res,d+1);
		}
	}
	// cerr<<res<<" ";
	return res;
}
void dfs(int x,int k)
{
	if(k==0)
	{
		int res=0,s=0;
		fill(vis+1,vis+n+1,0);
		rep(i,1,n) if(bz[i]&&!vis[i]) s++,bfs1(i);
		if(s>2) return;
		fill(vis+1,vis+n+1,0),ans=min(bfs2(),ans);
		return;
	}
	if(x>n) return;
	bz[x]=1,dfs(x+1,k-1),bz[x]=0,dfs(x+1,k);
}
void solve()
{
	cin>>n>>m,memset(head,0,sizeof head),cnt=0,ans=INT_MAX;
	rek(i,1,n) cin>>x>>y,add(x,y),add(y,x);
	dfs(1,m),cout<<ans<<'\n';
	// cerr<<'\n';
}
signed main()
{
	// st=clock(),fre(hub);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	Tie,cin>>Taskid>>T;
	while(T--) solve();
	// ed=clock(),cerr<<(ed-st)*1.0/CLOCKS_PER_SEC;
	return 0;
}//15pts