#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int ans;
int a[N];
int sum[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i-1];
		
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i,j=i;
		while(l<=r){
			int mid=(l+r)/2;
			//printf("%d %d %d\n",i,mid,(a[i]*(i-mid)-sum[i-1]+sum[mid]));
			if((a[i]*(i-mid)-sum[i]+sum[mid])>m){
				l=mid+1;
			}
			else {
				r=mid-1;
				j=mid;
			}
		}
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
