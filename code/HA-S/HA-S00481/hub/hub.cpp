#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int myread()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void prin(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) prin(x/10);
	putchar(x%10+'0');
}

const int MAXN=1000006;

int n,k;

struct graph
{
	int nxt,to;
}
edg[2*MAXN];
int h[MAXN];
int cnt;
void add(int u,int v)
{
	edg[++cnt]={h[u],v};
	h[u]=cnt;
}

bool chs[MAXN];
bool vis[MAXN];
void dfs(int u)
{
	vis[u]=1;
	for (int i=h[u];i;i=edg[i].nxt)
	{
		int v=edg[i].to;
		if (!chs[v]||vis[v]) continue;
		dfs(v);
	}
}

int ds[MAXN];
queue<int> q;

int bfs(int st)
{
	while (!q.empty()) q.pop();
	for (int i=1;i<=n;i++) vis[i]=0;
	ds[st]=0;
	vis[st]=1;
	q.push(st);
	while (1)
	{
		int u=q.front();
		q.pop();
		for (int i=h[u];i;i=edg[i].nxt)
		{
			int v=edg[i].to;
			if (vis[v]) continue;
			vis[v]=1;
			ds[v]=ds[u]+1;
			if (chs[v]) return ds[v];
			q.push(v);
		}
	}
}

void solve()
{
	n=myread(); k=myread();
	for (int i=1,u,v;i<n;i++)
	{
		u=myread(); v=myread();
		add(u,v); add(v,u);
	}
	
	int ans=1000000000;
	int lim=(1<<n);
	for (int mask=1;mask<lim;mask++)
	{
		int cntt=0;
		for (int i=1;i<=n;i++)
		{
			if ((mask>>(i-1))&1) cntt++;
		}
		if (cntt!=k) continue;
		for (int i=1;i<=n;i++)
		{
			if ((mask>>(i-1))&1) chs[i]=1;
			else chs[i]=0;
		}
		cntt=0;
		for (int i=1;i<=n;i++) vis[i]=0;
		for (int i=1;i<=n;i++)
		{
			if (chs[i]&&!vis[i])
			{
				cntt++;
				dfs(i);
			}
		}
		if (cntt>2) continue;
		int maxdis=0;
		for (int i=1;i<=n;i++)
		{
			if (!chs[i])
			{
				maxdis=max(maxdis,bfs(i));
			}
		}
		ans=min(ans,maxdis);
	}
	prin(ans);
	putchar('\n');
	return;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int C,T;
	C=myread();
	T=myread();
	while (T--)
	{
		solve();
		for (int i=1;i<=n;i++) h[i]=0;
		for (int i=1;i<=cnt;i++) edg[i]={0,0};
		cnt=0;
	}
	return 0;
}
