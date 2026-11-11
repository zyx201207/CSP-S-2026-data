#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5005;
int c,t,n,d,x[N],f[N][N],g[N][N],cnt[N][N];
vector<int>G[N];
void Main()
{
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=g[i][j]=inf,cnt[i][j]=0;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++)
	{
		int pos=i-1;
		while(pos>=1&&x[i]-x[pos]<=d)f[pos][i]=f[i][pos]=1,pos--;
		pos=i+1;
		while(pos<=n&&x[pos]-x[i]<=d)f[pos][i]=f[i][pos]=1,pos++;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][k]!=inf&&f[k][j]!=inf&&f[i][j]>f[i][k]+f[k][j])f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i+1;k<j;k++)
			{
				if(f[i][k]!=inf&&f[k][j]!=inf&&f[i][j]==f[i][k]+f[k][j])cnt[i][j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(cnt[i][j]==2)ans++;
		}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)Main();
	return 0;
}
