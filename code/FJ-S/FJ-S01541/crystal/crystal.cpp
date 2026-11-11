#include<bits/stdc++.h>
#define int long long
const int N=1e6+5;
using namespace std;
int a[N],sum[N];
int ans;
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=1;i--){
		int l=1,r=i,idx=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int t=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
			if(t<=m){
				r=mid-1;
				idx=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-idx+1);
	}
	printf("%lld",ans);
	return 0;
}

