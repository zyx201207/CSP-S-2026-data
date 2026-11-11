//祝__wanghc__、__NightDay__、chen_14514、void_ghost、EternalArcana CSP rp++

//11:05 ** 滚木 **背包10pts.
//不太会背包...
//fqoi:?????? 

#include<bits/stdc++.h>
using namespace std;
#define write ios::sync_with_stdio(false);
#define by cin.tie(0);
#define __wanghc__ cout.tie(0);
#define ll long long

const ll N=2e5+10;
ll a[N],dp[N];

int main()
{
	write by __wanghc__
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	memset(dp,0,sizeof(dp));
	dp[0]=-1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=m;j>=1;j--)
		{
			ll xx=(dp[j-1])&(a[i]);
			dp[j]=max(dp[j],xx);
		}	
	}
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<' ';
	cout<<endl;
	cout<<dp[m];
	return 0;
}

//Trick or treat!
