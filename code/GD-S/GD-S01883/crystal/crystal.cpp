#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
long long lrsum(long long l,long long r){ return sum[r]-sum[l-1]; }
bool check(long long mid){
	for(long long i=mid;i<=n;i++){
		if(a[i]*mid-lrsum(i-mid+1,i)<=m)return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	long long l=1,r=n,res=1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid))res=mid,l=mid+1;
		else r=mid-1;
	} 
	cout<<res;
} 
