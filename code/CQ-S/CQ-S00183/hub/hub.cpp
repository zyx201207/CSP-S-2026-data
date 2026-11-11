/*
	还是做不到吗 /ll 
*/
#include<bits/stdc++.h>
using namespace std;
const int GI=1<<20;
char *p1,*p2,buf[GI];
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,GI,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int x=0,f=1;char ch=nc();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=nc();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=nc();
	return x*f;
}
const int inf=0x3f3f3f3f;
const int maxn=4000+7;
int C,T,n,k,dis[maxn],ans=inf;
bool vis[maxn],vis1[maxn];
vector<int> g[maxn];
void dfs1(int i,int f)
{ 
	for(int j:g[i])
		if(j!=f)
		{
			dis[j]=dis[i]+1;
			if(!vis[j]) dfs1(j,i);
		} 
}
void dfs2(int i,int f)
{
	for(int j:g[i])
	{
		if(j!=f&&vis[j])
		{
			vis1[j]=true;
			dfs2(j,i);
		}
	}
}
void dfs(int x,int j)
{
	if(x>n) 
	{
		if(j<k) return;
		int cnt=0;
		memset(vis1,0,sizeof(vis1));
		for(int i=1;i<=n;i++)
			if(vis[i]&&!vis1[i])
			{
				dfs2(i,0),cnt++;
				if(cnt>2) return;
			}
		int maxv=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			memset(dis,0,sizeof(dis));
			dfs1(i,0);
			for(int y=1;y<=n;y++) maxv=max(maxv,dis[y]);
		}
	//	cout<<maxv<<'\n';
	//	for(int i=1;i<=n;i++) cout<<vis[i]<<' ';cout<<'\n';
		
		ans=min(ans,maxv);
		return;
	} 
	if(j<k)
	{
		vis[x]=true;
		dfs(x+1,j+1);
		vis[x]=false;
	}
	dfs(x+1,j);
}
void solve()
{
	while(T--)
	{
		for(int i=1;i<=n;i++) g[i].clear();
		ans=inf;
		n=read(),k=read();
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	//	cout<<zx<<' ';
	} 
}
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read(),T=read();
	solve();
	return 0;
}
/*
0 1
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

0 1
5 2
1 2
2 3
3 4
4 5

0 3
10 3
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 3
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 3
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/

