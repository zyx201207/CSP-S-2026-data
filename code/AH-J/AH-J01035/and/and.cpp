#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=2E5+5;
LL n,m,a[N],ans,maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++){
		scanf("%lld",a+i);
		maxn=max(maxn,a[i]);
	}
	LL x=a[1];
	for(LL i=2;i<=n;i++) x&=a[i];
	if(m==1){
		printf("%lld",maxn);
		return 0;
	}
	if(m==n){
		printf("%lld",x);
		return 0;
	}
	LL l=1;
	for(LL r=m;r<=n;r++){
		if(r-l+1!=m) continue;
		LL tmp=a[l];
		for(LL i=l+1;i<=r;i++) tmp&=a[i];
		if(tmp>ans){
			ans=tmp;
			l++;
		}
	}
	printf("%lld",ans);
	return 0;
}
