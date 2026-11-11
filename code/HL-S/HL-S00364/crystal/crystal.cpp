#include <bits/stdc++.h>
using namespace std;
long long b[500005],n,ans,m,a[500005],l,r,o;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		l=i,r=n+1;
		while(l+1<r){
			o=(l+r)/2;
			if(a[i]*(o-i+1)<=b[o]-b[i-1]+m)
				l=o;
			else
				r=o;
		}
		ans=max(ans,l-i+1);
	}
	printf("%lld",ans);
}
