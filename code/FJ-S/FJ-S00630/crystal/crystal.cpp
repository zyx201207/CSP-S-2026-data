#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500005],sum[500005];
int check(long long x){
	for(int i=x;i<=n;i++){
		if(sum[i]-sum[i-x]+m>=a[i]*x){
			return 1;
		}
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l,r,mid;
	l=1,r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
