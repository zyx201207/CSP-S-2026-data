#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1,j=1,s=0;i<=n;i++){
		s+=a[i];
		while(s+m<(i-j+1)*a[i]) s-=a[j],j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
