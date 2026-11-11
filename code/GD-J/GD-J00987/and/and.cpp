#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long n,m;
long long a[N];
long long maxi=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=0;i<n-1;i++){
		for(long long j=1+i;j<n;j++){
			if(a[i]<a[j]){
				long long k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	printf("%lld",a[m-1]);
	return 0;
}
