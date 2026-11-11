# include <cstdio>
using namespace std;
int Tid,T,n,m,ls[1000007],nx[2000007],e[2000007],em,dp[1000007][2],B;
int dis[4007][4007],f[1000007],g[1000007],fa[1000007],fa1[1000007],A,bz[1000007];
int max(int x,int y){return x>y?x:y;}
void input(int x,int y)
{
	em++;
	e[em]=y;
	nx[em]=ls[x];
	ls[x]=em;
}
void dg5(int x,int y)
{
	for(int i=ls[x];i;i=nx[i])
	{
		if(e[i]==y) continue;
		fa[e[i]]=x;
		dg5(e[i],x);
	}
}
void dg1(int x,int y,int z)
{
	for(int i=ls[x];i;i=nx[i])
	{
		if(e[i]==y) continue;
		dis[z][e[i]]=dis[z][x]+1;
		dg1(e[i],x,z);
	}
}
int dg2(int x,int y,int xz)
{
	int z=1;
	g[x]=0;
	for(int i=ls[x];i;i=nx[i])
	{
		if(e[i]==y) continue;
		z=max(dg2(e[i],x,xz),z);
		g[x]+=g[e[i]];
	}
	if(g[x]>0||z>xz) g[x]++;
	return z+1;
}
void dg3(int x,int y)
{
	for(int i=ls[x];i;i=nx[i])
	{
		if(e[i]==y) continue;
		fa1[e[i]]=x;
		dg3(e[i],x);
	}
}
int dg4(int x,int y,int xz)
{
	int z=1;
	g[x]=0;
	for(int i=ls[x];i;i=nx[i])
	{
		if(e[i]==y) continue;
		z=max(z,dg4(e[i],x,xz));
		g[x]+=g[e[i]];
	}
	if(g[x]>0||z>xz) g[x]++;
	return z+1;
}
int does(int x)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) g[j]=n+1;
		dg2(i,fa[i],x);
		f[i]=g[i];
		if(f[i]==0) f[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]>=m) continue;
		for(int j=1;j<=n;j++) fa1[j]=-1;
		fa1[fa[i]]=i;
		dg3(fa[i],i);
		for(int j=1;j<=n;j++)
		{
			if(fa1[j]==-1) continue;
			for(int k=1;k<=n;k++) g[k]=n+1;
			dg4(j,fa1[j],x);
			if(g[j]==0) g[j]=1;
			int pan=1;
			if(g[j]+f[i]>m) continue;
			for(int k=1;k<=n;k++)
			{
				if(fa1[k]!=-1&&g[k]==n+1&&dis[k][i]>x&&dis[k][j]>x)
				{
					pan=0;
					break;
				}
			}
			if(pan==1) return 1;
		}
	}
	return 0;
}
int dg6(int x,int y,int xz)
{
	int z=0;
	for(int i=ls[x];i;i=nx[i])
	{
		if(e[i]==y) continue;
		z=max(z,dg6(e[i],x,xz)+1);
	}
	if(z>xz)
	{
		if(A==0) A=x;
		else if(B==0) B=x;
	}
	return z+1;
}
void dg7(int x,int y,int z,int xz)
{
	if(z<=xz) bz[x]=1;
	for(int i=ls[x];i;i=nx[i])
	{
		if(e[i]==y) continue;
		dg7(e[i],x,z+1,xz);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&Tid,&T);
	for(int happy=1;happy<=T;happy++)
	{
		scanf("%d%d",&n,&m);
		if(m==n)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=em;i++) e[i]=nx[i]=0;
		for(int i=1;i<=n;i++) ls[i]=0;
		em=0;
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			input(x,y),input(y,x);
		}
		if(Tid<=10)
		{
			for(int i=1;i<=n;i++) dg1(i,0,i);
			dg5(1,0);
			int l=1,r=n,ans=n;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(does(mid)==1) r=mid-1,ans=mid;
				else l=mid+1;
			}
			printf("%d\n",ans);
			continue;
		}
		if(m==2)
		{
			A=0;
			int l=1,r=n,ans=n;
			while(l<=r)
			{
				int mid=(l+r)/2;
				A=B=0;
				dg6(1,0,mid);
				dg6(A,0,mid);
				for(int i=1;i<=n;i++) bz[i]=0;
				dg7(A,0,0,mid);
				dg7(B,0,0,mid);
				int pan=1;
				for(int i=1;i<=n;i++)
				{
					if(bz[i]==0) pan=0;
				}
				if(B==0) pan=1;
				if(pan==1) r=mid-1,ans=mid;
				else l=mid+1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
