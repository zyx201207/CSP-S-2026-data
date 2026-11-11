#include<bits/stdc++.h>
using namespace std;
long long f[10005][10005],c,n,m,d,q[505],w,k,a[2],t,x,y,p;
long long bh(long long g)
{
	return g*(k+2);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	memset(f,0x3f3f3f3f,sizeof(f));
	for(long long i=1;i<=n*22;i++)
		f[i][i]=0;
	for(long long i=1;i<=m;i++)
	{
		cin>>w;
		f[bh(i)][bh(i)+1]=w;
		f[bh(i)+1][bh(i)]=w;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>a[1]>>t;
			q[a[1]]++;
			f[bh(a[1])+1][bh(a[1])+1+q[a[1]]]=t;
			f[bh(a[1])+1+q[a[1]]][bh(a[1])+1]=t;
			f[bh(a[0])+q[a[0]]][bh(a[1])+q[a[1]]]=0;
			f[bh(a[1])+q[a[1]]][bh(a[0])+q[a[0]]]=0;
			a[0]=a[1];
		}
	}
	for(long long i=1;i<=n*22;i++)
	{
		for(long long j=i;j<=n*22;j++)
		{
			for(long long k=1;k<=n*22;k++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=f[i][j];
			}
		}
	}
	for(int i=1;i<=p;i++)
	{
		cin>>x>>y;
		cout<<f[bh(x)][bh(y)]<<endl;
	}
	return 0;
}
