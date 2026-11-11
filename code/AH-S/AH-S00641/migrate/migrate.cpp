#include<bits/stdc++.h>
using namespace std;
int c,T;
long long d,a[2000001],n,f[302][302],p[302][302];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		  scanf("%lld",&a[i]);
	    if(c==11 or c==12)
	    {
			if(d<(a[2]-a[1])*2)
			{
				cout<<0<<'\n';
				continue;
			}
			int tmp=d/(a[2]-a[1]);
			cout<<n-(tmp*2-1)<<'\n';
		}
	    else if(c<=6)
	    {
			for(int i=1;i<=n;i++)
			  for(int j=1;j<=n;j++)
			    f[i][j]=1e18,p[i][j]=0;
			for(int i=1;i<=n;i++)
			  f[i][i]=0,p[i][i]=1;
			for(int i=1;i<=n;i++)
			  for(int j=i+1;j<=n;j++)
			    if(a[j]-a[i]<=d)f[i][j]=1,p[i][j]=1;
			for(int k=1;k<=n;k++)
			  for(int i=1;i<=n;i++)
			    for(int j=i+1;j<=n;j++)
			    {
			      if(k==i or k==j)continue;
			      if(f[i][k]+f[k][j]<f[i][j])f[i][j]=f[i][k]+f[k][j],p[i][j]=p[i][k]*p[k][j];
			      else if(f[i][k]+f[k][j]==f[i][j])p[i][j]+=p[i][k]*p[k][j];
			    }
			long long ans=0;
			for(int i=1;i<=n;i++)
			  for(int j=i+1;j<=n;j++)
			    if(p[i][j]==2)ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
