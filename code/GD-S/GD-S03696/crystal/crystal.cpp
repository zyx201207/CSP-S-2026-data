#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,len,ans;
int a[N],b[N][2],sum[N],sum1[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if((i-mid)*a[i]-sum[i-1]+sum[mid-1]<=m) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-r);
	}
	printf("%lld\n",ans);
	return 0;
}
