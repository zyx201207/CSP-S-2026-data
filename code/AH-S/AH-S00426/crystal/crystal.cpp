#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL N=5e5+10;
LL n,m,sum2[N],maxn,a[N],sum[N],num,d[N];
bool ok=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	d[2]=a[2]-a[1];sum[2]=d[2];sum2[2]=sum[2];
	for(LL i=3;i<=n;++i){
		d[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+d[i];
		sum2[i]=sum2[i-1]+sum[i];
		if(d[i]!=d[i-1])	ok=0;
	}
	if(n*n<=1e8){
		for(LL i=1;i<=n;++i){
			LL sum=0;
			for(LL j=i-1;j>=1;--j){
				sum+=a[i]-a[j];
				if(sum>m){
					maxn=max(maxn,i-j);
					break;
				}
			}
		}
		printf("%lld",maxn);
	}
	else if(ok){
		LL l=1;
		for(LL r=1;r<=n;++r){
			while(l<r&&(a[r]-a[l]+a[r]-a[r-1])*(r-l)/2>m)	++l;
			maxn=max(maxn,r-l+1);
		}
		printf("%lld",maxn);
	}
	else{
		LL l=1;
		//for(LL i=1;i<=n;++i)	cout<<sum[i]<<' ';
		//puts("");
		//for(LL i=1;i<=n;++i)	cout<<sum2[i]<<' ';
		for(LL r=1;r<=n;++r){
			while(l<r&&(sum[r]*(r-l)-(sum2[r-1]-sum2[l-1]))>m)	++l;
			maxn=max(maxn,r-l+1);
		}
		printf("%lld",maxn);
		//sum[r]-sum[l]+sum[r]-sum[l+1]+...+sum[r]-sum[r-1]
	}
	return 0;
}
