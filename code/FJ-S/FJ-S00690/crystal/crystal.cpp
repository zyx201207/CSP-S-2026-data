#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int* ans;
int a[500001],d[500001],s[500001],ss[500001],cf[500001];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%i%i",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%i",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		d[i]=a[i]-a[i-1]+d[i-1];
	}
	for(int i=n;i>=1;i--){
		s[i]=(s[i+1]+d[i]);
		ss[i]=(ss[i+1]+s[i]);
	}
	cf[n]=ss[2];
	for(int i=n-1;i>=1;i--){
		cf[i]=cf[i+1]-(i)*d[i+1];
	}
	ans=lower_bound(cf+1,cf+n+1,m);
	while(*(ans+1)==*ans){
		ans++;
	}
	printf("%i",ans-cf);
	
	
//	
//	printf("\n");
//	for(int i=1;i<=n;i++){
//		printf("%i %i %i %i \n",d[i],s[i],ss[i],cf[i]);
//	}
	return 0;
}
