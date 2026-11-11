#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],ans=0,sum[500005];
bool check(long long j,long long i){
	long long w=(j-i)*a[j]-(sum[j-1]-sum[i-1]);
	return w>m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long l=1,r=n-i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(mid+i,i)){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(l>ans) ans=l;
	}
	cout<<ans;
	return 0;
}
