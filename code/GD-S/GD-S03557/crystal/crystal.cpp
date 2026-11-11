#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int k=0;
int n;
//columbina & sandrone
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	int j=1; //[i,j)
	int used=0;
	int ans=0;
	for (int i=1;i<=n;i++){
		used-=(j-i)*(a[i-1]-a[i]);
		while(true){
			if (j<=n && used+a[i]-a[j]<=k){
				used+=a[i]-a[j];
				j++;
			}else{
				break;
			}
		}
//		printf("%d %d %d\n",i,j,used);
		ans=max(ans,j-i);
	}
	printf("%lld",ans);
	return 0;
}
