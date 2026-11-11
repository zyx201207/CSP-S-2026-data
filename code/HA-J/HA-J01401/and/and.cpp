#include<bits/stdc++.h>
using namespace std;
long long w[1000000],n,m,a[1000010],sum=4294967295,maxx;
void f(long long i,long long q){
	if(i==m+1){
		maxx=max(maxx,sum);
		return;
	}
	w[i]=sum;
	for(int j=q;j<=n;j++){
		sum=sum&a[j];
		f(i+1,q+1);
		sum=w[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(m==1){
		sum=0;
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		printf("%lld",sum);
		return 0;
	}
	f(1,1);
	printf("%lld",maxx);
	return 0;
} 

