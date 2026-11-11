#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>
int binary(int l,int r,T cmp){
	while(l<r){
		int mid=l+(r-l)/2;
		cmp(mid)?l=mid+1:r=mid;
	}
	return l;
}
const int N=5e5+50; 
int n,m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int j=binary(i,n+1,[&](int x){
			return (x-i+1)*a[x]-(sum[x]-sum[i-1])<=m;
		})-1;
		ans=max(ans,j-i+1);
	}
	printf("%lld",ans);
	return 0; 
}
