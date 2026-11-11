//crystal GYSB 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],s[500010],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1,j=0;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while(a[i]*(i-j)-(s[i]-s[j])>m) j++;
		ans=max(ans,i-j); 
	}
	printf("%lld",ans);
	return 0;
}
