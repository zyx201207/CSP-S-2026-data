#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans=0,n,m;
	scanf("%lld %lld",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf(" %lld",&a[i]);
	}
	while(n>m){
		n=n-1;
		for(int i=0;i<n;i++){
			//a[i]=a[i]&a[i+1];
			//printf("%lld \n&&",a[i]);
			a[i]=a[i]&a[i+1];
			ans=max(ans,a[i]);
		}
	}printf("%lld",ans);
	return 0;
}
