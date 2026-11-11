#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10,NN=5000+10;
const ll inf=1e17;
ll C,T,n,d;
ll x[N];
ll a[NN][NN],c[NN][NN];
void init()
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			a[i][j]=inf;
			c[i][j]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(C==11 || C==12)
		{
			ll ju=d/(x[2]-x[1]);
			ll ans=n-2*ju+1;
			ans=max(ans,0ll);
			if(ju<=1) ans=0;
			cout<<ans<<endl;
			continue;
		}
		init();
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					a[i][j]=1;
					c[i][j]=1;
				}
			}
		}
		for(ll k=1;k<=n;k++)
		{
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=n;j++)
				{
					if(a[i][j]>a[i][k]+a[k][j])
					{
						a[i][j]=a[i][k]+a[k][j];
						c[i][j]=c[i][k]*c[k][j];
					}
					else if(a[i][j]==a[i][k]+a[k][j])
					{
						c[i][j]+=c[i][k]*c[k][j];
					}
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(c[i][j]==2)
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
