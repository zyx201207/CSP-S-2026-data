#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans,c,d;
long long ss(long long k){
	long long l=0,r=k,s=0;
	while(l<=r){
		int mid=(l+r)/2;
		d=mid;
		if(a[k]*(k-mid)-(sum[c]-sum[d])>m){
			l=mid+1;
		}else{
			r=mid-1;
			s=k-mid;
		}
	}
	return s;
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
	for(int i=1;i<=n;i++){
		c=i;
		ans=max(ans,ss(i));
	}
	cout<<ans;
	return 0;
}
