#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=5e5+5; 
ll n,k,a[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>k;
	for(ll i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1);
	ll ans=1;
	ll need=0;
	for(ll r=2,l=1;r<=n;r++){
		ll len=r-l+1;
		need+=(len-1)*(a[r]-a[r-1]);
		while(need>k){
			need-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout <<ans;
	return 0;
}
