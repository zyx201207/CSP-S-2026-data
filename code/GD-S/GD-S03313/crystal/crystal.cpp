#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N];
bool check(int mid){
	for(int i=mid;i<=n;i++){
		if(a[i]*mid-(sum[i]-sum[i-mid])<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m); 
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int L=1,R=n;
	while(L<R){
		int mid=(L+R+1)/2;
		if(check(mid)){
			L=mid;
		}else{
			R=mid-1;
		}
	}
	printf("%lld",L);
	return 0;
} 
