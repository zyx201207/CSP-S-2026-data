#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	for(int i=1;i<=n;i++){
		int l=i,r=n,mx;
		while(l<=r){
			int mid=(l+r)/2;
			if(s[mid]-s[i-1]-(a[mid]-a[i-1])*(i-1)<=m)mx=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,mx-i+1);
	}
	printf("%lld",ans);
	return 0;
} 
