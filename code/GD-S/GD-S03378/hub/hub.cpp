#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,f[1000005];
long long ff[1000005][21],dep[1000005];
vector<long long>edge[1000005];
bool vis[1000005];
void read(long long &x)
{
	x=0;
	int w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1; 
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=w;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	int top=0,sta[100];
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top--) putchar(sta[top]+'0');
	putchar('\n');
}
long long lca(long long x,long long y)
{
	if(dep[x]<dep[y]) swap(x,y);
	long long o=dep[x]-dep[y];
	for(int i=20;i>=0;i--) if(o>=(1<<i)) o-=(1<<i),x=ff[x][i];
	if(x==y) return x;
	
	for(int i=20;i>=0;i--)
	{
		if(ff[x][i]!=ff[y][i])
		{
			x=ff[x][i];y=ff[y][i];
		}
	}
	return ff[x][0];
}
long long dis(long long x,long long y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void dfs(long long o,long long fa)
{
	for(int v:edge[o])
	{
		if(v==fa) continue;
		dep[v]=dep[o]+1;
		dfs(v,o);
		ff[v][0]=o;
	}
}
long long fid(long long a){return f[a]==a?a:f[a]=fid(f[a]);}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c);read(t);
	while(t--)
	{
		long long u,v;
		read(n);read(k);
		for(int i=1;i<n;i++)
		{
			read(u);read(v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1,0);
		ff[1][0]=1;
		for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) ff[i][j]=ff[ff[i][j-1]][j-1];
		long long ans=1e18;
		if(n<=10)
		{
			for(int s=0;s<(1<<n);s++)
			{
				long long cnt=0;
				for(int i=1;i<=n;i++)
				{
					if(s>>(i-1)&1) vis[i]=1,cnt++;
					else vis[i]=0; 
				}
				if(cnt>k) continue;
				for(int i=1;i<=n;i++) f[i]=i;
				for(int i=1;i<=n;i++)
				{
					for(int vv:edge[i])
					{
						if(vis[i]&&vis[vv])
						{
							u=fid(i),v=fid(vv);
							if(u==v) continue;
							f[u]=v;
							cnt--;
						}
					}
				}
				
				if(cnt<=2)
				{
					long long mx=0;
					for(int i=1;i<=n;i++)
					{
						long long mn=1e18;
						for(int j=1;j<=n;j++)
						{
							if(s>>(j-1)&1) mn=min(mn,dis(i,j));
						}
						mx=max(mx,mn);
					}
					ans=min(ans,mx);
				}
				
			}
		}
		else
		{
			ans=n/2;
		}
		write(ans);
		for(int i=1;i<=n;i++) edge[i].clear();
	}
	return 0;
}
