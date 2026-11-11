#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=2e6+10;
ll C,t;
ll n,d;
ll x[N];

ll f[5050][5050];
ll g[5050][5050];

ll ybt[N];

int main()
{
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	
	//freopen("migrate4.in","r",stdin);freopen("migrate.out","w",stdout);
	
//	system("fc migrate.out migrate3.ans");
//	return 0;
	
	scanf("%lld%lld",&C,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;++i)
		{
			scanf("%lld",&x[i]);
		}
		
		if(C==11ll||C==12ll)
		{
			ll D=x[2]-x[1];
			ll C=D*(n/2ll+1ll)-d;
			
			if(2ll*D>d)
			{
				printf("0\n");
				continue;
			}
			else if(C<=0ll)
			{
				printf("0\n");
				continue;
			}
			
			ll dd=(C+D-1)/D;
			if(n%2==0)
			{
				printf("%lld\n",(dd-1ll)*2ll+1ll);
			}
			else
			{
				printf("%lld\n",dd*2ll);
			}
			continue;
		}
		else if(C==13ll||C==14ll)
		{
			ll cnt=0;
			for(ll i=2;i<n;++i)
			{
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d)
				{
					++cnt;
				}
			}
			if(cnt==2)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
			continue;
		}
		
		for(ll i=1;i<=n;++i)
		{
			for(ll j=1;j<=n;++j)
			{
				f[i][j]=n+1;
				g[i][j]=0;
			}
		}
		
		ll r=1;
		for(ll i=1;i<=n;++i)
		{
			while(x[r]-x[i]<=d&&r<=n) ++r;
			--r;
			ybt[i]=r;
		}
		
		for(ll i=1;i<=n;++i)
		{
			for(ll j=i+1;j<=ybt[i];++j)
			{
				g[i][j]=1;
				f[i][j]=1;
			}
		}
		
		for(ll i=1;i<=n;++i)
		{
			for(ll j=ybt[i]+1;j<=n;++j)
			{
				for(ll k=i+1;k<=j-1;++k)
				{
					if(f[i][j]>f[i][k]+f[k][j])
					{
						f[i][j]=f[i][k]+f[k][j];
						g[i][j]=g[i][k]*g[k][j];
					}
					else if(f[i][j]==f[i][k]+f[k][j])
					{
						g[i][j]+=g[i][k]*g[k][j];
					}
				}
			}
		}
		
		ll ans=0;
		for(ll i=1;i<=n;++i)
		{
			for(ll j=i+1;j<=n;++j)
			{
				if(g[i][j]==2)
				{
					++ans;
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
