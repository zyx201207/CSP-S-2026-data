#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m,mx,a[500005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n,cmp);
	for(long long i=0;i<n-1;i++){
		long long ans=1,m1=m;
		for(long long j=i+1;j<n;j++){
			if(m1<(a[i]-a[j])){
				break;
			}
			m1-=(a[i]-a[j]);
			ans+=1;
		}
		mx=max(ans,mx);
	}
	printf("%lld",mx);
	return 0;
}
