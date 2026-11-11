#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=7e3+5;
long long c,n,m,d,q,k[N],x[M],t[M],p[M],f[M][M],cnt[M],w[M],s[M][M];
bool vis[M]; 
void Floyd()
{
	for(int k=1;k<=m;++k)
	{
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(f[i][k]+f[k][j]<f[i][j]) f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int u,v=0;
	cin>>c>>n>>m>>d>>q;
	memset(f,127/3,sizeof(f));
	for(int i=1;i<=m;++i) cin>>w[i],f[i][i]=0;
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j)
		{
			cin>>x[j]>>t[j];
			if(j==1) continue;
		}
		for(int j=1;j<=k[i];++j)
		{
			for(int g=1;g<=k[i];++g)
			{
				f[x[j]][x[g]]=t[g]+t[j];
				f[x[g]][x[j]]=t[g]+t[j];
			}
		}
	}
	Floyd();
	for(int i=1;i<=q;++i)
	{
		cin>>u>>v;
		cout<<f[u][v]+w[u]+w[v]<<endl;
	}
	return 0;
}
