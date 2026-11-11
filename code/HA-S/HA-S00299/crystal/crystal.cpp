#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e5+10;
ll a[N],m,sum[N];
int n;
bool check(ll x){
	for(int tar=x;tar<=n;tar++){
		ull tot=x*a[tar]-(sum[tar]-sum[tar-x]);
		if(tot<=m)	return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	ll l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
