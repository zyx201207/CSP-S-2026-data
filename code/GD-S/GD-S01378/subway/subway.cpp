#include<bits/stdc++.h>
using namespace std;
const long long M=1000,N=510;
long long c,n,m,d,q;
long long w[M],k[N],st[M+N][M+N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n+m;i++)
	{
		for(long long j=1;j<=n+m;j++)
		{
			if(i==j)st[i][j]=0;
			else st[i][j]=1e18;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		long long a,b,k;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>a>>b;
			st[a][m+i]=st[m+i][a]=b;
		}
	}
	for(long long k=1;k<=n+m;k++)
	{
		for(long long i=1;i<=n+m;i++)
		{
			for(long long j=1;j<=n+m;j++)st[i][j]=min(st[i][k]+st[k][j],st[i][j]);
		}
	}
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		cout<<st[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
