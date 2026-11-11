#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500005],b[500005],m,ans=-1e18;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n<=5000)
	{
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(ll i=1;i<n;i++)
		{
			b[i]=b[i-1]+a[i];
		}
		for(ll i=n;i>=1;i--)
		{
			ll awa=m,qwq=1,cha=0;
			for(ll j=1;j<=i-1;j++)
			{
				cha=a[i]*(i-j)-(b[i-1]-b[j-1]);
				if(awa>=cha)
				{
					qwq+=i-j;
					break;
				}
			}
			ans=max(ans,qwq);
		}
		cout<<ans;
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(ll i=1;i<n;i++)
		{
			b[i]=a[i+1]-a[i];
		}
		ll qwq=1,awa=m;
		for(ll i=n-1;i>=1;i--)
		{
			if(awa>=b[i])
			{
				awa-=b[i];
				qwq++;
			}
			else
			{
				break;
			}
		}
		cout<<qwq;
		
	}
	return 0;
}
