#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll a[500005];
ll b[500005];
ll n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	ll ans=1;
	for(ll i=n;i>=1;i--){
		ll l=1,r=i;
		ll mid;
		while (l<=r){
			mid=(l+r+1)/2;
			if (a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m){
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		if (a[i]*(i-l+1)-(b[i]-b[l-1])<=m){
			ans=max(i-l+1,ans);
		}
	}
	cout<<ans;
	return 0;
}/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
//ll arr=a[i]*i-b[i];
