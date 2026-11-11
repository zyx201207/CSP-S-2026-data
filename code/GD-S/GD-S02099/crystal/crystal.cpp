#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iif if(k==315275)
const ll N=5e5+10;
ll n,m,a[N],b[N];
bool cmp(ll qp,ll pq){
	return qp<pq;
}
bool check(ll k){
	ll cnt=0;
	for(ll i=1;i<k;i++){
		cnt+=i*b[i];
	}
	if(cnt<=m) return 1;
	for(ll i=k;i<n;i++){
		cnt-=(a[i]-a[i-k+1]);
		cnt+=(k-1)*b[i];
		if(cnt<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		b[i]=a[i+1]-a[i];
	}
	ll l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
