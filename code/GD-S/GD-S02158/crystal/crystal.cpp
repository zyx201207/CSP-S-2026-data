#include<bits/stdc++.h>
using namespace std;
const long long N=-1000000000005;
long long n,m,a[500005];
long long maxl(long long a,long long b){
	if(a>=b) return a;
	return b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	unsigned long long maxn=N;
	for(int w=1;w<=n-maxn;w++){
		unsigned long long nl=0;
		for(unsigned long long i=w+1;i<=n;i++){
			if(a[i]==a[i-1]) continue;
			nl+=(a[i]-a[i-1])*(i-w);
			if(nl>m){
				maxn=maxl(maxn,i-w);
				break;
			}
		}	
	}
	printf("%lld",maxn); 
	return 0;
} 
