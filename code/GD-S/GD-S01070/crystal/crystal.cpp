#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll ans,a[N],s[N];
/*bool check(ll mid)
{
	ll j=1;
	for(ll i=1;i<=n;i++)//钦定第 i 个是目标 且最多可使得 [j,i] 成为 a[i] 
	{
		while(j<=i and ((i-j)*a[i]-(s[i-1]-s[j-1]))>m)j=j+1;
		printf("CHECK:%lld %lld\n",j,i);
		if(i-j+1>=mid)return true;
	}
	return false;
}*/
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	/*ll l=1,r=n,ans=1;//二分答案
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	} */
	ll j=1;
	for(ll i=1;i<=n;i++)
	{
		while(j<=i and ((i-j)*a[i]-(s[i-1]-s[j-1]))>m)j=j+1;
		//printf("CHECK:%lld %lld %lld\n",j,i,(i-j)*a[i]-(s[i-1]-s[j-1]));
		ans=max(ans,i-j+1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
