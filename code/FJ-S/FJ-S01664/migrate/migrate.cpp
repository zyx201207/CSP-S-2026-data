#include<bits/stdc++.h>
using namespace std;
long long m,t,n,d,x[2000001],f[2000001],g[2000001],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		long long ans=0;
		for(int l=1;l<=n-1;l++)
		{
			g[l]=f[l]=1;
			for(int i=l+1;i<=n;i++)
			{
				f[i]=1e18;
				g[i]=0;
			}
			for(int i=l+1;i<=n;i++)
			{
				int xx=lower_bound(x+l,x+n+1,x[i]-d)-x;
				f[i]=f[xx]+1;
				for(int j=xx;j<=i-1;j++)
				{
					if(f[j]==f[xx]) g[i]+=g[j];
					else break;
					if(g[i]>2) break;
				}
				if(g[i]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
