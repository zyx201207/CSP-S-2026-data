#include<bits/stdc++.h>
using namespace std;//obviously
#define int long long//yellow
int n,m;
const int N=5e5+100;
int a[N];
int sum[N];


bool check(int k){
	for(int i=k;i<=n;i++){
		if( (sum[i]-sum[i-k+1]-(i-k)*(a[i]-a[i-k+1])) <m)return 1;
	}
	return 0;
}


signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*i;
	}
	int l=0,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
		//cout<<mid<<' '<<l<<' '<<r<<'\n';
	}
	cout<<l;
	return 0;
}
