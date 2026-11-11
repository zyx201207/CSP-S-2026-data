#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[5000005];
long long sum[5000005];
long long s(long long now){
	long long l=1;
	long long r=now-1;
	long long mid=0;
	long long cnt=0;
	while(l<=r){
		mid=(l+r)/2;
		if((now-mid)*a[now]-(sum[now-1]-sum[mid-1])<=m){
			cnt=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		ans=max(ans,i-s(i)+1);
	}
	cout<<ans;
	return 0;
}
