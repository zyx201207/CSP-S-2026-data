#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N],ans;
ll read();
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n = read(),m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	sort(a+1,a+n+1);
	ll l = 1,tot = 0;
	for(ll r=1;r<=n;r++)
	{
		tot += (r - l) * (a[r] - a[r-1]);
		while(tot > m) tot -= (a[r] - a[l]),l ++ ;
		ans = max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}

ll read()
{
	ll s = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s*f;
}
