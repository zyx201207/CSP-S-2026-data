#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],sum=1,mc,sumc=0,w=1e13;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	mc=m;
	for(long long i=1;i<n;i++){
		if(a[i]-a[i-1]<=m){
			w=min(w,i);
			m-=(a[i]-a[i-1]);
			sum++;
		}else{
			if(i==w+1){
				w++;
			}
			sumc=max(sum,sumc);
			sum=1;
			m=mc;
			i=w+1;
		}
	}
	printf("%lld",sumc);
}
