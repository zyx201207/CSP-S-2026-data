#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,now=0;
	for(int i=2;i<=n;i++){
		now+=(i-l)*(a[i]-a[i-1]);
		while(now>m){
			now-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
