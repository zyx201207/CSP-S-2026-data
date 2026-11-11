#include<bits/stdc++.h>
using namespace std;
long long  a[500005];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(long long i=0;i<n;i++){
	scanf("%lld",&a[i]);
	}
	sort(a,a+n);
    for(long long  i=1;i<n;i++){
	long long num=0,ians=0;
		for(long long  j=i;j>=0;j--){
			num+=a[i]-a[j];
			if(num>m) break;
			if(num<=m) ians++;
			}
			ans=max(ans,ians);
			}
	printf("%lld",ans);
	return 0;
	}
