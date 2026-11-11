#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],sum[N],m;int n;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int l=1,r=2;r<=n;r++) {
		for(;l<r&&1ll*(r-l+1)*a[r]-(sum[r]-sum[l-1])>m;l++);
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);return 0;
}
