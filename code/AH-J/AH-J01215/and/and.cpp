#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll maxn=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
				maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
