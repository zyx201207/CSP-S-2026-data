#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int c,n,m,d,q,a[N];
long long f[1009][1009],t[N],w[N],t1[N],t2[N];
vector<int> g[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	if(c<=11)
	{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				f[i][j]=2147483647000000000;
		for(int i=1;i<=n;i++)
		{
			int k; scanf("%d",&k);
			for(int j=1;j<=k;j++)
				scanf("%d%lld",&a[j],&t[j]);
			for(int j1=1;j1<=k;j1++)
				for(int j2=j1+1;j2<=k;j2++)
				{
					int u=a[j1],v=a[j2];
					f[u][v]=min(f[u][v],t[j1]+t[j2]);
					f[v][u]=f[u][v];
//					cout<<u<<" "<<v<<" "<<t[v]<<" "<<f[u][v]<<endl;
				}
		}
		for(int k=1;k<=m;k++)
			for(int i=1;i<=m;i++)
				for(int j=1;j<=m;j++)
					if(k!=i&&i!=j&&j!=k)
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		while(q--)
		{
			int u,v; scanf("%d%d",&u,&v);
			printf("%lld\n",f[u][v]+w[u]+w[v]);
		}
	}
	else if(c<=19)
	{
		int T=0;
		for(int i=1;i<=n;i++)
		{
			int k; scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				int a; long long t;
				scanf("%d%lld",&a,&t);
				if(T==0) T=t;
				g[a].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				f[i][j]=f[j][i]=2147483647000000000;
		for(int i=1;i<=n;i++) f[i][i]=0;
		for(int i=1;i<=m;i++)
			for(int j=0;j<g[i].size();j++)
				for(int k=j+1;k<g[i].size();k++)
					f[g[i][j]][g[i][k]]=f[g[i][k]][g[i][j]]=1;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(k!=i&&i!=j&&j!=k)
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		while(q--)
		{
			int u,v; scanf("%d%d",&u,&v);
			long long ans=2147483647000000000;
			for(int i:g[u]) for(int j:g[v]) ans=min(ans,f[i][j]);
			printf("%lld\n",(ans+1)*2*T+w[u]+w[v]);
		}
	}
	else if(c<=21)
	{
		int k; scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			long long tt1;
			scanf("%d%lld",&a[j],&tt1);
			t1[a[j]]=tt1;
		}
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			long long tt2;
			scanf("%d%lld",&a[j],&tt2);
			t2[a[j]]=tt2;
		}
		long long minn=2147483647000000000;
		for(int i=1;i<=m;i++)
			if(t1[i]&&t2[i])
				minn=min(minn,t1[i]+t2[i]);
		while(q--)
		{
			int u,v; scanf("%d%d",&u,&v);
			long long ans=2147483647000000000;
			if(t1[u]&&t1[v]) ans=min(ans,t1[u]+t1[v]);
			if(t2[u]&&t2[v]) ans=min(ans,t2[u]+t2[v]);
			if(t1[u]&&t2[v]) ans=min(ans,t1[u]+t2[v]+minn);
			if(t2[u]&&t1[v]) ans=min(ans,t2[u]+t1[v]+minn);
			printf("%lld\n",ans+w[u]+w[v]);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int k,a; scanf("%d",&k);
			long long t;
			for(int j=1;j<=k;j++)
				scanf("%d%lld",&a,&t);
		}
		while(q--)
		{
			int u,v; scanf("%d%d",&u,&v);
			printf("%lld\n",2+w[u]+w[v]);
		}
	}
	return 0;
}
