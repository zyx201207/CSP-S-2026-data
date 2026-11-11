#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
#define M 30001
long long c,n,m,d,p,w[M],l[510],t[510][M],x,y,a[510][M],e[510][510],q[M][510],tot[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) e[i][j]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		e[i][i]=0;
		scanf("%lld",&l[i]);
		for(int j=1;j<=l[i];j++) 
		{scanf("%lld",&a[i][j]);
		scanf("%lld",&t[i][a[i][j]]);
		q[a[i][j]][++tot[a[i][j]]]=i;}
	}
	for(int i=1;i<=m;i++)
	{
		if(tot[i]<2) continue;
		for(int j=1;j<=tot[i];j++)
			for(int k=j+1;k<=tot[i];k++)
				e[q[i][j]][q[i][k]]=e[q[i][k]][q[i][j]]=min(e[q[i][j]][q[i][k]],t[q[i][j]][i]+t[q[i][k]][i]);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&i!=k&&e[i][k]+e[k][j]<e[i][j])
					e[i][j]=e[i][k]+e[k][j];
	for(int i=1;i<=p;i++)
	{
		scanf("%lld%lld",&x,&y);
		ll ans=0x3f3f3f3f;
		for(int j=1;j<=tot[x];j++)
			for(int k=1;k<=tot[y];k++)
				ans=min(ans,w[x]+w[y]+e[q[x][j]][q[y][k]]+t[q[x][j]][x]+t[q[y][k]][y]);
		cout<<ans<<endl;
	}
	return 0;
}
