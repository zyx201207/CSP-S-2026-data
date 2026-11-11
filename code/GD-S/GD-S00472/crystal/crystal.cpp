#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=500005;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1ll,sum=0ll,ans=1ll;
	for(int r=2;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m&&l<r)
			sum-=(a[r]-a[l]),l++;
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
} 
