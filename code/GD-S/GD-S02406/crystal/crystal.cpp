#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=500005;
LL a[maxn],s[maxn];
LL n,m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(LL i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	LL l,r,mid,cst;
	for(LL i=1;i<=n;i++){
		l=1,r=i;
		while(l<=r){
			mid=(l+r)>>1;
			cst=(i-mid+1)*a[i]-(s[i]-s[mid-1]);
			if(m>=cst){
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
