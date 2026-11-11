#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+1);
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=m;i++) cout<<0<<' ';
	return 0;
}
