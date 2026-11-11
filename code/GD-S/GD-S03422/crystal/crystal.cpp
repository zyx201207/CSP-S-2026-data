#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long p=m,sum=1,ans=0;
	for(long long i=n;i>=1;i--){
		for(long long j=i-1;j>=1;j--){
			p-=(a[i]-a[j]);
			if(p<0) break;
			else sum++;
		}
		p=m;
		ans=max(sum,ans);
		sum=1;
	}
	printf("%lld",ans);
	return 0;
}
