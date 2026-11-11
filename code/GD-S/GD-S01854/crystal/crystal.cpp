#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long n,m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long res=0,l=1;
	for(long long i=1;i<=n;i++){
		if(a[i]==a[i+1])continue;
		while(((i-l+1)*a[i])-(sum[i]-sum[l-1])>m){
			l++;
		}
		res=max(res,i-l+1);
	}
	printf("%lld",res);
	return 0;
}
