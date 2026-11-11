#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500050];
ll ans;
ll ma=0;
//Oct31==Dec25? 
bool check1(ll p,ll k) {
	if(p==1){
		if(a[p]<=m) return 1;
		else return 0;
	}
	double long h=a[p]-a[1]+a[p]-a[p-1];
//	cout<<h<<endl;
	double long c=(p-1)*1.0/2;
//	if(h==7) cout<<h*1.0*c;
	if(h*1.0*c<=m) return 1;
	else return 0;
}
bool check2(ll k){
	ll sum=0;
	for(ll i=1;i<k;i++){
		sum+=a[k]-a[i];
	}
	if(sum<=m) return 1;
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		pre[i]=pre[i-1]+a[i];
//	}
	bool f=0;
	ll k=a[2]-a[1];
	for(int i=3; i<=n; i++) {
		if(a[i]-a[i-1]!=k) f=1;
	}
	if(f==0) {
		for(int i=1;i<=n;i++){
			ans=i;
			if(check1(i,k)==0){
				ans=i-1;
			//	cout<<i<<" ";
				break;
			}
		}
	cout<<ans;
		return 0;
	}
	else{
		ll l=1,r=n;
		while(l<=r){
			ll mid=l+(r-l)/2;
			if(check2(mid)){
				l=mid+1;
			//	ans=mid;
			}
			else {
				r=mid-1;
				ans=r;
			}
		}
			cout<<ans;
		
	}
	return 0;
}
