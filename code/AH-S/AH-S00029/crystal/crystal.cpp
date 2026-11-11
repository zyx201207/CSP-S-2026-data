#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans,b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1,j=2;j<=n&&i<=j;j++){
		m-=(j-i)*(a[j]-a[j-1]);
		while(m<0) m+=a[j]-a[i++];
		ans=max(ans,j-i+1);
	}
	printf("%lld",ans);
	return 0;
}
