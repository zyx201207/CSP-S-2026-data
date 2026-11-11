#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000+10;
const ll inf=1e17;
ll c,T,n,k;
ll a[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				a[i][j]=inf;
		for(ll i=1;i<=n;i++) a[i][i]=0;
		for(ll i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			a[u][v]=a[v][u]=1;
		}
		for(ll k=1;k<=n;k++)
		{
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=n;j++)
				{
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		ll lim=(1<<n)-1,ans=inf;
		for(ll s=0;s<=lim;s++)
		{
			ll cnt=__builtin_popcount(s);
			if(cnt!=k) continue;
			ll sum=0;
			for(ll i=1;i<=n;i++)
			{
				if(!(s&(1<<(i-1))))
				{
					ll res=inf;
					for(ll j=1;j<=n;j++)
					{
						if(s&(1<<(j-1)))
						{
							res=min(res,a[i][j]);
						}
					}
					sum=max(sum,res);
				}
			}
			ans=min(ans,sum);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
