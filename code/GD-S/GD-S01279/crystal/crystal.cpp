#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int j=1;
	long long sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
