#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ci=const int;

ci N=35; 
namespace Qwq
{
	int c,t,k,n;
	int head[N],nxt[N<<1],tot,to[N<<1];
	int dis[N][N];
	int vis[N];
	int can[N];
	void add(int x,int y)
	{
		to[++tot]=y;
		nxt[tot]=head[x];
		head[x]=tot;
	}
	void dfs(int x,int fa,int r)
	{
		int i;
		for(i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(y==fa) continue;
			dis[r][y]=dis[r][x]+1;
			dfs(y,x,r);
		}
	}
	int check(int x)
	{
		int cnt=0;
		while(x)
		{
			x-=(x&-x);
			cnt++;
		}
		return cnt;
	}
	void dfsc(int x)
	{
		int i;
		for(i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(vis[y]||!can[y]) continue;
			vis[y]=1;
			dfsc(y);
		}
	}
	void mian()
	{
		int i,j,l;
		cin>>c>>t;
		while(t--)
		{
			cin>>n>>k;
			memset(head,0,sizeof head);
			memset(dis,0,sizeof dis);
			tot=0;
			for(i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				add(u,v);add(v,u);
			}
			for(i=1;i<=n;i++) dis[i][i]=0,dfs(i,0,i);
			int t=1<<n;
			int lans=0x3f3f3f3f;
			for(i=0;i<t;i++)
			{
				if(check(i)!=k) continue;
				memset(can,0,sizeof can);
				memset(vis,0,sizeof vis);
				int cnt=0;
				for(l=0;l<n;l++)
				{
					if((i>>l)&1) can[l+1]=1;
				}
				for(l=0;l<n;l++)
				{
					if(((i>>l)&1)&&!vis[l+1])
					{
						vis[l+1]=1;
						cnt++;
						dfsc(l+1);
					}
				}
				if(cnt>2) continue;
				int ans=0;
				for(j=1;j<=n;j++)
				{
					int d=0x3f3f3f3f;
					for(l=0;l<n;l++)
					{
						if((i>>l)&1) d=min(d,dis[j][l+1]);
					}
					ans=max(ans,d);
				}
				lans=min(lans,ans);
			}
			cout<<lans<<'\n';
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	Qwq::mian();
	return 0;
}
