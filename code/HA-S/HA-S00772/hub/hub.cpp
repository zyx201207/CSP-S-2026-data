#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int res = 0;
	char ch = getchar();
	bool tag = 0;
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-')
	{
		tag = 1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		res = (res << 3) + (res << 1) + ch - '0';
		ch = getchar();
	}
	if (tag) return -res;
	return res;
}
void write(int x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	if (x >= 10) write(x/10);
	putchar(x%10+'0');
}
const int N = 1000006;
const int M = 2000006;
int op,T,n,k,u,v,cnt,head[N];
int ver[M],nxt[M],ans;
bool vis[N],tag[N];
int dfs(int u,int fa)
{
	if (vis[u]) return 0;
	int res = n;
	for (int i=head[u];i;i=nxt[i])
	{
		int v = ver[i];
		if (v == fa) continue;
		res = min(dfs(v,u),res);
	}
	return res+1;
}
void add(int x,int y)
{
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}
void sosuo(int u,int fa)
{
	if (!vis[u]) return;
	tag[u] = 1;
	for (int i=head[u];i;i=nxt[i])
	{
		int v = ver[i];
		if (v == fa) continue;
		sosuo(v,u);
	}
}
void calc(int id,int x)
{
	if (id == n+1)
	{
		int tot = 0, res = 0;
		for (int i=1;i<=n;i++) tag[i] = 0;
		for (int i=1;i<=n;i++)
		{
			if (!vis[i]) continue;
			if (tag[i]) continue;
			sosuo(i,0), tot++;
		}
		if (tot > 2) return;
		for (int i=1;i<=n;i++)
		{
			if (vis[i]) continue;
			res = max(res,dfs(i,0));
		}
		ans = min(ans,res);
		return;
	} 
	if (x < k) 
	{
		vis[id] = 1;
		calc(id+1,x+1);
		vis[id] = 0;
	}
	calc(id+1,x);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	op = read(), T = read();
	while (T--)
	{
		n = read(), k = read();
		cnt = 0, ans = n;
		for (int i=1;i<=n;i++)
			head[i] = 0;
		for (int i=1;i<n;i++)
		{
			u = read(), v = read();
			add(u,v), add(v,u);
		}
		calc(1,0);
		write(ans);
		puts("");
	}
	return 0;
}
