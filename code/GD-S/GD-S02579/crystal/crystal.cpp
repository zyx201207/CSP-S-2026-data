#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],l,r,ans,tot;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	while(r<n){
		tot+=(r-l+1)*(a[r+1]-a[r]);
		while(tot>m) tot-=a[r+1]-a[l++];
		ans=max(ans,(++r)-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
 
