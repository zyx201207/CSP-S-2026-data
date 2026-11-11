#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=a[n-m+1];
	for(ll i=n-m+2;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0; 
}

