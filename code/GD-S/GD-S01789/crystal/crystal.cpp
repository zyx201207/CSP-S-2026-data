#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,ans;
LL a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++) cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(LL i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(LL i=1;i<=n;i++){
		LL l=1,r=i;
		while(l<r){
			LL mid=(l+r)>>1;
			if(m>=(i-mid+1)*a[i]-(sum[i]-sum[mid-1])) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
