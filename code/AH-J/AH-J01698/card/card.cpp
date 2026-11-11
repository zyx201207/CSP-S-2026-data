#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
bool f[505];
ll dis[205];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5000)
	{
		for(ll i=1;i<=n;i++)
		{
			memset(f,0,sizeof(f));
			for(ll j=i;j<=n;j++)
			{
				bool flag=false;
				for(ll k=j-1;k>=i;k--)
				{
					if(f[k]!=1&&a[k]==a[j])
					{
						flag=1;
						break;
					}
				}
				if(flag)
					for(ll k=j-1;k>=i;k--)
					{
						f[k]=1;
					}
			}
			for(ll j=i;j<=n;j++)
			{
				if(!f[j])
				{
					//cout<<i<<" "<<a[j]<<"\n";
					dis[a[j]]++;
				}
			}
		}
		for(ll i=1;i<=m;i++)
		{
			cout<<dis[a[i]]<<" ";
		}
	}
	return 0;
}
