#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss,a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ss=1,sum[1]=a[1];
	for(i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(sum[i-1]+m>=a[i]*(i-1)){
			ss=max(ss,i);
			continue;
		}
		if(a[i-1]+m<a[i])continue;
		l=1,r=i-1;
		while(l+1<r){
			mm=(l+r)/2;
			if((sum[i-1]-sum[mm-1])+m>=a[i]*(i-mm))r=mm;
			else l=mm;
		}
		ss=max(ss,i-r+1);
	}
	printf("%lld",ss);
	return 0;
}
