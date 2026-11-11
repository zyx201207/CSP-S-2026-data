#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,t,n,d,x[2000005],l[2000005],r[2000005],cnt,i,j,k,X,Y,Z,ans;
int main(void) {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) {
		scanf("%lld%lld",&n,&d);
		for(i=1,cnt=0;i<=n;++i) {
			scanf("%lld",&x[i]);
			if(i>3) {
				X=x[i]-x[i-1],Y=x[i-1]-x[i-2],Z=x[i-2]-x[i-3];
				if(X+Y<=d&&Y+Z<=d&&X+Y+Z>d) l[++cnt]=i-3,r[cnt]=i;
			}
		}
		for(i=1,ans=0,r[cnt+1]=1e9;i<=cnt;++i) {
			for(j=l[i]-1;j>0&&j>l[i-1]&&x[j+1]-x[j]<=d;--j);
			for(k=r[i]+1;k<=n&&k<r[i+1]&&x[k]-x[k-1]<=d;++k);
			ans+=(l[i]-j)*(k-r[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
