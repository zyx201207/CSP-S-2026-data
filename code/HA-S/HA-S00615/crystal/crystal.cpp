#include <bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],n,m,l,r,mid,cnt;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	l=1ll,r=n;
	while(l<r){
		mid=(l+r+1ll)/2ll,cnt=0x3f3f3f3f3f3f3f3f;
		//cout<<cnt;
		for(int i=mid;i<=n;i++){
			cnt=min(cnt,mid*a[i]-(sum[i]-sum[i-mid]));
		}
		if(cnt<=m){
			l=mid;
		}else {
			r=mid-1;
		}
	}
	cout<<l;
	//cout<<111;
	return 0;
}
