#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,T,n,d,a[N];
long long x[15],ans[15],sum;
long long f[305][305],t[305][305];
void dfs(int y,int ti)
{
	for(register int i=y;i<=n&&a[i]<=a[y]+d;++i)
	{
		if(ti+1==x[i]) { ans[i]++; dfs(i,ti+1); }
		if(ti+1<x[i]) { x[i]=ti+1,ans[i]=1; dfs(i,ti+1); }
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(register int i=1;i<=n;++i) scanf("%lld",&a[i]);
		sum=0;
		if(n<=9)
		{
			for(register int i=1;i<=n;++i)
			{
				for(register int j=1;j<=n;++j) x[j]=1e18+5,ans[j]=0;
				x[i]=0,dfs(i,0);
				for(register int j=1;j<=n;++j)
					if(ans[j]==2) sum++;
			}
			printf("%d\n",sum);
		}
		else 
		{
			for(register int i=1;i<=n;++i)
				for(register int j=1;j<=n;++j) f[i][j]=1e18+5,t[i][j]=0;
			for(register int i=1;i<=n;++i)
				for(register int j=i+1;j<=n&&a[j]-a[i]<=d;++j) 
					f[i][j]=1,t[i][j]=1;
			for(register int i=1;i<=n;++i)
				for(register int j=1;j<=n;++j)
					for(register int k=j+1;k<=n;++k)
					{
						if(f[j][i]+f[i][k]==f[j][k]) t[j][k]+=t[j][i]*t[i][k];
						if(f[j][i]+f[i][k]<f[j][k]) 
							f[j][k]=f[j][i]+f[i][k],t[j][k]=t[j][i]*t[i][k];
					}
			for(register int i=1;i<=n;++i)
				for(register int j=1;j<=n;++j)
					if(t[i][j]==2) sum++;
			printf("%lld\n",sum);
		}
	}
	return 0;
}
