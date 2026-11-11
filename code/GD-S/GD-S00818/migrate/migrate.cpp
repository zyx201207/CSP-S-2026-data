#include <bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
const int N = 2e6+5,M = 5005;
int C,T;
int n,m,d;
int v[N],X[N];
vector<int> a[N];
int dist[N];bool vis[N];
int cnt[N];
void bfs(int s)
{
	for (int i = 1; i <= n; i++) dist[i]=2e18,cnt[i]=0,vis[i]=false;
	queue<int> q;
	q.push(s);
	dist[s]=0;
	cnt[s]=1;
	while (q.size())
	{
		int x = q.front();
		q.pop();
		if (vis[x]) continue;
		vis[x]=true;
		if (cnt[x]>2) continue;
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (dist[y]==dist[x]+1) cnt[y]+=cnt[x];
			else if (dist[y]>dist[x]+1)
			{
				cnt[y]=cnt[x];
				dist[y]=dist[x]+1;
				if (!vis[y]) q.push(y);
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),T=read();
	while (T--)
	{
		n=read(),d=read();
		bool flagA = true;
		for (int i = 1; i <= n; i++) v[i]=X[i]=read();
		for (int i = 3; i <= n; i++) flagA&=(X[i]-X[i-1]==X[i-1]-X[i-2]);
		if (flagA)
		{
			int D = X[2]-X[1];
			if (d<2*D) puts("0");
			else if (n<(d/D*2)) puts("0");
			else writech(n-(d/D*2)+1,'\n');
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			for (int j = i+1; j <= n; j++)
			{
				if (X[j]-X[i]>d) break;
				a[i].push_back(j);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			bfs(i);
			for (int j = 1; j <= n; j++) ans+=(cnt[j]==2);
		}
		writech(ans,'\n');
	}
	return 0;
}

