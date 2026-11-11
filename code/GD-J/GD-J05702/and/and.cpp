#include<bits/stdc++.h>
using namespace std;
long long n,ma,m,a[2000005],sum;
void oj(int k,int l){
	if(l>=m){
		if(ma<=sum)
			ma=sum;
		return;
	}
	if(n-k+l+1<m)return;
	long long s=sum;
	oj(k+1,l);
	if(sum==0)sum=a[k];
	sum=(sum&a[k]);
	oj(k+1,l+1);
	sum=s;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	oj(1,0);
	printf("%lld",ma);
	return 0;
}
