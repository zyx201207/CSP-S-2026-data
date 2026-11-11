#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,l,r,mid,ans,Max;
ll a[500005];
ll h[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		h[i]=h[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		Max=l=1;r=i;
		while(l<=r){
			mid=(l+r)/2;
			if(h[i]-h[mid-1]+m>=(i-mid+1)*a[i]){
				Max=i-mid+1;
				r=mid-1;
			}else if(h[i]-h[mid-1]+m<(i-mid+1)*a[i]){
				l=mid+1;
			}
		}
		ans=max(Max,ans);
	}
	printf("%lld",ans);
	return 0;
}
