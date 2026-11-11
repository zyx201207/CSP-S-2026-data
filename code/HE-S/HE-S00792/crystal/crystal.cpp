#include <bits/stdc++.h>
using namespace std;
long long n,m,a[600100],sum[600100];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long l=1,r=1,ans=0;
	for(;r<=n;r++){
		sum[r]=sum[r-1]+(a[r]-a[r-1])*(r-l);
		while(sum[r]>m&&l<r){
			sum[r]-=(a[r]-a[l]);
			++l;
		}
		if(ans<r-l+1){
			ans=r-l+1;
		}
	}
	cout<<ans;
	return 0;
}
