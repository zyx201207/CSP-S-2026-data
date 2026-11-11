#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf ("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf ("%lld",&a[i]);
	sort (a+1,a+n+1);a[0]=-1e18;
	int l=0,cnt=0;
	for (int r=1;r<=n;r++){
		if (r>1) cnt+=(r-1-l)*(a[r]-a[r-1]);
		while (cnt>m&&l+1<=r)
			cnt-=(a[r]-a[++l]);
		ans=max(ans,r-l);
	} 
	printf ("%lld",ans);
	return 0;
}
