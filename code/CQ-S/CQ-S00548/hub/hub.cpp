#include<iostream>
#include<queue>
#include<vector>
#include<numeric>
#include<cstring>
#include<algorithm>
template<typename T>
inline void read(T& x)
{
	x=0;int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-f;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
char asdf[1005];
template<typename T>
inline void write(T x,char dlc='\0')
{
	if(x<0) putchar('-'),x=-x;
	int t=0;
	while(x||(!t)) asdf[t++]=x%10+'0',x/=10;
	while(t--) putchar(asdf[t]);
	if(dlc!='\0') putchar(dlc);
}
#define pint std::pair<int,int>
#define mp std::make_pair
#define fi first
#define se second
#define vint std::vector<int>
#define pb emplace_back
#define vpint std::vector<std::pair<int,int> >
const int N=25;
int c,T,n,k,ans;
bool cho[N],vis[N];
vint g[N];
void dfs1(int u)
{
	vis[u]=1;
	for(int v:g[u])if(cho[v]&&!vis[v]) dfs1(v);
}
int dis[N];
inline int bfs(int st)
{
	for(int i=1;i<=n;++i)dis[i]=1e9; 
	std::queue<int>q;
	q.push(st);dis[st]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(cho[u]) return dis[u];
		for(int v:g[u])if(dis[v]>dis[u]+1)
		{
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	return 1e9;
}
inline void check()
{
	int ss=0;
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i)if(cho[i]&&!vis[i]) ++ss,dfs1(i);
	if(ss>2) return;
//	for(int i=1;i<=n;++i) write(cho[i]);putchar(10);
	int res=0;
	for(int i=1;i<=n;++i)if(!cho[i]) res=std::max(res,bfs(i));
	ans=std::min(ans,res);
}
void dfs(int u,int p)
{
	if(u>k) check();
	else for(int i=p+1;i<=n;++i)
	{
		cho[i]=1;
		dfs(u+1,i);
		cho[i]=0;
	}
}
inline void solve()
{
	read(n);read(k);ans=1e9;
	for(int i=1;i<=n;++i) g[i].clear();
	for(int i=1,u,v;i<n;++i)
	{
		read(u);read(v);
		g[u].pb(v);g[v].pb(u);
	 } 
	dfs(1,0);
	write(ans,10);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c);read(T);
	while(T--) solve();
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
