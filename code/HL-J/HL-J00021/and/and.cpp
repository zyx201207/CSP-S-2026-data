#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m,a[2000005];
	cin>>n>>m;
	for(ll i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<ll>());
	ll b=a[0];
	for(ll i=1;i<m;i++) b&=a[i];
	cout<<b;
	return 0;
}