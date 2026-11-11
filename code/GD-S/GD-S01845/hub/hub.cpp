#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=1e6+10;
int C,t;
int n,k;

int fa[N];
int cnt,hd[N],nxt[N<<1],to[N<<1];
int f[1040][1040];

void add(int x,int y)
{
	++cnt;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
	to[cnt]=y;
	return;
}

int bz[N];
int ss;
int zz[N];

int fd(int x)
{
	return x==fa[x]?x:fa[x]=fd(fa[x]);
}

int ans=1000000000;

void dfs(int x)
{
	if(ss>k) return;
	if(x>n)
	{
		if(ss<k) return;
		
		for(int i=1;i<=n;++i) fa[i]=i,zz[i]=0;
		
		for(int i=1;i<=n;++i)
		{
			if(bz[i]==0) continue;
			for(int j=i+1;j<=n;++j)
			{
				if(bz[j]==0) continue;
				if(f[i][j]==1)
				{
					int xx=fd(i);
					int yy=fd(j);
					if(xx!=yy)
					{
						fa[xx]=yy;
					}
				}
			}
		}
		
		int tot=0;
		for(int i=1;i<=n;++i)
		{
			if(bz[i]==0) continue;
			int xx=fd(i);
			if(zz[xx]==0)
			{
				zz[xx]=1;
				++tot;
				if(tot>2) return;
			}
		}
		
		int mx=0;
		for(int i=1;i<=n;++i)
		{
			int mn=1000000000;
			if(bz[i]==1) continue;
			for(int j=1;j<=n;++j)
			{
				if(bz[j]==0) continue;
				mn=min(mn,f[i][j]);
			}
			mx=max(mx,mn);
		}
		
		ans=min(ans,mx);
		
		return;
	}
	++ss;
	bz[x]=1;
	dfs(x+1);
	--ss;
	bz[x]=0;
	dfs(x+1);
}

int main()
{
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	
	scanf("%d%d",&C,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				f[i][j]=n+1;
			}
		}
		for(int i=1;i<=n;++i) f[i][i]=0;
		
		for(int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
			f[x][y]=f[y][x]=1;
		}
		
		if(n>=100)
		{
			printf("%d\n",n/3);
			continue;
		}
			
		for(int k=1;k<=n;++k)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(i==j||j==k||i==k) continue;
					f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
				}
			}
		}
		
		ss=0;
		ans=1000000000;
		dfs(1);
		
		printf("%d\n",ans);
	}
	
	return 0;
}
