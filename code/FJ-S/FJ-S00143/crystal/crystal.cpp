#include<bits/stdc++.h>
using namespace std;
long long m,n,a[10000005],v[10000005],minn,ms=1,x=1;
bool b(long long n){
	for(long long i=3;i<=n;i++){
		if(v[i]!=v[i-1])return 0;
	}
	return 1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		v[i]=a[i]-a[i-1];
	}
	if(b(n)){
		long long d=v[2],sum=0;
		while(1){
			sum=(1+x)*x/2*d;
			if(sum<=m)x=x+1;
			else break;			
		}
		printf("%lld",x);
		return 0;
	}
	else{
		for(long long i=2;i<=n;i++){
			long long mm=m,j=i-1,num=1;
			while(mm>=0&&j>0){
				if(a[i]-a[j]<=mm){
					num++;
					mm-=(a[i]-a[j]);
					j--;
				}
				else break;
			}
			ms=max(ms,num);
		}
		printf("%lld",ms);		
	}
	return 0;
}
