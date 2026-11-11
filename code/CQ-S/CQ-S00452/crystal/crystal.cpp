#include<stdio.h>
#include<algorithm>
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<=i&&(ll)(i-j+1)*a[i]-(sum[i]-sum[j-1])>m) j++;
		ans=std::max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
