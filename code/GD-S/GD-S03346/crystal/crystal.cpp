#include<bits/stdc++.h>
#define ll long long
#define endl '\n';
using namespace std;
const ll maxn=5e5+10;
ll n,m,a[maxn],b[maxn],sum=0,res=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll maxx=0;
	for(ll i=n;i>=1;i--)
	{
		if(a[i+1]!=a[i])
		{
			ll ans=0,mm=m;
			for(ll j=i-1;j>=1;j--)
			{
				if(mm+a[j]>=a[i])	ans++,mm=mm-a[i]+a[j];
			}
			maxx=max(maxx,ans+1);
		}
	}
	cout<<maxx;
	return 0;
}
//Oct31==Dec25?
