#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=(k<<3)+(k<<1)+c-'0';
		c=getchar();
	}
	return k*f;
}
struct node{int nex,to;}edg[1000010];
int h[1000010],cnt=0,n,k;
void add(int u,int v)
{
	cnt++;
	edg[cnt].nex=h[u];
	edg[cnt].to=v;
	h[u]=cnt;
}
int fina=1e9;
int viss[1000010];
int vis[1000010];
void putttt(int u,int fa)
{
	viss[u]=1;
	for(int i=h[u];i;i=edg[i].nex)
	{
		int v=edg[i].to;
		if(v==fa) continue;
		if(vis[v]) putttt(v,u);
	}
}
int get_ans(int u,int fa,int dep)
{
	if(vis[u]) return dep;
	int ans=1e9;
	for(int i=h[u];i;i=edg[i].nex)
	{
		int v=edg[i].to;
		if(v==fa) continue;
		ans=min(ans,get_ans(v,u,dep+1));
	}
	return ans;
}
void check()
{
	int cntt=0;int anss=0;
	for(int i=1;i<=n;i++) cntt+=vis[i];
	if(cntt!=k) return;
	for(int i=1;i<=n;i++) viss[i]=0;
	for(int i=1;i<=n;i++) if(vis[i]&&!viss[i]) putttt(i,0),anss++;
	if(anss!=2) return;
	int ansss=0;
	for(int i=1;i<=n;i++) ansss=max(ansss,get_ans(i,0,0));
	fina=min(ansss,fina);
}
void dfs(int dep)
{
	if(dep==n+1){check();return;}
	vis[dep]=0;dfs(dep+1);
	vis[dep]=1;dfs(dep+1);
}
bool check1(int kk)
{
	return (n/2+1-(kk-1+kk)-2*(kk-1)<=k);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c=read(),t=read();
	while(t--)
	{
		n=read(),k=read();
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		if(n<=15)
		{
			dfs(1);
			printf("%lld\n",fina);
		}
		else
		{
			int l=0,r=1e9;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(check1(mid)) r=mid;
				else l=mid+1;
			}
			printf("%lld\n",l);
		}
		cnt=0;fina=1e9;
		for(int i=1;i<=n;i++) h[i]=0;
	}
	return 0;
}
