#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int a[N],n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	int ans=0,l=1,cost=0;
	for(int i=1;i<=n;i++){
		cost+=(i-l)*(a[i]-a[i-1]);
		while(cost>m)cost-=(a[i]-a[l++]);
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
