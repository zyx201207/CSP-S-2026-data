#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sub[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1ll;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1ll,a+1ll+n);
	sub[1ll]=a[1ll];
	ans=1ll;
	for(long long k=2ll;k<=n;k++){
		sub[k]=sub[k-1ll]+a[k];
		for(long long i=a[k-1ll];i<=a[k];i++){
			for(long long j=k;j>=1ll;j--){
				if((i*(k-j))-(sub[k]-sub[j-1ll])<=m){
					ans=max(ans,k-j);
				}
				else break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
