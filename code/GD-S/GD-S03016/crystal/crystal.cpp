#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long inf=9223372036854775807;
long long n,m,a[500001],ans=-inf;
long long pj,c;
bool cmp(long long x,long long y) {
	return abs(x-(int)pj)<abs(y-(int)pj);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
		pj+=a[i];
	}
	c=abs(a[2]-a[1]);
	if(n<=5000) {
		pj/=n;
		sort(a+1,a+1+n,cmp);
		long long bz,s,ls=m;
		for(long long i=1;i<=n;++i) {
			bz=a[i];
			s=0,m=ls;
			for(long long j=1;j<=n&&m>0;++j) {
				if(a[j]>bz) continue;
				if(m-abs(a[j]-bz)>=0&&a[j]<bz) m-=abs(a[j]-bz),s++;
				else if(a[j]==bz) s++;
			}
			ans=max(ans,s);
		}
		printf("%lld",ans);
	}
	else {
		long long bz=((1+n)/2),lz=0,s=0;
		for(long long i=1;lz<=m;lz+=i,i+=c) s++;
		printf("%lld",s);
	}
	return 0;
} 
