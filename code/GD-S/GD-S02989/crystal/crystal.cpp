#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const ll maxn=5e5+5;
ll a[maxn], c[maxn];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	ll ans=0;
	ll l=0, r=0, cmp=0;
	while(r<=n){
		r++;
		cmp+=(a[r]-a[r-1])*(r-l-1);
		while(cmp>m){
			cmp-=a[r]-a[l+1];
			l++;
		}
		ans=max(ans, r-l);
	}
	cout << ans;
	return 0;
 } 
