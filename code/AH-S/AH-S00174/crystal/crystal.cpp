#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500005];
ll ss[500005];
/*
6 7
1 3 5 6 8 9 
  

int search(ll k){
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=l+r>>1;
		if(k<=a[mid]){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
} */
bool f1=1,f2=1;
ll mx,mn=0x3f3f3f3f;
int main(){
	freopen("crystal4.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		if(a[i]!=i)f1=0;
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])f2=0;
		}
	}
	
	if(f1){
		ll l=1,r=n,ans=1;
		while(l<=r){
			ll mid=l+r>>1;
			if(mid*(mid-1)<=m){
				ans=mid;
				l=mid+1;
			}else r=mid-1;
		}
		cout<<ans*2-1;
		return 0;
	}
	if(f2){
		ll gc=a[2]-a[1];
		ll l=1,r=n,ans=1;
		while(l<=r){
			ll mid=l+r>>1;
			if(gc*mid*(mid-1)<=m){
				ans=mid;
				l=mid+1;
			}else r=mid-1;
		}
		cout<<ans*2-1;
		return 0;
	}
	
	sort(a+1,a+n+1);
	ll idx1=1,idx2=1;
	for(int i=1;i<=n;i++){
		ss[i]=ss[i-1]+a[i];
	}
	ll ans=0;
	while(1){
		if(idx2>n){
			break;
		}
		while(idx2<=n&&sum<=m){
			ans=max(ans,idx2-idx1+1);
			sum+=(a[idx2]-a[idx2-1])*(idx2-idx1+1);
			idx2++;
		}
		while(idx1<=idx2&&sum>m){
			sum-=(a[idx1+1]-a[idx1])*(idx2-idx1+1);
			idx1++;
		}
		if(idx2>n)break;
	}
	cout<<ans;
	return 0;
}
