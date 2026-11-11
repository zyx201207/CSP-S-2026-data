#include<bits/stdc++.h>
//guan zhu Bzhan KYWYX
using namespace std;
using ll=long long;
using i128=__int128;
const ll N=5e5,M=1e18;
ll n,m,a[N+10],l,r,mid;
inline bool check(ll x){
	ll xh=0,js=LLONG_MAX;
	for(ll i=1;i<=x;i++){
		xh+=a[x]-a[i];
	}
	js=xh;
	for(ll i=0;i+x<n;i++){
		xh-=a[x+i]-a[i];
		xh+=(a[x+i+1]-a[x+i])*(x-1);
		js=min(js,xh);
	}
	if(js<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen(".ky","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(l=1,r=n;l<=r;){
		mid=((l+r)>>1);
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
