#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][20005],b[20005][505],le[20005];
long long t[505][20005],cnt=1e15,er[505][20005],fa[500005];
bool f[505];
void dfs(int x,int y,long long kkk)
{
	if(kkk>cnt) return;
	if(x==y)
	{
		cnt=min(cnt,kkk);
		return;
	}
	for(int i=1;i<=le[x];i++)
	{
		for(int j=1;j<=k[b[x][i]];j++)
		{
			if(le[a[b[x][i]][j]]>1&&!f[b[x][i]]&&a[b[x][i]][j]!=x)
			{
				f[b[x][i]]=1;
				dfs(a[b[x][i]][j],y,kkk+er[b[x][i]][x]+t[b[x][i]][j]);
				f[b[x][i]]=0;
			}
			else if(a[b[x][i]][j]==y) dfs(y,y,kkk+er[b[x][i]][x]+t[b[x][i]][j]);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
//	if(c>=20&&c<=21)
//	{
//		int aa[3][500005];
//		long long tt[3][500005];
//		for(int i=1;i<=m;i++) fa[i]=i;
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%d",&k[i]);
//			if(k[i]==1) i--,n--;
//			for(int j=1;j<=k[i];j++)
//			{
//				scanf("%d%lld",&aa[i][j],&tt[i][j]);
//				if(j>1) fa[aa[i][j]]=cz(fa[aa[i][j-1]]);
//			}
//		}
//		for(int i=1;i<=m;i++)
//		{
//			if()
//		}
//		while(q--)
//		{
//			int x,y;
//			long long ans;
//			scanf("%d%d",&x,&y);
//			ans=w[x]+w[y];
//			if(cz(x)==cz(y)) printf("%lld\n",ans);
//			else
//			{
//				
//			}
//		}
//		return 0;
//	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		if(k[i]==1) i--,n--;
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%lld",&a[i][j],&t[i][j]);
			er[i][a[i][j]]=t[i][j];
			b[a[i][j]][++le[a[i][j]]]=i;
		}
	}
	if(c>=1&&c<=6)
	{
		while(q--)
		{
			int x,y;
			long long ans;
			scanf("%d%d",&x,&y);
			ans=w[x]+w[y];
			dfs(x,y,0);
			printf("%lld\n",ans+cnt);
		}
		return 0;
	}
	if((c>=7&&c<=11))
	{
		long long x[1005][1005];
		bool f[1005][1005];
		memset(f,0,sizeof(f));
		for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) x[i][j]=2000000000ll;
//		cout<<x[1][1]<<'\n';
		for(int i=1;i<=n;i++)
		{
			f[a[i][1]][a[i][2]]=f[a[i][2]][a[i][1]]=1;
			x[a[i][1]][a[i][2]]=x[a[i][2]][a[i][1]]=min(t[i][1]+t[i][2],x[a[i][1]][a[i][2]]);
		}
		for(int kk=1;kk<=m;kk++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(x[i][j]>x[i][kk]+x[kk][j])
					{
						x[i][j]=x[i][kk]+x[kk][j];
					}
				}
			}
		}
		while(q--)
		{
			int u,v;
			long long ans;
			scanf("%d%d",&u,&v);
			ans=w[u]+w[v];
			if(!f[u][v]) ans+=x[u][v];
//			cout<<u<<' '<<v<<' '<<x[u][v]<<'\n';
			printf("%lld\n",ans);
		}
		return 0;
	}
	return 0;
}
