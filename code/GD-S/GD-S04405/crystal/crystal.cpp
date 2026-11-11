#include<bits/stdc++.h>
using namespace std;
long long m;
int n;
long long a[500005];
long long sum[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long s=(i-1)*abs(a[i]-a[i-1]);
		sum[i]=sum[i-1]+s;
	}
	sum[n+1]=m+1;
	for(int i=n;i>=2;i--){
		if(sum[i]<=m&&sum[i+1]>m){
			printf("%d",i);
			return 0;
		}
	}
	printf("0");
	return 0;
} 
