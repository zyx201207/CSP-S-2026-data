#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 505000LL;
const ll inf = 1152921504606846976;
ll n, m,i,j,k,a[N],f[N],p[N],pos;
bool check(ll x)
{
	ll tot=inf, lll, rr;
	for (ll i=1LL; i+x-1LL<=n; i++)
	{
		lll = i;
		rr = i+x-1LL;
		tot = min(tot, (x * a[rr]) -( p[rr] - p[lll-1LL]));
	}
	if (tot <= m) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (i=1; i<=n ;i++)
		cin >> a[i];
	sort(a+1LL, a+1LL+n); 
	for (i=1; i<=n; i++)
	{
		p[i] = p[i-1LL] + a[i];
	}
	ll l = 1, r = n, mid, ans;
	while (l <= r)
	{
		mid = l + (r-l)/2LL;
		if (check(mid) == true)
		{
			l = mid+1LL;
			ans = mid; 
		}else{
			r = mid-1LL;
		}
	}
	cout << ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
