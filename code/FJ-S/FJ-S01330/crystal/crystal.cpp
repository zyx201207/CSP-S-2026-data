#include<bits/stdc++.h>
using namespace std;
typedef double D;
typedef int LL;
typedef unsigned long long ULL;
const int N=5e5+10;
LL n,m,tot,_;
LL nums[N],nums2[N];
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==1){
		printf("1");
		exit(0);
	}
	for(LL i=1;i<=n;i++){
		scanf("%lld",&nums[i]);
	}
	for(LL i=1;i<=n;i++){
		int cnt=0,ans=0;
		for(int j=1;j<=i;j++){
			nums2[j]=nums[i]-nums[j];
		}
		sort(nums2,nums2+i+1);
		for(int j=1;j<=i;j++){
			cnt+=nums2[j];
			if(cnt>m){
				break;
			}
			ans++;
		}
		tot=max(tot,ans);
	}
	printf("%lld",tot);

	return 0;
}

