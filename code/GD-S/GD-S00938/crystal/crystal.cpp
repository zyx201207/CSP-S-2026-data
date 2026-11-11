#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],sum[500005],m,ans;
bool ck(long long x){
	for(long long i=1;i+x-1<=n;i++){
		long long j=i+x-1;
		if(abs(x*a[j]-sum[j]+sum[i-1])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(ck(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}
