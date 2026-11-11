#include<bits/stdc++.h>
#define N 500005 
#define M
#define mod
#define MAXX 1000000000000000000
#define MINN -1000000000000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m; 
ll a[N]; 
ll ans=1; 
ll pre[N]; 

ll check(ll j,ll i)
{
	ll sum=a[i]*(i-j+1)-(pre[i]-pre[j-1]); 
	if(sum<=m)
	{
		return 1; 
	}
	return 0; 
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("1.out","w",stdout);

	cin>>n>>m; 
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1); 
	for(ll i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i]; 
	}
	for(ll i=2;i<=n;i++)
	{
		ll l=1,r=i-1; 
		ll cnt=1; 
		while(l<=r)
		{
			ll mid=l+r>>1; 
			if(check(mid,i))
			{
				cnt=i-mid+1; 
				r=mid-1; 
			}
			else
			{
				l=mid+1; 
			}
		}
		ans=max(ans,cnt); 
	}
	cout<<ans<<"\n"; 
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/


