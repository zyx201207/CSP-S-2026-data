#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
int n,m;
long long a[N],dp[N];
bool f(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n,f);
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	printf("%lld",dp[m]);
	return 0;
}
