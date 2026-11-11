#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m,a[N],sum[N],l,r,mid,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		l=1,r=i;
		while(l<r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
