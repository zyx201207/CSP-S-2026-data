#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2,bj=0;
		for(int i=mid;i<=n;i++){
			if(a[i]*(mid-1)-(s[i-1]-s[i-mid])<=m){
				bj=1;
				break;
			}
		}
		if(bj==1){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
