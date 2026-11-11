#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int n,m,a[MAXN],L,R,sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n),L=1,ans=1;
	for(int i=2;i<=n;i++){
		sum+=(i-L)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[L++];
		ans=max(ans,i-L+1);
	}
	printf("%lld",ans);
	return 0;
} 
