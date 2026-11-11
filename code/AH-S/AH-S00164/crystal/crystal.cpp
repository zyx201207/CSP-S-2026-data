#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll MAXN=5e5+5;
ll n, m;
ll a[MAXN], b[MAXN];
bool cnt(ll a,ll b)
{
	return a+b;
}
int main(){
	
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >>n>>m;
	for (ll i=1;i<=n;i++) cin >>a[i];
	sort (a+1,a+1+n,cnt);
	for (ll i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	for (ll i=1;i<=n;i++) 
	{
		ll x,cnt,ans;
		x=cnt=0;
		if (x<=ans)
		{
			ans+=x;
			
		}
		cout <<ans;
	}
	return 0; 
	
}
