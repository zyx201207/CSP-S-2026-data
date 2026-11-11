#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+200;
ll n,m;
ll a[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	ll sum=0,ans=1;
	for(ll l=1,r=2;r<=n;r++)
	{
		ll len=r-l;
		sum+=len*(a[r]-a[r-1]);
		while(sum>m)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
} 
