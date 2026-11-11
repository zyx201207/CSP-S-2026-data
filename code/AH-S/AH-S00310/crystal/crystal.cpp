#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long LL;
LL n,m,a[N],sum[N],maxn=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++){
		 scanf("%lld",&a[i]);	 
	}
	sort(a+1,a+n+1);
	if(n<=5e3){
		for(LL i=1;i<=n;i++){
			LL l=i,cnt=1,tot=0;
			while(l>=1&&abs(a[i]-a[l])+tot<=m){cnt++;l--;tot+=abs(a[i]-a[l]);}
			maxn=max(maxn,cnt);
		}
		printf("%lld",maxn);
		return 0;
	}
	/*
	for(LL i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i]-a[1];
		LL p=lower_bound(sum+1,sum+1+i,sum[i]-m)-sum;
		maxn=max(maxn,i-p+1);
	}*/
	LL l=1;
	for(LL r=1;r<=n;r++){
		sum[r]=sum[r-1]+(a[r]-a[r-1])*(r-l);
		while(l<r&&sum[r]>m){
			sum[r]-=a[r]-a[l];l++;
		}
		maxn=max(maxn,r-l+1);
	}
	printf("%lld",maxn);
	return 0;
}
