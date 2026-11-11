#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace sol
{
	ll a[500010];
	int main()
	{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		int n;
		ll m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		ll sum=0;
		int p=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			while(a[i]*(i-p)-sum>m)sum-=a[p++];
			ans=max(ans,i-p+1),sum+=a[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
}
int main()
{
	sol::main();
	return 0;
}

