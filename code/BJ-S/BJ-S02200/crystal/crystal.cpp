#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],sum=0,t=1,ans=-1e9;
int main()
{
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		sum+=(i-t)*(a[i]-a[i-1]);
		if(sum>m)
		{
			for(;t<=i&&sum>m;t++) sum-=a[i]-a[t];
		}
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}