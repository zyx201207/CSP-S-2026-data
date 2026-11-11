#include<bits/stdc++.h>
using namespace std;

#define N 10000005
long long a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m,i;
	scanf("%lld %lld",&n,&m);
	
	for(i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	
	sort(a,a+n);
	
	long long ans=a[n-1];
	for(i=n-2;i>=n-m;--i){
		ans=ans&a[i];
	}
	
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
