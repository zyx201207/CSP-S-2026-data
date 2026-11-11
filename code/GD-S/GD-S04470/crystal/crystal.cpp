#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	int ans=1,sum=0,j=1;
	for(int i=2;i<=n;i++){
		scanf("%lld",a+i); 
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		while(sum+(i-j)*(a[i]-a[i-1])>m&&j<i){
			sum-=(a[i-1]-a[j]);
			j++;
		}
		sum+=(i-j)*(a[i]-a[i-1]);
		ans=max(i-j+1,ans);
	}
	printf("%lld\n",ans);
	return 0;
} 
