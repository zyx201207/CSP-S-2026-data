#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int z=1,ans=1;
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=(i-z)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=(a[i]-a[z]);
			z++;
		}
		ans=max(ans,i-z+1);
	}
	printf("%d\n",ans);
	return 0;
}
