#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	long long m;
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1,j=1;j<=n;j++){
		while(i<j&&a[j]*(j-i)-(sum[j-1]-sum[i-1])>m){
			++i;
		}
		ans=max(ans,j-i+1);
	}
	printf("%d",ans);
	return 0;
}
