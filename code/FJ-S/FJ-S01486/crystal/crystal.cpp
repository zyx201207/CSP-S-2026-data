#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[5000005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,now=0;
	for(int r=1;r<=n;r++){
		now+=(r-l)*(a[r]-a[r-1]);
		while(now>m)
		now-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
