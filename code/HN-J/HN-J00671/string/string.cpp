#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
ll n;
ll a[N];
char c[N];
ll sum[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(ll i=1; i<=n; i++) cin >> a[i] >> c[i];
	ll now=n, now2=0, now3=a[n];
	ll ans=0;
	for(ll i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1; i<=n; i++)
	{
		char k=c[i];
		ll s=min(a[i], sum[n]/2-(a[now]-now3+sum[n]-sum[now]));
		while(s>0)
		{
			if(k!=c[now]) ans+=min(now3, s);
			ll ls=now3;
			now3-=min(now3, s);
			if(now3==0)
			{
				now--;
				now3=a[now];
			}
			s-=min(ls, s);
		}
		if(a[now]-now3+sum[n]-sum[now]==sum[n]/2) break;
	}
	cout << ans;
	return 0;
}
