#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans,e=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if((a[n]==1)||(a[n]==256)||(a[n]==512)||(a[n]==1024)||(a[n]==2)||(a[n]==8)||(a[n]==16)||(a[n]==32)||(a[n]==64)||(a[n]==256)||(a[n]==512)||(a[n]==1024)||(a[n]==2048)||(a[n]==4096)||(a[n]==8192)||(a[n]==16384)||(a[n]==32768)||(a[n]==65536)||(a[n]==131072)||(a[n]==262144)||(a[n]==524288)||(a[n]==1048576)||(a[n]==2097152)||(a[n]==4194304)||(a[n]==8388608)||(a[n]==16777216)||(a[n]==33554432)||(a[n]==134217728)||(a[n]==268435456)||(a[n]==536870912)||(a[n]==1073741824)){
		ans=a[n-1];
		for(int i=n-2;i>=n-m;i--){
			ans&=a[i];
		}
	}
	else {
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
