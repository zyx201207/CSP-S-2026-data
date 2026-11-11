#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int n,m,a[N],pre[N],ans=1;
signed main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		while((i-j+1)*a[i]-(pre[i]-pre[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld\n",ans);
	return 0;
}
