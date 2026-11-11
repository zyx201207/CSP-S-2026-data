#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500500],b[500500],c[500500];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i-1,r=n+1;
		while(l+1!=r){
			int mid=(l+r)/2;
			if(c[mid]-c[i]-(i-1)*(b[mid]-b[i])<=m){
				l=mid;
			}else{
				r=mid;
			}
		}
		ans=max(ans,l-i+1);
	}
	printf("%lld",ans);
	return 0;
}

