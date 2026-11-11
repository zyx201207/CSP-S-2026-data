#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000];
ll b[1000000];
ll n,m;
bool pan(ll s){
	for(ll i=s;i<=n;i++){
        ll sum=b[i]-b[i-s];
        ll pay=s*a[i]-sum;
        if(pay<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)b[i+1]=b[i]+a[i];
	ll l=1,r=n,mid=0,sum=0; 
	while(l<=r){  
		mid=(l+r)/2;   
		if(pan(mid)==true){  
			sum=mid;
			l=mid+1; 
		 }
		else r=mid-1;
		  
	 }
	cout<<sum+1;
	    
	 
	return 0;
}
