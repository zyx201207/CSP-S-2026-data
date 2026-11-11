#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N=500009;
ll m,n,a[N],sum[N];

bool check(ll p){
	ll mn=0x3f3f3f3f3f3f3f3f,sm;
	for(int i=n;i-p>=0;i--){
		sm=p*a[i]-(sum[i]-sum[i-p]);
		mn=sm<mn?sm:mn;
	}
	return(mn<=m);
}



int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
	ll l,r,mid;
	l=1;r=n;
	while(l<r){
		//cout<<l<<r<<'/';
		mid=((r-l+1)>>1)+l;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
