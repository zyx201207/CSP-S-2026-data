#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N];
bool check(ll len){
	ll res=0;
	for(ll i=1;i<=len;i++)
		res+=a[len]-a[i];
	if(res<=m) return 1;
	for(ll i=2;i<=n-len+1;i++){
		ll j=i+len-1;
		res-=a[j-1]-a[i-1];
		res+=(len-1)*(a[j]-a[j-1]);
		if(res<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,r=n,mid,res;
	while(l<r){
		mid=l+r>>1;
		if(check(mid)) l=mid+1,res=mid;
		else r=mid;
	}
	cout<<res;
	return 0;
}

