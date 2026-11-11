#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
long long a[520000];
long long aq[520000];
long long jul(long long l,long long r){
	long long ans=0;
	ans+=a[r]*(r-l);
	ans-=aq[r-1]-aq[l-1];
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		aq[i]=aq[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=i,r=n;
		while(l+1<r){
			long long mid=(l+r)>>1;
			if(jul(i,mid)<=m){
				l=mid;
			}else{
				r=mid;
			}
		}
		if(jul(i,l)<=m){
			ans=max(ans,l-i+1);
		}
		if(jul(i,r)<=m){
			ans=max(ans,r-i+1);
		}
	}
	printf("%lld",ans);
}
