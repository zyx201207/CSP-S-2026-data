#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans=0;
ll a[N],su[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		su[i]=su[i-1]+a[i]; 
	}
	ll l=1,r=n,mid,ans;
	while(l<=r){
		mid=l+(r-l)/2;
		ll flag=0;
		for(ll i=1;i+mid-1<=n;i++){
			ll j=i+mid-1;
			ll t=mid*a[j]-su[j]+su[i-1];
			if(t<=m){
//				cout<<i<<" "<<j<<endl; 
				flag=1;
				break;
			}
		}
		if(flag){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
