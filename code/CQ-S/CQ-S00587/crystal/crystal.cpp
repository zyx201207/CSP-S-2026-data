#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+5;
LL n,m,ans;
LL a[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	LL l=1,r=1;
	__int128 sum=0;
	while(l<=r&&r<=n){
		if(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		else{
			ans=max(ans,r-l+1);
			r++;
			sum=sum+(r-l)*(a[r]-a[r-1]);
		}
		if(l>=r) r=l+1;
	}
	printf("%lld",ans);
	return 0;
}
