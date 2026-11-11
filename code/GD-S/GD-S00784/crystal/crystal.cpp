#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
long long n,m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(m>N){
		for(long long i=n/1.58;i>=1;i--){
			long long total=0,num=0;
			for(long long j=1;j<=n;j++){
				if(a[i]-a[j]>=0){
					total+=a[i]-a[j];
					num++;
				}
			} 
			if(total<=m){
				printf("%ld",num);
				return 0;
			}
		} 
	}else{
		for(long long i=n;i>=1;i--){
			long long total=0,num=0;
			for(long long j=1;j<=n;j++){
				if(a[i]-a[j]>=0){
					total+=a[i]-a[j];
					num++;
				}
			} 
			if(total<=m){
				printf("%ld",num);
				return 0;
			}
		} 
	}
	
	return 0;
}
