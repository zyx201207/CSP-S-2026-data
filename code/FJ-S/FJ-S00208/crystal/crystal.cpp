#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,m;
ll a[501010];
ll f[505050];
bool check(ll x){
	ll sum=0;
	ll bs=4e18;
	ll bl=0;
	ll as=0;
	for(int i=1;i<=n-x+1;i++){
		sum=a[i+x-1]*(x-1)-f[i+x-2]+f[i-1];
		if(sum<bs){
			bl=i;
			bs=sum;
		}
	}
	if(bs<=m){
		return 1;
	}else{
		return 0;
	}
}
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
		f[i]=f[i-1]+a[i];
	}
	ll l=1,r=n;
	while(1){
		if(l>=r){
			cout<<l;
			break;
		}
		ll mid=(l+r+1)/2;
		if(check(mid)==1){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return 0;
}

