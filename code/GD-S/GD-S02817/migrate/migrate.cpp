#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ppp,T,n,d,a[5005],f[5005][5005],h[5005][5005];
int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ppp>>T;
	while(T--)
	{
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		ll o=a[2]-a[1],t=1;
		for(int i=1;i<n;i++)if(a[i+1]-a[i]!=o)t=0;
		if(t)
		{
			if((d/o>1))
			cout<<(max(0*1ll,n-(d/o)*2+1))<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=0,h[i][j]=1e18;
		for(int i=1;i<=n-1;i++)
		{
			f[i][i]=1;
			h[i][i]=0;
			for(int j=i+1;j<=n;j++)
			{
				ll k=j-1;
				while(k>=i&&a[j]-a[k]<=d)
				{
					if(h[i][j]>h[i][k]+1)
						f[i][j]=f[i][k],h[i][j]=h[i][k]+1;
					else if(h[i][j]==h[i][k]+1)
						f[i][j]+=f[i][k];
					k--;
				}
				if(f[i][j]==2)ans++;
				if(f[i][j]==0)break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
