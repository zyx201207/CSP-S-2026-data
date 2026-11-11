#include<bits/stdc++.h>
#define ll long long
using namespace std; 


ll n, m, a[200005], maxn=LONG_LONG_MIN; 

int main() {
	freopen("and.in", "r", stdin); 
	freopen("and.out", "w", stdout); 
	cin>>n>>m; 
	for(ll i=1; i<=n; i++) {
		cin>>a[i]; 
	} for(ll i=1; i<=n; i++) {
		ll andsum=a[i]; 
		for(ll k=0; k<m; k++) {
			for(ll j=i+k; j<=n; j++) {
				andsum&=a[j]; 
			}
		} maxn=max(andsum, maxn); 
	} cout<<maxn; 
	return 0; 
}
