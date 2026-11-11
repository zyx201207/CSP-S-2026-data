#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,K;
int a[N];
int ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&K);	
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=n,s=0;
	for(int i=n;i;i--){
		if(i<n){
			if(l>i) l=i,s=0;
			else s-=(i-l+1)*(a[i+1]-a[i]);	
		}
		while(l>1 && s+a[i]-a[l-1]<=K){
			l--;
			s+=a[i]-a[l];
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
